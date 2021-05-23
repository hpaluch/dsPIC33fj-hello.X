# Demo for dsPIC33FJ on Microstick II

Here is modified LED blinking demo for [dsPIC33FJ128MC802][dsPIC33FJ128MC802]
that is provided with [Microstick II][PIC Microstick II] board.

Now it does following (I use it to measure FRC oscillator frequency):

* - Blinking LED on RA0 PIN 2 at frequency `F_cy / 10,000,000`
    (TMR1 interrupt freq is f_cy / 1,000,000)
* - `f_cy / 1000` output on RA1 PIN 3

In my case default `f_cy = 40 MHz kHz`, so `f_pll = 80 MHz`

Now we use PLL, so we may say:
- `f_frc = 7.37 MHz`
- `f_pll = 80 MHz`
- `f_cy  = 40 MHz` (40 MIPS) instruction clock

## Why not use MCC tool to generate sources?

The whole dsPICFJ series is NOT supported
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

# Resources

* How to configure FRC with PLL to get f 80 MHz ( f_cy = 40 MHz, 40 MIPS):
  - http://ww1.microchip.com/downloads/en/DeviceDoc/DS-70596A.pdf

[PIC Microstick II]: https://www.microchip.com/DevelopmentTools/ProductDetails/dm330013-2
[dsPIC33FJ128MC802]: https://www.microchip.com/wwwproducts/en/dsPIC33FJ128MC802
