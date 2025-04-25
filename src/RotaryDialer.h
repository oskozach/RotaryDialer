#ifndef __ROTARY_DIALER_H__
#define __ROTARY_DIALER_H__
#include <InputSwitch.h>

#define ROTARY_DIALER_DEFAULT_PIN_PULSE 2
#define ROTARY_DIALER_DEFAULT_PIN_DIAL_IN_PROGRESS 3

class RotaryDialer {
    private:
        InputSwitch _dialInProgressInput;
        InputSwitch _pulseInput;
        uint8_t _pulseCount;
        uint8_t _convertPulseToDigit();
        bool _isValidPulse();
    public:
        RotaryDialer(uint8_t pinDialInProgress = ROTARY_DIALER_DEFAULT_PIN_DIAL_IN_PROGRESS, 
                        uint8_t pinPulse = ROTARY_DIALER_DEFAULT_PIN_PULSE);
        void init();
        bool getDigit(uint8_t &digit);
        bool isDialing();
};
#endif
