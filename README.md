# COMPSYS303 Assignment 2
## Pacemaker Group 9

Upload the provided .sof file onto the DE2 board, run NIOS II and import in the cs303a2 and cs303a2_bsp files respectively.
TO SWITCH MODE: Use SW0. SW0 low = Mode 1, SW0 high = Mode 2.

KNOWN BUG: The DE2 will freeze occasionally if the system is switched from Mode 1 or Mode 2 mid-operation. Switch to your desired mode and re-program the DE2 device.

#### Mode 1 testing: 
- Use the buttons on the DE2 board to assert inputs
- Key1 = ASense (makes LED1 high)
- Key0 = VSense (makes LED0 high)

- Outputs:
- APace = LED3
- VPace = LED2

#### Mode 2 testing:
- Open the virtual heart executable, find the appropriate COM in the dropdown, and set a baud rate of 115200.
- Test mode 1 by unchecking the SA Autorhythmic checkbox, and verify that atrial pulses are slower and require APace.
- Test mode 2 by unchecking the AV Autorhythmic checkbox, and verify that both A and V pulses are slower, with erratic atrial signals.
- Test mode 3 by keeping SA node checked but AV conduction unchecked, this should verify correct 100bpm operation on the atrial graph but VPace required for the very slow (~30bpm) ventricle beating.
