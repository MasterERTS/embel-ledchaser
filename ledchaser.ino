#include "ledchaser.h"

unsigned int gPhase = 3;

void setupChaser() {

    pinMode(LED4, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED0, OUTPUT);
    pinMode(P0, INPUT_PULLUP);

    Timer1.initialize (200000);
    Timer1.attachInterrupt (isr);

    if (!gScreenInit) initLCD();
}

void irqHelper() {
    // Keep the led chaser in current state while button is pressed
    while (digitalRead(P0) == LOW) {}

    // LED chaser back and forth
    if (gState == 1) {
        digitalWrite(gPhase, HIGH);
    
        if (gPhase == 3) {
            digitalWrite(7,LOW);     // turn off the previous led ( in that case gPhase - 1 doesn't work since it's the last led )
        } else {
            digitalWrite(gPhase - 1, LOW); // turn off the previous led
        }
        
        ++gPhase;
        if (gPhase > 7) {
            gPhase = 7;
            gState = 0;
        }
        
    } else if (gState == 0) {
        digitalWrite(gPhase, HIGH);
        if (gPhase == 7) {
            digitalWrite(3, LOW);
        } else {
            digitalWrite(gPhase + 1, LOW);
        }

        --gPhase;
        if (gPhase < 3) {
            gPhase = 3;
            gState = 1;
        }
    }
}
