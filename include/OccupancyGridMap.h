#ifndef OCCUPANCY_GRID_MAP_H
#define OCCUPANCY_GRID_MAP_H
#include <vector>

class OccupancyGridMap {
private:
    std::vector<std::vector<char>> grid;
    int robotX;
    int robotY;
    int cellSizeCm;

    void expandMap();

public:
    OccupancyGridMap(int cellSizeCm);

    void printMap();
    void moveRobot(int dx, int dy);
    void markObstacle(int dx, int dy);
};

#endif
