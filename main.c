/**********************************************************************
* © 2005 Microchip Technology Inc.
*
* Modified by Henryk Paluch for dsPIC33FJ128MC802 
* running on Microstick II board.
* 
* FileName:        main.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC33Fxxxx/PIC24Hxxxx
* Compiler:        XC16 v1.70
* IDE:             MPLAB X IDE v5.45
* DFP:             dsPIC33F-GP-MC_DFP 1.0.6???
* Tested On:	   dsPIC33FJ128MC802
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Abhishek Jain		04/10/2007  
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* ADDITIONAL NOTES: 
* The Processor starts with the External Crystal without PLL enabled and then the Clock is switched to PLL Mode.
*
**********************************************************************/
#if defined(__dsPIC33F__)
#include "p33Fxxxx.h"
#elif defined(__PIC24H__)
#include "p24Hxxxx.h"
#endif


// in init_timer.c
extern void Init_Timer1( void );

// **     FNOSC_FRC            Internal Fast RC (FRC) - 
// The Fast RC (FRC) internal oscillator runs at a nominal 
// frequency  of  7.37  MHz. 
_FOSCSEL(FNOSC_FRC);
// **     OSCIOFNC_OFF         OSC2 pin has clock out function
// **     FCKSM_CSECMD         Clock switching is enabled, Fail-Safe Clock Monitor is disabled
// **     POSCMD_XT            XT Oscillator Mode (ignored in FRC mode)


_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF  & POSCMD_XT);	// Clock Switching Enabled and Fail Safe Clock Monitor is disabled
													// OSC2 Pin Function: OSC2 is Clock Output
													// Primary Oscillator Mode: XT Crystal
_FWDT(FWDTEN_OFF); 			            			// Watchdog Timer Enabled/disabled by user software

// NOTE: volatile is absolutely necessary for XC16 v1.70
volatile unsigned int Count;

/* ISR ROUTINE FOR THE TIMER1 INTERRUPT */

void __attribute__((interrupt,no_auto_psv)) _T1Interrupt( void )
{
	
	
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 0;
   	Count++;
	if(Count == 10)
	{
		    Count		   = 0;  
			LATAbits.LATA0 = ~LATAbits.LATA0;		    
	}

    TMR1          = 0;
	T1CONbits.TON = 1;
	/* reset Timer 1 interrupt flag */
 	
}
/*-----------------------*/

int main(void)
{
	
	RCONbits.SWDTEN=0;            /* Disable Watch Dog Timer*/
	
// Configure Oscillator to operate the device at 40Mhz
// Fosc= Fin*M/(N1*N2), Fcy=Fosc/2
// Fosc= 8M*40/(2*2)=80Mhz for 8M input clock
	PLLFBD=38;					// M=38
	CLKDIVbits.PLLPOST=0;		// N1=2
	CLKDIVbits.PLLPRE=0;		// N2=2

#if 0    
// Clock switching to incorporate PLL
	__builtin_write_OSCCONH(0x03);		// Initiate Clock Switch to Primary
													// Oscillator with PLL (NOSC=0b011)
	__builtin_write_OSCCONL(0x01);		// Start clock switching
	while (OSCCONbits.COSC != 0b011);	// Wait for Clock switch to occur	
#endif 

   /*Initialize the Ports */    

    TRISA = 0x0000;
    LATA  = 0x0000;
    PORTA = 0x0000;

    /*Initialize Timer 1 for Period Interrupts*/

    Init_Timer1();

	
	while(1)
	{
	
	}
}
/******************************************************************************/

