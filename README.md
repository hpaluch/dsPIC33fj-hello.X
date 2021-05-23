# Demo for dsPIC33FJ on Microstick II

Here is modified LED blinking demo for [dsPIC33FJ128MC802][dsPIC33FJ128MC802]
that is provided with [Microstick II][PIC Microstick II] board.

Now it does following (I use it to measure FRC oscillator frequency):

* - Blinking LED on RA0 PIN 2 at frequency `F_cy / 1,000,000`
* - `f_cy / 1000` output on RA1 PIN 3

In my case default `f_cy = 3.6757 kHz`, so `f_osc = 7.3514 MHz`

Tuning FRC to 8 MHz. I used debugger session and paused
program (anywhere) then directly modified OSCTUN register.

In my case I found following:
- OSCTUN = 0x0014 => `f_cy = 4.0082 MHz`
- OSCTUN = 0x0013 => `f_cy = 3.9984 MHz`

I used OSCTUN = 0x0014 in source...


Why not use MCC tool to generate sources?

The whe dsPICFJ series is NOT supported
by MCC configuration tool (at least not on 2021-05-20).
So you must create most of sources
manually... and that's where adventure starts...

This example is originaly based on source from:
- https://ww1.microchip.com/downloads/en/DeviceDoc/CE143_Timer_Period_14aug09.zip
- available on link `CE143 - Using Timer1 for Period Interrupts`
  from [dsPIC33FJ128MC802][dsPIC33FJ128MC802]

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
