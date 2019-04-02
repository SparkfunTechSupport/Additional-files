/*
 * Quick and dirty test code for the SparkFun COM-10790 encoder.
 * 
 * This sketch counts pulses from an encoder. The COM-10790 encoder 
 * only has one output so you can tell how far the encoder has rotated 
 * but you can't tell what direction the encoder has traveled. This 
 * encoder will pulse 200 times per rotation so one full revolution 
 * (in a single direction) will give you a value of 200 on the serial 
 * monitor. 
 * 
 * Setup: 
 * Blue = GND
 * Brown = +5V
 * Black = D2
 * 
 * You don't absolutely need it, but if you have issues, try connecting 
 * a 10K resistor between D2 and +5V
 */

volatile int IRQcount;
    int pin = 2;
    int pin_irq = 0; //IRQ that matches to pin 2

    void setup() {
      // Put your setup code here, to run once:
      Serial.begin (9600);
      attachInterrupt(pin_irq, IRQcounter, FALLING);
    }

    void IRQcounter() {
      IRQcount++;
    }

    void loop() {
      detachInterrupt(pin);
      Serial.print(F("Counted = "));
      Serial.println(IRQcount);
      //delay(100);
    }
