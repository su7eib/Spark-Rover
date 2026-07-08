// add servo and ultreasonic librarys

#include <Servo.h>
#include <UltrasonicSensorLibrary>

// set variabels

Ultrasonic ultrasonic(2,3);
Servo servo;

// left motors

int EN1_motor1 = 5;
int EN2_motor1 = 6;
int EN3_motor2 = 7;
int EN4_motor2 = 8;

// right mototrs

int EN1_motor3 = 9;
int EN2_motor3 = 10;
int EN3_motor4 = 11;
int EN4_motor4 = 12;

int switch = 13;

float forward_distance;
float right_distance;
float left_distance;

const int CENTER = 90;
const int RIGHT = 30;
const int LEFT = 150; 
void setup()
{   
    // setup components

    ultrasonic.begin();

    servo.attach(4);

    pinMode(EN1_motor1, OUTPUT);
    pinMode(EN2_motor1, OUTPUT);
    pinMode(EN3_motor2, OUTPUT);
    pinMode(EN4_motor2, OUTPUT);

    pinMode(EN1_motor3, OUTPUT);
    pinMode(EN2_motor3, OUTPUT);
    pinMode(EN3_motor4, OUTPUT);
    pinMode(EN4_motor4, OUTPUT);

}

void loop()
{
    // read distance

    forward_distance = ultrasonic.readCM();


    if (forward_distance > 25)
    {
        forward();
    }

    else
    {
        brake();

        servo.write(RIGHT);
        delay(400);

        right_distance = ultrasonic.readCM();

        servo.write(LEFT);
        delay(400);

        left_distance = ultrasonic.readCM();

        servo.write(CENTER);
        delay(300);

        if(right_distance > left_distance)
        {
            right();
            delay(400);
            forward();
        }

        else if(left_distance > right_distance)
        {
            left();
            delay(400);
            forward();
        }

        else
        {
           rotate180();
           delay(400);
           forward();
        }
    }



void forward()
{
    // all motors move forward

    digitalWrite(EN1_motor1, HIGH);
    digitalWrite(EN2_motor1, LOW);

    digitalWrite(EN3_motor2, HIGH);
    digitalWrite(EN4_motor2, LOW);

    digitalWrite(EN1_motor3, HIGH);
    digitalWrite(EN2_motor3, LOW);

    digitalWrite(EN3_motor4, HIGH);
    digitalWrite(EN4_motor4, LOW);
}

void backword()
{
    // all motors move backword

    digitalWrite(EN1_motor1, LOW);
    digitalWrite(EN2_motor1, HIGH);

    digitalWrite(EN3_motor2, LOW);
    digitalWrite(EN4_motor2, HIGH);

    digitalWrite(EN1_motor3, LOW);
    digitalWrite(EN2_motor3, HIGH);

    digitalWrite(EN3_motor4, LOW);
    digitalWrite(EN4_motor4, HIGH);
}

void right()
{
    // robot move right

    digitalWrite(EN1_motor1, HIGH);
    digitalWrite(EN2_motor1, LOW);

    digitalWrite(EN3_motor2, HIGH);
    digitalWrite(EN4_motor2, LOW);

    digitalWrite(EN1_motor3, LOW);
    digitalWrite(EN2_motor3, HIGH);

    digitalWrite(EN3_motor4, LOW);
    digitalWrite(EN4_motor4, HIGH);
}

void left()
{
    // robot move left

    digitalWrite(EN1_motor1, LOW);
    digitalWrite(EN2_motor1, HIGH);

    digitalWrite(EN3_motor2, LOW);
    digitalWrite(EN4_motor2, HIGH);

    digitalWrite(EN1_motor3, HIGH);
    digitalWrite(EN2_motor3, LOW);

    digitalWrite(EN3_motor4, HIGH);
    digitalWrite(EN4_motor4, LOW);
}

void rotate180()
{
    // robot rotate 180

    digitalWrite(EN1_motor1, HIGH);
    digitalWrite(EN2_motor1, LOW);

    digitalWrite(EN3_motor2, HIGH);
    digitalWrite(EN4_motor2, LOW);

    digitalWrite(EN1_motor3, LOW);
    digitalWrite(EN2_motor3, HIGH);

    digitalWrite(EN3_motor4, LOW);
    digitalWrite(EN4_motor4, HIGH);

    delay(900);

    digitalWrite(EN1_motor1, LOW);
    digitalWrite(EN2_motor1, LOW);

    digitalWrite(EN3_motor2, LOW);
    digitalWrite(EN4_motor2, LOW);

    digitalWrite(EN1_motor3, LOW);
    digitalWrite(EN2_motor3, LOW);

    digitalWrite(EN3_motor4, LOW);
    digitalWrite(EN4_motor4, LOW);
}

void stop()
{
    // stop the robot

    digitalWrite(EN1_motor1, LOW);
    digitalWrite(EN2_motor1, LOW);

    digitalWrite(EN3_motor2, LOW);
    digitalWrite(EN4_motor2, LOW);

    digitalWrite(EN1_motor3, LOW);
    digitalWrite(EN2_motor3, LOW);

    digitalWrite(EN3_motor4, LOW);
    digitalWrite(EN4_motor4, LOW);
}

void brake()
{
    // break the motor

    digitalWrite(EN1_motor1, HIGH);
    digitalWrite(EN2_motor1, HIGH);

    digitalWrite(EN3_motor2, HIGH);
    digitalWrite(EN4_motor2, HIGH);

    digitalWrite(EN1_motor3, HIGH);
    digitalWrite(EN2_motor3, HIGH);

    digitalWrite(EN3_motor4, HIGH);
    digitalWrite(EN4_motor4, HIGH);
}
}