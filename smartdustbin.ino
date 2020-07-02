#include <NewPing.h>
#include <Servo.h>
Servo servo
#define t 5
#define e 6
#define max 2000
int servoPin =7;
NewPing sonar(t, e, max);

void setup()
{
    servo.attach(servoPin);
    servo.write(0);
    delay(1000);
    servo.detach();
    Serial.begin(9600);

}

void loop()
{
    delay(50);
    if (sonar.ping_cm()<=20)
    {
        servo.attach(servoPin);
        delay(1);
        servo.write(120);
        delay(1000);

    }
    else
    {
        servo.write(0);
        delay(1000);
        servo.detach();

    }
}