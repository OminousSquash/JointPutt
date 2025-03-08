#ifndef BALL_H
#define BALL_H

class Ball {
public:
    float x;
    float y;
    float xVel;
    float yVel;
public:
//    Ball(int x, int y) : x(x), y(y), xVel(0), yVel(0){}
//
//    Ball(int x, int y, int xVel, int yVel) : x(x), y(y), xVel(xVel), yVel(yVel){}

    Ball() : x(120), y(200), xVel(0), yVel(0) {}
};

#endif