#ifndef __ROTARY_DIALER_H__
#define __ROTARY_DIALER_H__
#include <InputSwitch.h>

#define ROTARY_DIALER_DEFAULT_PIN_PULSE 2
#define ROTARY_DIALER_DEFAULT_PIN_ARMED 3

class RotaryDialer {
    private:
        InputSwitch _armedInput;
        InputSwitch _pulseInput;
        uint8_t _pulseCount;
        uint8_t _convertPulseToDigit();
        bool _isValidPulse();
    public:
        RotaryDialer(uint8_t pinArmed = ROTARY_DIALER_DEFAULT_PIN_ARMED, 
                    uint8_t pinPulse = ROTARY_DIALER_DEFAULT_PIN_PULSE);
        void init();
        bool getDigit(uint8_t &digit);
        bool isArmed();
};
#endif
