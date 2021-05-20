# Demo for dsPIC33FJ on Microstick II

Here is trivial LED blinking demo for [dsPIC33FJ128MC802][dsPIC33FJ128MC802]
that is provided with [Microstick II][PIC Microstick II] board.

What's the problem? The whole dsPICFJ series is NOT supported
by MCC configuration tool (at least not on 2021-05-20).
So you must create most of sources
manually... and that's where adventure starts...


This example is based on source from:
- https://ww1.microchip.com/downloads/en/DeviceDoc/CE143_Timer_Period_14aug09.zip
- available on link `CE143 - Using Timer1 for Period Interrupts`
  from [dsPIC33FJ128MC802][dsPIC33FJ128MC802]

You can review my changes comparing `main.c` with `main.c.original` (untouched
from Microchip ZIP archive).

# Setup

Hardware:
- you need [PIC Microstick II][PIC Microstick II]
- remember to insert provided [dsPIC33FJ128MC802][dsPIC33FJ128MC802]
  into socket.

Software:
- XC16 v1.70
- MPLAB X IDE v5.45
- Device Family Pack (DFP):  `dsPIC33F-GP-MC_DFP 1.0.6` (not sure)

You can debug and/or run this project as usual (no special instructions needed).


[PIC Microstick II]: https://www.microchip.com/DevelopmentTools/ProductDetails/dm330013-2
[dsPIC33FJ128MC802]: https://www.microchip.com/wwwproducts/en/dsPIC33FJ128MC802
