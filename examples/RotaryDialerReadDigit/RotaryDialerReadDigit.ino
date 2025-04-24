#include <RotaryDialer.h>

#define PIN_PULSE 2 //default
#define PIN_ARMED 3 //default

RotaryDialer dialer(PIN_ARMED, PIN_PULSE);

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
