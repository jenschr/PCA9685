#include <pca9685.h>

PCA9685 outputs;

void setup() {
  outputs.begin( 0x40 );
}

void loop() {
  // blink single
  outputs.on(0);
  delay(1000);
  outputs.off(0);
  delay(1000);

  // blink all
  outputs.on(PCA9685_ALL);
  delay(1000);
  outputs.off(PCA9685_ALL);
  delay(1000);

  // fade output 0 up and down
  for( int i=0;i<4095;i++ )
  {
    outputs.setPWM(0,0,i);
  }
  for( int i=4095;i>0;i-- )
  {
    outputs.setPWM(0,0,i);
  }
}