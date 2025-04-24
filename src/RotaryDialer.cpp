#include "RotaryDialer.h"

RotaryDialer::RotaryDialer(uint8_t dialInProgress, uint8_t pinPulse) 
                            : _dialInProgressInput(dialInProgress, FALLING),
                                _pulseInput(pinPulse, FALLING, true),
                                _pulseCount(0) {}

uint8_t RotaryDialer::_convertPulseToDigit() { return (_pulseCount == 10) ? 0 : _pulseCount; }

bool RotaryDialer::_isValidPulse() { return _pulseCount > 0 && _pulseCount <= 10; }

void RotaryDialer::init() {
    _pulseCount = 0;
    _dialInProgressInput.begin();
    _pulseInput.begin();
}

bool RotaryDialer::getDigit(uint8_t &digit) {
    if(_dialInProgressInput.changed()) {
        bool valid = _isValidPulse();
        if(valid)
            digit = _convertPulseToDigit();
        _pulseCount = 0;
        return valid;
    }
    if(isDialing() && _pulseInput.changed())
        _pulseCount++;
    return false;
}

bool RotaryDialer::isDialing() { return _dialInProgressInput.getState(); }
