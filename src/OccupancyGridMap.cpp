#include <iostream>
#include "OccupancyGridMap.h"

using namespace std;

// '?' = unknown
// '.' = explored free space
// 'X' = obstacle

// The map starts small and expands as the robot explores.
// This way, we do not need to know the room size in advance.

OccupancyGridMap::OccupancyGridMap(int cellSizeCm) {
    const int INITIAL_MAP_SIZE = 5;

    this->cellSizeCm = cellSizeCm;

    grid = vector<vector<char>>(
        INITIAL_MAP_SIZE,
        vector<char>(INITIAL_MAP_SIZE, '?')
    );

    robotX = INITIAL_MAP_SIZE / 2;
    robotY = INITIAL_MAP_SIZE / 2;
}

void OccupancyGridMap::expandMap() {
    const int OFFSET = 1;

    vector<vector<char>> newGrid(
        grid.size() + 2,
        vector<char>(grid[0].size() + 2, '?')
    );

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            newGrid[row + OFFSET][col + OFFSET] = grid[row][col];
        }
    }

    grid = newGrid;

    robotX += OFFSET;
    robotY += OFFSET;
}

void OccupancyGridMap::printMap() {
    cout << "\nCurrent Occupancy Grid Map:\n";

    for (int row = 0; row < grid.size(); row++) {
        for (int col = 0; col < grid[row].size(); col++) {
            if (row == robotY && col == robotX) {
                cout << "R ";
            } else {
                cout << grid[row][col] << " ";
            }
        }
        cout << endl;
    }

    cout << endl;
}

void OccupancyGridMap::moveRobot(int dx, int dy) {
    grid[robotY][robotX] = '.';

    int newX = robotX + dx;
    int newY = robotY + dy;

    if (newX < 0 || newX >= grid[0].size() ||
        newY < 0 || newY >= grid.size()) {

        expandMap();

        newX = robotX + dx;
        newY = robotY + dy;
    }

    robotX = newX;
    robotY = newY;
}

void OccupancyGridMap::markObstacle(int dx, int dy) {
    int obstacleX = robotX + dx;
    int obstacleY = robotY + dy;

    if (obstacleX < 0 || obstacleX >= grid[0].size() ||
        obstacleY < 0 || obstacleY >= grid.size()) {

        expandMap();

        obstacleX = robotX + dx;
        obstacleY = robotY + dy;
    }

    grid[obstacleY][obstacleX] = 'X';
}
