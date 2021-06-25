# 4x4-Button-Arduino-Shortcut
4x4 PushButton to Arduino to Keyboard Shortcut (for Macro software to receive &amp; perform automation on computer)

Arduino code (.ino) just listens for button presses, determines which button was pressed, then sends a keyboard shortcut to the USB-connected computer - via: Arduino Pro Micro (In Arduino IDE, choose 'SparkFun Pro Micro' board. Choose appropriate 3.3V (clk: 8MHz) or 5V (clk: 16MHz) Processor. [I'm currently using 5V.] Choose Port.)

If can't see Port in Arduino IDE:
https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/troubleshooting-and-faq
In Short: hook up a reset button. Plug in board. In Arduino IDE click upload, then ~1 sec later, hit reset btn 2x fast. (keep trying until timing is about right).

.macros file contains macros for the "Keyboard Maestro" app on Mac comptuers. These macros do the heavy lifting for actually automating the interaction with the PGS app. Probably won't work out of the box, but should get you off to a good start, if you have Keyboard Maestro.
