#include <RotaryDialer.h>

#define PIN_PULSE 2 //default
#define PIN_DIAL_IN_PROGRESS 3 //default

RotaryDialer dialer(PIN_DIAL_IN_PROGRESS, PIN_PULSE);

void setup() {
    Serial.begin(9600);
    delay(500);
    dialer.init();
}

void loop() {
    uint8_t digit;
    if(dialer.getDigit(digit))
        Serial.println(digit);
}
