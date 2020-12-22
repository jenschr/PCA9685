#include "pca9685.h"

PCA9685::PCA9685()
{

}

bool PCA9685::begin(uint8_t addr)
{
    _addr = addr;
    Wire.begin();
    return reset();
}

void PCA9685::setPWM(uint8_t ledNum, uint16_t OnValue, uint16_t OffValue)
{
    int result = 9;

    uint8_t targetAddress = PCA9685_LED0_ON_L+(ledNum*4);
    if( ledNum == PCA9685_ALL )
    {
        targetAddress = PCA9685_ALL_LED_ON_L;
    }

    unsigned char buf[5];
    buf[0]= targetAddress;
    buf[1]=OnValue & 0xFF;
    buf[2]=(OnValue >> 8) & 0xF;
    buf[3]=OffValue & 0xFF;
    buf[4]=(OffValue >> 8) & 0xF;
    Wire.beginTransmission(_addr);
    Wire.write(buf,5);
    result = Wire.endTransmission();
    
    if( result > 0 )
    {
        #ifdef PCA9685_SHOW_ERRORS_ON_SERIAL
        Serial.print("PCA9685 ERROR setPWM ");
        Serial.print(result);
        Serial.print(" on led ");
        Serial.println(ledNum);
        #endif
    }
}

void PCA9685::on(uint8_t ledNum)
{
    int result = 9;
    uint8_t targetAddress = PCA9685_LED0_ON_H+(ledNum*4);
    if( ledNum == PCA9685_ALL )
    {
        targetAddress = PCA9685_ALL_LED_ON_H;
    }

    unsigned char buf[2];
    buf[0]= targetAddress;
    buf[1]= 0x00;
    Wire.beginTransmission(_addr);
    Wire.write(buf,2);
    result = Wire.endTransmission();

    if( result > 0)
    {
        #ifdef PCA9685_SHOW_ERRORS_ON_SERIAL
        Serial.print("PCA9685 ERROR ");
        Serial.print(result);
        Serial.print(" on address ");
        Serial.print(targetAddress,HEX);
        Serial.print(" on led ");
        Serial.println(ledNum);
        #endif
    }
}

void PCA9685::off(uint8_t ledNum)
{
    int result = 9;
    uint8_t targetAddress = PCA9685_LED0_ON_H+(ledNum*4);
    if( ledNum == PCA9685_ALL )
    {
        targetAddress = PCA9685_ALL_LED_ON_H;
    }

    unsigned char buf[2];
    buf[0]= targetAddress;
    buf[1]= 0x10;
    Wire.beginTransmission(_addr);
    Wire.write(buf,2);
    result = Wire.endTransmission();

    if( result > 0)
    {
        #ifdef PCA9685_SHOW_ERRORS_ON_SERIAL
        Serial.print("PCA9685 ERROR ");
        Serial.print(result);
        Serial.print(" on address ");
        Serial.print(targetAddress,HEX);
        Serial.print(" on led ");
        Serial.println(ledNum);
        #endif
    }

}

bool PCA9685::reset(void)
{
    bool allIsGood = true;
    int result = 9;
    
    // Setup Mode 1
    unsigned char buf[2];
    buf[0] = PCA9685_MODE1;
    buf[1] = PCA9685_RESTART + PCA9685_AI; // PCA9685_AI
    Wire.beginTransmission(_addr);
    Wire.write(buf,2);
    result = Wire.endTransmission();

    if( result > 0)
    {
        allIsGood = false;
        #ifdef PCA9685_SHOW_ERRORS_ON_SERIAL
        Serial.print("PCA9685 ERROR Mode1");
        Serial.println(result);
        #endif
    }
    
    // wait for restart
    delay(1);

    // Setup Mode 2
    // This is for using an External P-type MOSFET driver, so we should set
    // PCA9685_OUTDRV & PCA9685_INVRT.
    // see datasheet ref 002aad170

    // If you are sinking current directly through the driver (@5V), you probably
    // don't want to set PCA9685_OUTDRV. Just remove it below.
    // See datasheet for details https://www.nxp.com/docs/en/data-sheet/PCA9685.pdf
    buf[0] = PCA9685_MODE2;
    buf[1] = PCA9685_OUTDRV+PCA9685_INVRT;
    Wire.beginTransmission(_addr);
    Wire.write(buf,2);
    result = Wire.endTransmission();

    
    if( result > 0)
    {
        allIsGood = false;
        #ifdef PCA9685_SHOW_ERRORS_ON_SERIAL
        Serial.print("PCA9685 ERROR Mode2");
        Serial.println(result);
        #endif
    }

    // Setup Prescale
    buf[0] = PCA9685_PRE_SCALE;
    buf[1] = 0x1E; // default value. see datasheet for calclulating this
    Wire.beginTransmission(_addr);
    Wire.write(buf,2);
    result = Wire.endTransmission();

    if( result > 0)
    {
        allIsGood = false;
        #ifdef PCA9685_SHOW_ERRORS_ON_SERIAL
        Serial.print("PCA9685 ERROR Prescale");
        Serial.println(result);
        #endif
    }
    return allIsGood;
}
