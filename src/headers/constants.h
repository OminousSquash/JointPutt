#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace CONSTANTS {
    const int BALL_RADIUS = 20;
    const int HOLE_RADIUS = 20;
    const int WINDOW_WIDTH = 900;
    const int WINDOW_HEIGHT = 600;
    const float FRICTION = 0.99;
    const int BORDER_WIDTH = 20;
    const float MAX_X_VELOCITY = 10.0;
    const float MAX_Y_VELOCITY = MAX_X_VELOCITY;
    const float MIN_X_VELOCITY = -1.0 * MAX_X_VELOCITY;
    const float MIN_Y_VELOCITY = -1.0 * MAX_Y_VELOCITY;
    const int BARRIER_WIDTH = 20;
    const int BARRIER_HEIGHT = WINDOW_HEIGHT;
    const float BARRIER_X = 1.0 * (CONSTANTS::WINDOW_WIDTH - CONSTANTS::BARRIER_WIDTH) / 2;
    const float BARRIER_Y = 0.0;
}

#endif