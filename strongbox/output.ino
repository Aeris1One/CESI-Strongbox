/*
  Constants
  Define pins connected to DELs
*/
const uint8_t del1Pin = 4;
const uint8_t del2Pin = 5;
const uint8_t del3Pin = 6;
const uint8_t del4Pin = 7;
const uint8_t delGreenPin = 3;

/*
  Variables
  failedAuth : number of failedAuth since the last safe opening
  lockTime : time (in tenths of a second) the lock will last on failed opening attempt, will double each time the safe locks
*/
uint8_t failedAuth = 0;
uint8_t lockTime = 300;

/*
  setup
  ---
  Mark all pins connected to DELs as output
*/
void outputSetup() {
  pinMode(del1Pin, OUTPUT);
  pinMode(del2Pin, OUTPUT);
  pinMode(del3Pin, OUTPUT);
  pinMode(del4Pin, OUTPUT);
  pinMode(delGreenPin, OUTPUT);
}

/*
  error
  ---
  Input : Nothing
  Output: Nothing
  Effect: Turn on then off all red leds with a delay of 300 ms, three times
*/
void error() {
  // We print error to Serial
  Serial.println("Authentication en erreur");
  
  // If this is the fourst failed authentication attempt
  // i.e: If there was already 3 failed attempts registered
  if (failedAuth == 3) {
    // Output the lock time to Serial
    Serial.print("Trop d'essai raté, blockage du coffre pendant");
    Serial.print(lockTime / 10);
    Serial.println(" secondes");
    // We lock the safe for lockTime
    lock(lockTime);
    // We double the lockTime for the next time
    lockTime = lockTime * 2;
    // N.B: No need to decrement failedAuth, it will stay at 3 and fire
    // another lock on the next failed attempt.
  } else {
    // We increment the number of failed tries
    failedAuth++;
  }

  // We loop 3 times
  uint8_t count = 3;
  while (count != 0) {
    // Turn on all DELs
    delOutput(4, false);
    // Wait 200ms
    delay(200);
    // Turn off all DELs
    delOutput(0, false);
    // Wait another 200ms
    delay(200);
    // Decrement counter
    count--;
  }
}

/*
  lock
  ---
  Input : Time in tenths of a second
  Output: Nothing
  Effect: Show an animation during the time defined as input. Synchronous, will block execution of the code, effectively
          locking the safe and preventing input.
*/
void lock(uint8_t time) {
  uint8_t delsOn = 0;
  while (time != 0) {
    if (delsOn <= 4) {
      delsOn++;
    } else {
      delsOn = 0;
    }
    delOutput(delsOn, false);
    time--;
    delay(100);
  }
}

/*
  delOutput
  ---
  Input : Integrer "red", boolean "green"
  Output: Nothing
  Effect: Turn on the number of red DEL specified as input. Turn off the excedant.
          Turn on or off the green DEL according to input.
*/
void delOutput(uint8_t red, uint8_t green) {
  if (red >= 1) {
    digitalWrite(del1Pin, HIGH);
  } else {
    digitalWrite(del1Pin, LOW);
  }
  if (red >= 2) {
    digitalWrite(del2Pin, HIGH);
  } else {
    digitalWrite(del2Pin, LOW);
  }
  if (red >= 3) {
    digitalWrite(del3Pin, HIGH);
  } else {
    digitalWrite(del3Pin, LOW);
  }
  if (red >= 4) {
    digitalWrite(del4Pin, HIGH);
  } else {
    digitalWrite(del4Pin, LOW);
  }
  if (green) {
    digitalWrite(delGreenPin, HIGH);
  } else {
    digitalWrite(delGreenPin, LOW);
  }
}