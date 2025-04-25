# Rotary Dialer

The `RotaryDialer` library allows you to interface an Arduino with a telephone rotary dial. It provides functionality to read pulse inputs from the dial and convert them into corresponding digits.

**Note:** This library relies on the [InputSwitch](https://github.com/oskozach/InputSwitch) library for managing debounced and edge-detected digital input signals.

## Wiring

- **Dial In Progress Pin:** Connects to the dial in progress signal of the rotary dial, with a 220Ω pull-down resistor (**Default:** Pin 3).
- **Pulse Pin:** Connects to the pulse signal of the rotary dial, with a 220Ω pull-down resistor (**Default:** Pin 2).
