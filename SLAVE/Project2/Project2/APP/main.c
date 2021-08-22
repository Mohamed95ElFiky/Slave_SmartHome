/*
 * main.c
 *
 * Created: 6/25/2021 10:50:38 PM
 *  Author: nereen elbagoury
 */

//Macros - including header files
#include "../MCAL/UART.h"
#include "../HAL/InOut.h"
#include "../HAL/LED.h"
#include "../HAL/LCD.h"
#include "../MCAL/SPI.h"

int main(void)
	
{	
	//Initializations:
	LED0_Initialization();	//function that initializes led 0 [setting pin direction]
	LED1_Initialization();	//function that initializes led 1 [setting pin direction]
	LED2_Initialization();	//function that initializes led 2 [setting pin direction]
	Relay_Initialization();	//function that initializes relay [setting relay pin direction]
	Buzzer_Initialization();  //function that initializes buzzer [setting buzzer pin direction]
	LCD_Initialization();    //function that initializes LCD [defining pins direction for control pins and data pins, checking mode]
	UART_Init();	        //setting baud rate, enabling Transmitter and Receiver bits, configuration for UART, baud rate calculation]
	SPI_Init();				//defining direction pins for [MOSI, MISO, CLK and SS]
	
	
	LCD_String("Smart Home");   //function that displays the comment "smart home" on LCD at start of system
	u8 data_received;           // uninitialized global variable to store data received by SPI
  
	while(1)
	
{  
	data_received = SPI_Receive();  //assigning received data from SPI to this variable [data coming from master to slave]
	
	if(data_received == '1')     //in case data received from SPI is '1'
	{	
		LCD_Clear();			//function clears the LCD to display next comment   
		LCD_String("ROOM 1");  //function to display the comment 'ROOM 1' on LCD   
		LED0_TGL();			//function lets LED0 toggle its value [if '1'received from SPI then open LED0, if '1' received again then turn off LED0]
		buzzer_ring();      //function that lets buzzer give a short ring with every action for 1 sec.
	} 
	
	else if(data_received == '2')    //in case data received from SPI is '2'
	{	
		LCD_Clear();                //function clears the LCD to display next comment   
		LCD_String("ROOM 2 ");     //function to display the comment 'ROOM 2' on LCD   
		LED1_TGL();        //function lets LED1 toggle its value [if '2'received from SPI then open LED1, if '2' received again then turn off LED1]
		buzzer_ring();      //function that lets buzzer give a short ring with every action for 1 sec.	
	}
	else if(data_received == '3')   //in case data received from SPI is '3'
	{	
		LCD_Clear();               //function clears the LCD to display next comment   
		LCD_String("ROOM 3");      //function to display the comment 'ROOM 3' on LCD   
		LED2_TGL();        //function lets LED2 toggle its value [if '3'received from SPI then open LED2, if '3' received again then turn off LED2]
		buzzer_ring();       //function that lets buzzer give a short ring with every action for 1 sec.
	}
	else if(data_received == '4')     //in case data received from SPI is '4'
	{
		LCD_Clear();                 //function clears the LCD to display next comment   
		LCD_String("OPEN DOOR");   //function to display the comment 'OPEN DOOR' on LCD   
		Relay_TGL();      //function lets relay toggle its value [if '4'received from SPI then open relay, if '4' received again then turn off relay]
	   buzzer_ring();           //function that lets buzzer give a short ring with every action for 1 sec.
	}
	else
	{
		LCD_String("Wrong Data Received");//function to display the comment 'Wrong Data Received' on LCD
	}
	   	
}
	
} 







