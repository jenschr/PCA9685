#ifndef PCA9685_BASELIB
#define PCA9685_BASELIB

// MIT License 2020
// Author: jenschr @ github

// Note that this library is a very bare bones implementation that was made to
// serve a very specific purpose. It's a good place to start hacking a full 
// library, but it does not support all the features in the PCA9685.
// See datasheet for details https://www.nxp.com/docs/en/data-sheet/PCA9685.pdf

#include "Wire.h"

#define PCA9685_MODE1           0x00
#define PCA9685_MODE2           0x01
#define PCA9685_SUBADR1         0x02
#define PCA9685_SUBADR2         0x03
#define PCA9685_SUBADR3         0x04
#define PCA9685_ALLCALLADR      0x05
#define PCA9685_LED0_ON_L       0x06
#define PCA9685_LED0_ON_H       0x07
#define PCA9685_LED0_OFF_L      0x08
#define PCA9685_LED0_OFF_H      0x09
#define PCA9685_LED1_ON_L       0x0A
#define PCA9685_LED1_ON_H       0x0B
#define PCA9685_LED1_OFF_L      0x0C
#define PCA9685_LED1_OFF_H      0x0D
#define PCA9685_LED2_ON_L       0x0E
#define PCA9685_LED2_ON_H       0x0F
#define PCA9685_LED2_OFF_L      0x10
#define PCA9685_LED2_OFF_H      0x11
#define PCA9685_LED3_ON_L       0x12
#define PCA9685_LED3_ON_H       0x13
#define PCA9685_LED3_OFF_L      0x14
#define PCA9685_LED3_OFF_H      0x15
#define PCA9685_LED4_ON_L       0x16
#define PCA9685_LED4_ON_H       0x17
#define PCA9685_LED4_OFF_L      0x18
#define PCA9685_LED4_OFF_H      0x19
#define PCA9685_LED5_ON_L       0x1a
#define PCA9685_LED5_ON_H       0x1b
#define PCA9685_LED5_OFF_L      0x1c
#define PCA9685_LED5_OFF_H      0x1d
#define PCA9685_LED6_ON_L       0x1e
#define PCA9685_LED6_ON_H       0x1d
#define PCA9685_LED6_OFF_L      0x20
#define PCA9685_LED6_OFF_H      0x21
#define PCA9685_LED7_ON_L       0x22
#define PCA9685_LED7_ON_H       0x23
#define PCA9685_LED7_OFF_L      0x24
#define PCA9685_LED7_OFF_H      0x25
#define PCA9685_LED8_ON_L       0x26
#define PCA9685_LED8_ON_H       0x27
#define PCA9685_LED8_OFF_L      0x28
#define PCA9685_LED8_OFF_H      0x29
#define PCA9685_LED9_ON_L       0x2a
#define PCA9685_LED9_ON_H       0x2b
#define PCA9685_LED9_OFF_L      0x2c
#define PCA9685_LED9_OFF_H      0x2d
#define PCA9685_LED10_ON_L      0x2e
#define PCA9685_LED10_ON_H      0x2f
#define PCA9685_LED10_OFF_L     0x30
#define PCA9685_LED10_OFF_H     0x31
#define PCA9685_LED11_ON_L      0x32
#define PCA9685_LED11_ON_H      0x33
#define PCA9685_LED11_OFF_L     0x34
#define PCA9685_LED11_OFF_H     0x35
#define PCA9685_LED12_ON_L      0x36
#define PCA9685_LED12_ON_H      0x37
#define PCA9685_LED12_OFF_L     0x38
#define PCA9685_LED12_OFF_H     0x39
#define PCA9685_LED13_ON_L      0x3a
#define PCA9685_LED13_ON_H      0x3b
#define PCA9685_LED13_OFF_L     0x3c
#define PCA9685_LED13_OFF_H     0x3d
#define PCA9685_LED14_ON_L      0x3e
#define PCA9685_LED14_ON_H      0x3f
#define PCA9685_LED14_OFF_L     0x40
#define PCA9685_LED14_OFF_H     0x41
#define PCA9685_LED15_ON_L      0x42
#define PCA9685_LED15_ON_H      0x43
#define PCA9685_LED15_OFF_L     0x44
#define PCA9685_LED15_OFF_H     0x45
#define PCA9685_ALL_LED_ON_L    0xfa
#define PCA9685_ALL_LED_ON_H    0xfb
#define PCA9685_ALL_LED_OFF_L   0xfc
#define PCA9685_ALL_LED_OFF_H   0xfd
#define PCA9685_PRE_SCALE       0xfe

#define PCA9685_ALL 16

// MODE1 bits
#define PCA9685_RESTART         0x80
#define PCA9685_EXTCLK          0x40
#define PCA9685_AI              0x20
#define PCA9685_SLEEP           0x10 // set by default!
#define PCA9685_SUB1            0x08
#define PCA9685_SUB2            0x04
#define PCA9685_SUB3            0x02
#define PCA9685_ALLCALL         0x01

#define PCA9685_INVRT           0x10
#define PCA9685_OCH             0x08
#define PCA9685_OUTDRV          0x04 // set by default! (OUTDRV = totem pole mode )
#define PCA9685_OUTNE1          0x02
#define PCA9685_OUTNE0          0x01

// uncomment to view any errors
//#define PCA9685_SHOW_ERRORS_ON_SERIAL 

class PCA9685 {
    public:
        PCA9685();
        bool begin(uint8_t addr);
        void setPWM(uint8_t ledNum, uint16_t OnValue = 2047, uint16_t OffValue = 4095);
        void on(uint8_t ledNum);
        void off(uint8_t ledNum);
    private:
        bool reset(void);
        uint8_t _addr;
};
#endif // PCA9685_BASELIB