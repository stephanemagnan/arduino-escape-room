# arduino-escape-room
This project contains individual scripts for your next Arduino/microcontroller escape room! Each script can be run individually and corresponds to a specific component of an adventure.

## blink_light
This script sends a message by blinking a single LED light according to a customizable pattern to communicate an idea such as a number. Currently, it will blink X times, then wait, then blink Y times, the wait, then blink Z times. After a prolonged wait, it will restart. All values can be easily tuned to communicate the digits of a combination lock for example. 

## bomb_timer
This project is a countdown timer for a 4x7 Segment display with a 'bomb' that is a series of wires that must be cut in the correct order. Clues within your custom escape room must be configured so that the wires get cut in the correct order. You could either number the wires or use different coloured wires. If you don't have enough colours, you can wrap two together (e.g., black and yellow) with only one of them actually being plugged in to the circuit.

### Wiring

Wiring diagram for Arduino UNO/NANO
Pins of 3641AS when looking at front of display
Top Row:    1 A F  2 3 B
Bottom Row: E D DP C G 4
D2: 1 (through 330 Ohm resistor)
D3: 2 (through 330 Ohm resistor)
D4: 3 (through 330 Ohm resistor)
D5: 4 (through 330 Ohm resistor)
D6: A
D7: B
D8: C
D9: D
D10: E
D11: F
D12: G
D13: DP

##bomb_wires
Contains only the protion of the defuse script from bomb_timer without the 4x7 segment display.

