#include "lcdincr.h"

LiquidCrystal lcd (18, 17, 16, 15, 14, 19); // Declare variable of LCD Crystal type

unsigned int gTimeStamp = 0;
unsigned int gTimeStampL2 = 0;
unsigned int gState = 0;
unsigned int gStateL2 = 0;

bool gScreenInit = false;

byte gArithmetic = 0;

void initLCD() {
    lcd.begin(20,4);
    gScreenInit = true;
}

void setLCD() {

    if (!gScreenInit) initLCD();

    lcd.setCursor(0, 0);
    lcd.print("LCD ON");

    pinMode(LED4, OUTPUT);
    pinMode(LED2, OUTPUT);

    // Step 4
    unsigned int millisSetup = millis();
    lcd.setCursor(0, 2);
    lcd.print(millisSetup);
}

void loopLCD() {
    if ( millis() - gTimeStamp > 500 ) {
        if (gState == 0) {
            digitalWrite(LED4, HIGH);
            gState = 1;
        } else if (gState == 1) {
            digitalWrite(LED4, LOW);
            gState = 0;
        }

        // Step 3
        lcd.setCursor(0,1);
        lcd.print(gArithmetic);
        
        gArithmetic += 20;
        gTimeStamp = millis();

        // Value is incremented by 501 at each loops
        unsigned int millisLoop = millis();
        lcd.setCursor(7, 2);
        lcd.print(millisLoop);
    }

    // Step 6
    if ( millis() - gTimeStampL2 > 499 ) {
        if (gStateL2 == 0) {
            digitalWrite(LED2, HIGH);
            gStateL2 = 1;
        }
        else if (gStateL2 == 1) {
            digitalWrite(LED2, LOW);
            gStateL2 = 0;
        }
    gTimeStampL2 = millis();
  }
}
