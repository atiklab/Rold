#ifndef SKID_STEER_H
#define SKID_STEER_H

#include <Arduino.h> 

#define MOTOR_SPEED_MAX 255
#define MOTOR_SPEED_MIN -255

/* Defines for the motor shield channel A */
#define PIN_MOTOR_LEFT_DIRECTION 2
#define PIN_MOTOR_LEFT_BRAKE 3
#define PIN_MOTOR_LEFT_SPEED 6

/* Defines for the motor shield channel B */
#define PIN_MOTOR_RIGHT_DIRECTION 4
#define PIN_MOTOR_RIGHT_BRAKE 5
#define PIN_MOTOR_RIGHT_SPEED 7


class SkidSteer {
  private:
    /* Variables */
    bool skidSteerIsReady = false;
    bool skidSteerInitializationFailed = false;
    long delayUntil = 0;
    
    /* Private function prototypes */
    void initialize();
    void releaseMotorBrakes(boolean releaseBrakes);

  public:
    /* Public function prototypes */
    void move(int y, int x);
    void stop();
    void delay(long timeInMillis);
    void moveDistance(int distanceInCm, boolean forward);
    void rotate(int degreesToRotate, boolean CCW);

    boolean isDelaying();
    long getRemainingDelayTime();
};



#endif /*SKID_STEER_H*/
