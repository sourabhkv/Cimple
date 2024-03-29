//10-bit internal ADC 
//AIN0 pin is selected 
//you can change the channel by changing PINSEL1 and ADCR value	   //Date:11/11/2011

#include <lpc214x.h>
#include <Stdio.h> 

void lcd_init(void);
void wr_cn(void);
void clr_disp(void);
void delay(unsigned int);
void lcd_com(void);						   
void wr_dn(void);
void lcd_data(void);

unsigned int data_lcd=0;
unsigned int adc_value=0,temp_adc=0,temp1,temp2;
float temp;
char var[15],var1[15];
char *ptr,arr[]= "ADC O/P= ";
char *ptr1,dis[]="A I/P  = ";

#define vol 3.3               	//Reference voltage
#define fullscale 0x3ff         //10 bit adc

int main()
{					   
	PINSEL1 = 0X00040000;   	//AD0.4 pin is selected(P0.25)
  IO0DIR = 0x000000FC;    	//configure o/p lines for lcd  
	
	delay(3200);
	lcd_init();	 				//LCD initialization  
  delay(3200);
	clr_disp();	 				//clear display
	delay(3200);				//delay

	ptr = dis;
	temp1 = 0x80;				//Display starting address	of first line 1 th pos
	lcd_com();
	delay(800); 

  while(*ptr!='\0')
   {
   	 temp1 = *ptr;
     lcd_data();
		 ptr ++;
	 } 

	ptr1 = arr;
	temp1 = 0xC0;				//Display starting address of second line 4 th pos
	lcd_com();
	delay(800); 
        
	while(*ptr1!='\0')
   {
     temp1 = *ptr1;
     lcd_data();
		 ptr1 ++;
	 }

    //infinite loop	
    while(1)
     {			 
		   //CONTROL register for ADC
		   AD0CR = 0x01200010;       			//command register for ADC-AD0.4
	  
		   while(((temp_adc = AD0GDR) &0x80000000)  == 0x00000000);	//to check the interrupt bit
		
		   adc_value = AD0GDR;          		//reading the ADC value
		   adc_value >>=6;
		   adc_value &= 0x000003ff;
		   temp = ((float)adc_value * (float)vol)/(float)fullscale;
		   sprintf(var1,"%4.2fV",temp);
		   sprintf(var,"%3x",adc_value); 		
		
	     temp1 = 0x89;
	 	   lcd_com();
	 	   delay(1200); 
	 	   ptr = var1;
        
		   while(*ptr!='\0')
        {	        
  			  temp1=*ptr;
			    lcd_data();	
          ptr++;
		    } 
                 
       temp1 = 0xc9;
       lcd_com();
       delay(1200);
						
       ptr1 = var;
       while(*ptr1!='\0')
        {	 	
        	temp1=*ptr1;
	    		lcd_data();
          ptr1++;
		    }       
	    }	 // end of while(1)		
} //end of main()
  
//lcd initialization
void lcd_init()
{
	temp2=0x30;		   
	wr_cn();
	delay(800); 
	
	temp2=0x30;
	wr_cn();
	delay(800);	 
		
	temp2=0x30;
	wr_cn();
	delay(800);

	temp2=0x20;
	wr_cn();
	delay(800);

	temp1 = 0x28;
	lcd_com();
	delay(800);
		
	temp1 = 0x0c;		
	lcd_com();
	delay(800);
	
	temp1 = 0x06;
	lcd_com();
	delay(800);
	
	temp1 = 0x80;
	lcd_com();
	delay(800);
}

void lcd_com(void)
{
	temp2= temp1 & 0xf0;
	wr_cn();
	temp2 = temp1 & 0x0f;
	temp2 = temp2 << 4; 
	wr_cn();
    delay(500);
}

// command nibble o/p routine
void wr_cn(void)                // write command reg
{ 	 
	IO0CLR  = 0x000000FC;		// clear the port lines.
	IO0SET 	= temp2;			// Assign the value to the PORT lines    
	IO0CLR  = 0x00000004;		// clear bit  RS = 0
	IO0SET 	= 0x00000008;   	// E=1
	delay(10);
	IO0CLR  = 0x00000008;
}

// data nibble o/p routine
void wr_dn(void)
{  	  
	IO0CLR  = 0x000000FC;		// clear the port lines.
	IO0SET = temp2;				// Assign the value to the PORT lines 
	IO0SET = 0x00000004;   		// set bit  RS = 1 	
	IO0SET = 0x00000008;   		// E=1
	delay(10);
	IO0CLR = 0x00000008;
}

// data o/p routine which also outputs high nibble first
// and lower nibble next
void lcd_data(void)
{  
	temp2 = temp1 & 0xf0;
  wr_dn();
  temp2= temp1 & 0x0f;	
	temp2= temp2 << 4;
  wr_dn();
  delay(100);					
} 

void delay(unsigned int r1)
{
 	unsigned int r;
 	for(r=0;r<r1;r++);
}
void clr_disp(void)
{
	temp1 = 0x01;
	lcd_com();
 	delay(500);
}
	  
