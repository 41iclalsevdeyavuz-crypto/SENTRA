#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

class DistanceSensor {
private:
    int forwardDistance;
    int leftDistance;
    int rightDistance;

public:
    DistanceSensor();

    void setDistances(int forward, int left, int right);

    int getForwardDistance();
    int getLeftDistance();
    int getRightDistance();
};

#endif
