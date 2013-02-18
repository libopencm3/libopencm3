This is _functionally_ identical to the "button-irq-printf"
example, but has been modified to use some low power features.

There is a 115200@8n1 console on PA2, which prints a tick count every second,
and when the user push button is pressed, the time it is held down for is
timed (in milliseconds)

Instead of free running timers and busy loops, this version uses the RTC
module and attempts to sleep as much as possible, including while the button
is pressed.

Status
~~~~~~
Only very basic power savings are done!

Current consumption, led off/on, 16Mhz HSI:    2.7mA/5.4mA
Current consumption, led off/on,  4Mhz HSI:    1.4mA/?.?mA
Current consumption, led off/on,  4Mhz MSI:    0.9mA/?.?mA
