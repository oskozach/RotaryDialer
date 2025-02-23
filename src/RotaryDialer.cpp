#include "RotaryDialer.h"

RotaryDialer::RotaryDialer(uint8_t pinArmed, uint8_t pinPulse) 
                        : _armedInput(pinArmed, FALLING),
                            _pulseInput(pinPulse, FALLING, true),
                            _pulseCount(0) {}

uint8_t RotaryDialer::_convertPulseToDigit() { return (_pulseCount == 10) ? 0 : _pulseCount; }

bool RotaryDialer::_isValidPulse() { return _pulseCount > 0 && _pulseCount <= 10; }

void RotaryDialer::init() {
    _pulseCount = 0;
    _armedInput.begin();
    _pulseInput.begin();
}

bool RotaryDialer::handleDialInput(uint8_t *dialedDigit) {
    if(_armedInput.changed() && _isValidPulse()) {
        *dialedDigit = _convertPulseToDigit(); 
        _pulseCount = 0;
        return true;
    }
    if(RotaryDialer::isArmed() && _pulseInput.changed())
        _pulseCount++;
    return false;
}

bool RotaryDialer::isArmed() { return _armedInput.getState(); }
