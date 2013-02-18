* Prints to the screen when the button is pushed/released (irq driven)
  115200@8n1 console on PA2 (tx only)
* uses basic timer 6 with overflows to generate a 1ms counter (not an ideal
  use, but shows some api methods and can be demoed on the disco board)
* uses basic timer 7 with the exti interrupts to do ghetto input capture.
  Not as fast or precise as the real input capture modes, but can be used
  on any gpio pin.

No effort at saving power is made here. Current consumption on the Disco board
is ~7.5mA when the green tick led is off, and about 10.5mA when it is on.

example output:

hi guys!
TICK 0
TICK 1
TICK 2
Pushed down!
held: 443 ms
Pushed down!
TICK 3
held: 217 ms
Pushed down!
held: 99 ms
Pushed down!
TICK 4
held: 73 ms
Pushed down!
held: 60 ms
TICK 5
Pushed down!
held: 98 ms
Pushed down!


