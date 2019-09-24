/**
 * LE CARPENTIER Jean-Maxime
 * LEJEUNE Erwin
 **/

/* < Notes >
 * Step 3 :
 * After the value of the byte variable exceeds 255 the variable is overflowed 
 */

#include <LiquidCrystal.h>
#include <TimerOne.h>

#define LED4       7
#define LED2       5  
#define LED1       4
#define LED0       3
#define LED3       6
#define P0         8


LiquidCrystal lcd (18, 17, 16, 15, 14, 19); // Declare variable of LCD Crystal type

// Declare global
unsigned int gPhase = 3;
unsigned int gState = 0;
/*unsigned int gTimeStamp = 0;
unsigned int gTimeStampL2 = 0;
unsigned int gStateL2 = 0;

byte gArithmetic = 0;*/

void setup() {
  // Define LED4 as output pin
  pinMode(LED4, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED0, OUTPUT);
  pinMode(P0, INPUT_PULLUP);

  Timer1.initialize (200000);
  Timer1.attachInterrupt (isr);

  // Write name on first line of lcd screen
  lcd.begin(20, 4);

  // Step 2
  /*lcd.setCursor(0, 0);
  lcd.print("LECARPENTIER LEJEUNE");

  // Step 4
  unsigned int millisSetup = millis();
  lcd.setCursor(0, 2);
  lcd.print(millisSetup);*/
}

void isr () {
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

void loop() {
  // Loop with millis on 0.5 seconds
  // Step 5
  /*if ( millis() - gTimeStamp > 500 ) {
    if (gState == 0) {
      digitalWrite(LED4, HIGH);
      gState = 1;
    }
    else if (gState == 1) {
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
  }*/

  
  
}
