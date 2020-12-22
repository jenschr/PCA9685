# PCA9685
Simple PCA9685 library for Arduino, Particle &amp; Teensy that just sets the outputs. Can be used for controlling LEDs, servos or anything.

## Usage
Create an instance and pass the output you want to change (see example).

On/off methods take the output number (0-15) as a parameter. The setPwm method do the same, but adds on/off timing parameters (when to turn on or off 0-4095) like this:

`outputs.setPWM(1,1023,4095);`

You can also pass PCA9685_ALL to any mentod to toggle all outputs at once:

`outputs.setPWM(PCA9685_ALL,1023,4095);`

`outputs.off(PCA9685_ALL);`

Note that by default, all outputs are on when using inverted setup + totem drivers (for driving External P-type MOSFET's). If you are sinking current directly through the driver (@5V), you probably don't want to set PCA9685_OUTDRV. Just remove it below. See datasheet for details https://www.nxp.com/docs/en/data-sheet/PCA9685.pdf 
