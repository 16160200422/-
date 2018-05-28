#include "LPC11xx.h"
#define LED1_ON() (LPC_GPIO2->DATA &=~(1<<0))
#define LED1_OFF() (LPC_GPIO2->DATA |=(1<<0))
#define LED2_ON() (LPC_GPIO2->DATA &=~(1<<1))
#define LED2_OFF() (LPC_GPIO2->DATA |=(1<<1))
#define LED3_ON() (LPC_GPIO2->DATA &=~(1<<2))
#define LED3_OFF() (LPC_GPIO2->DATA |=(1<<2))
#define LED4_ON() (LPC_GPIO2->DATA &=~(1<<3))
#define LED4_OFF() (LPC_GPIO2->DATA |=(1<<3))
#define LED5_ON() (LPC_GPIO2->DATA &=~(1<<4))
#define LED5_OFF() (LPC_GPIO2->DATA |=(1<<4))
#define LED6_ON() (LPC_GPIO2->DATA &=~(1<<5))
#define LED6_OFF() (LPC_GPIO2->DATA |=(1<<5))
#define LED7_ON() (LPC_GPIO2->DATA &=~(1<<6))
#define LED7_OFF() (LPC_GPIO2->DATA |=(1<<6))
#define LED8_ON() (LPC_GPIO2->DATA &=~(1<<7))
#define LED8_OFF() (LPC_GPIO2->DATA |=(1<<7))
//led初始化
void LedInit (void)
{LPC_SYSCON->SYSAHBCLKCTRL|=(1<<16);
	LPC_IOCON->PIO2_0&=~0x07;
	LPC_IOCON->PIO2_1&=~0x07;
	LPC_IOCON->PIO2_2&=~0x07;
	LPC_IOCON->PIO2_3&=~0x07;
	LPC_IOCON->PIO2_4&=~0x07;
	LPC_IOCON->PIO2_5&=~0x07;
	LPC_IOCON->PIO2_6&=~0x07;
	LPC_IOCON->PIO2_7&=~0x07;
	LPC_SYSCON->SYSAHBCLKCTRL&=~(1<<16);
	LPC_SYSCON->SYSAHBCLKCTRL|=(1<<6);
	
	 LPC_GPIO2->DIR |=(1<<0);
	LPC_GPIO2->DATA |=(1<<0);
		LPC_GPIO2->DIR |=(1<<1);
	LPC_GPIO2->DATA |=(1<<1);
		LPC_GPIO2->DIR |=(1<<2);
	LPC_GPIO2->DATA |=(1<<2);
		LPC_GPIO2->DIR |=(1<<3);
	LPC_GPIO2->DATA |=(1<<3);
		LPC_GPIO2->DIR |=(1<<4);
	LPC_GPIO2->DATA |=(1<<4);
		LPC_GPIO2->DIR |=(1<<5);
	LPC_GPIO2->DATA |=(1<<5);
		LPC_GPIO2->DIR |=(1<<6);
	LPC_GPIO2->DATA |=(1<<6);
		LPC_GPIO2->DIR |=(1<<7);
	LPC_GPIO2->DATA |=(1<<7);
}
//32定时器初始化
void T32B1_Init_Init(void)
{
LPC_SYSCON->SYSAHBCLKCTRL|=(1<<10);
	LPC_TMR32B1->IR=0x01;
		LPC_TMR32B1->MCR=0x04;
}
//32wei延时
void T32B1_DelayMs(uint16_t ms)
{
	LPC_TMR32B1->TCR=0x02;
		LPC_TMR32B1->PR=0;
	LPC_TMR32B1->MR0=ms*(SystemCoreClock/1000);
	LPC_TMR32B1->TCR=0x01;
	while(	LPC_TMR32B1->TCR&0x01);
}
int main()
{
  LedInit ();
	T32B1_Init_Init ();
	while(1)
	{
	  T32B1_DelayMs(500);
		LED1_ON();
		T32B1_DelayMs(500);
		LED1_OFF();	
		T32B1_DelayMs(500);
		LED2_ON();
		T32B1_DelayMs(500);
		LED2_OFF();	
  	T32B1_DelayMs(500);
		LED3_ON();
		T32B1_DelayMs(500);
		LED3_OFF();			
	  T32B1_DelayMs(500);
		LED4_ON();
		T32B1_DelayMs(500);
		LED4_OFF();			
  	T32B1_DelayMs(500);
		LED5_ON();
		T32B1_DelayMs(500);
		LED5_OFF();			
  	T32B1_DelayMs(500);
		LED6_ON();
		T32B1_DelayMs(500);
		LED6_OFF();			
		T32B1_DelayMs(500);
		LED7_ON();
		T32B1_DelayMs(500);
		LED7_OFF();		
		T32B1_DelayMs(500);
		LED8_ON();
		T32B1_DelayMs(500);
		LED8_OFF();	
		
		
		
		
		
		
		
		
	}


}




