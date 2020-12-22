# PCA9685
Simple PCA9685 library for Arduino, Particle &amp; Teensy that just sets the outputs. Can be used for controlling LEDs, servos or anything.

## Usage
Create an instance and pass the output you want to change (see example).

On/off methods take the output number (0-15) as a parameter. The setPwm method do the same, but adds on/off timing parameters (when to turn on or off 0-4095) like this:

`outputs.setPWM(1,1023,4095);`

You can also pass PCA9685_ALL to any mentod to toggle all outputs at once:

`outputs.setPWM(PCA9685_ALL,1023,4095);`

`outputs.off(PCA9685_ALL);`


