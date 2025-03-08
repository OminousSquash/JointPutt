#ifndef BALL_H
#define BALL_H

class Ball {
public:
    float x;
    float y;
    float xVel;
    float yVel;
    bool deactivated;
public:
    Ball(float x, float y) : x(x), y(y), xVel(0), yVel(0), deactivated(false) {}

    Ball() : x(120), y(200), xVel(0), yVel(0), deactivated(false) {}
};

#endif