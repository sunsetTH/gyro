/*-----------------------ADIS16405 Driver Test Code-----------------------------------

Author: 		ADI CAST (China Application Support Team)
Date:			2010-04-22
Rev:			V1.0
Description:	Realize ADIS16405 Driver£¬Use ADuC7026 as MCU£¬Development Tool: KEIL C
				Test program by reading triple axis gyroscope and triple axis accelerometer 
				and triple axis magnetometer and send the Z axis acceleration to PC through UART 

---------------------------------------------------------------------------------------------------------*/
#include <ADuC7026.h>
#include "ADIS16405_IO.h"
#include "ADIS16405.h"

//Three Axis Gyro and Acceleration and Magnetometer Flag
#define		GyroX		0		
#define		GyroY		1
#define		GyroZ		2
#define		AccX		3		
#define		AccY		4
#define		AccZ		5
#define		MagX		6		
#define		MagY		7
#define		MagZ		8

signed		int		GyroAccMag[9];		//Three Axis Gyro and Three Axis Acceleration and Three Axis Magnetometer Value
unsigned	char	Calculate_Sign = 0;	//Flag for Timer Out

unsigned	char	RegisterData[8];
union{unsigned int ui;unsigned char uc[4];}un;

void putchar(unsigned char ch)/* Write character to Serial Port  */  
{          
	COMTX = ch;				 //COMTX is an 8-bit transmit register.
    while(!(0x020==(COMSTA0 & 0x020)))
    {;}
}

void IRQ_Handler() __irq
{
    if(0 != (IRQSTA & GP_TIMER_BIT))	//TIMER1 Interrupt
    {  
		T1CLRI = 0;
		Calculate_Sign = 1;
		return;
    }
}
void ADuC7026_Initiate(void)
{
    //Clock Initial
    POWKEY1 = 0x01;				//Start PLL Setting
    POWCON = 0x00;				//Set PLL Active Mode With CD = 0  CPU CLOCK DIVIDER = 41.78MHz
    POWKEY2 = 0xF4;				//Finish PLL Setting

	GP1CON = 0x011;					//PIN set up for UART
	GP2DAT = GP2DAT | 0x04040000;	//Disable LCD;
	GP0DAT = GP0DAT | 0x02020000;	//Disable LED;
 
	GP0DAT = GP0DAT & 0xDFFFFFFF;	//Configure the P0.5 pin as input for DOUT of ADIS16405

	GP4DAT = GP4DAT | 0x38380000;	//Configure the P4.3 pin as output for CS of ADIS16405, CS Stall High
									//Configure the P4.4 pin as output for SCLK of ADIS16405, SCLK Stall High
									//Configure the P4.5 pin as output for DIN of ADIS16405	
/*   
	//UART Initial£¬Baud Rate = 9600
	COMCON0 = 0x080;  
	COMDIV0 = 0x088;    		
	COMDIV1 = 0x000;
	COMCON0 = 0x007; 
*/

	//UART Initial£¬Baud Rate = 115200		 
	COMCON0 = 0x80;					
   	COMDIV0 = 0x0B;					
	COMDIV1 = 0x00;
   	COMCON0 = 0x07;
  	COMDIV2 = 0x883E;	

	//Timer1 Initial 
//	T1LD = 0xCC010;					//Interval = 20ms
	T1LD = 0x13EC190;				//Interval = 0.5s
	T1CON = 0xC0;
					
	IRQEN = GP_TIMER_BIT;			//Enable Timer1 Interrupt	
}   
void main (void)
{ 
    ADuC7026_Initiate();
	ReadFromADIS16405ViaSpi(XGYRO_OUT,1,RegisterData);

	while(1)
	{
		if(1 == Calculate_Sign)
		{
			Calculate_Sign = 0;

			ReadFromADIS16405ViaSpi(YGYRO_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[GyroX]	= RegisterData[1];
			GyroAccMag[GyroX]	= (GyroAccMag[GyroX]<<8) | RegisterData[0];
			
			ReadFromADIS16405ViaSpi(ZGYRO_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[GyroY]	= RegisterData[1];
			GyroAccMag[GyroY]	= (GyroAccMag[GyroY]<<8) | RegisterData[0];		
		
			ReadFromADIS16405ViaSpi(XACCL_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[GyroZ]	= RegisterData[1];
			GyroAccMag[GyroZ]	= (GyroAccMag[GyroZ]<<8) | RegisterData[0];
		
			ReadFromADIS16405ViaSpi(YACCL_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[AccX]	= RegisterData[1];
			GyroAccMag[AccX]	= (GyroAccMag[AccX]<<8) | RegisterData[0];
	
			ReadFromADIS16405ViaSpi(ZACCL_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[AccY]	= RegisterData[1];
			GyroAccMag[AccY]	= (GyroAccMag[AccY]<<8) | RegisterData[0];

			ReadFromADIS16405ViaSpi(XMAGN_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[AccZ]	= RegisterData[1];
			GyroAccMag[AccZ]	= (GyroAccMag[AccZ]<<8) | RegisterData[0];
		
			ReadFromADIS16405ViaSpi(YMAGN_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[MagX]	= RegisterData[1];
			GyroAccMag[MagX]	= (GyroAccMag[MagX]<<8) | RegisterData[0];
	
			ReadFromADIS16405ViaSpi(ZMAGN_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[MagY]	= RegisterData[1];
			GyroAccMag[MagY]	= (GyroAccMag[MagY]<<8) | RegisterData[0];
		
			ReadFromADIS16405ViaSpi(XGYRO_OUT,1,RegisterData);
			RegisterData[1] &= 0x3F;
			GyroAccMag[MagZ]	= RegisterData[1];
			GyroAccMag[MagZ]	= (GyroAccMag[MagZ]<<8) | RegisterData[0];
				
			un.ui = GyroAccMag[AccZ]; 
			putchar(un.uc[1]);
			putchar(un.uc[0]);

		}
	}	

}