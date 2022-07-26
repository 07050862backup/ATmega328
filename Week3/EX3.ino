/*1. 設置一個指撥開關於Arduino D2，設置一個LED於D7，當指撥由0撥至1時，改變LED狀態1	次。
  2. 設置一個指撥開關於Arduino D3，設置一個LED於D6，當指撥由1撥至0時，改變LED狀態1	次。
  3. 設置一個指撥開關於Arduino D8，設置一個LED於D5，當指撥狀態改變時(由1撥至0 或 由0撥至1)，改變LED狀態1次。
*/
#include <avr/io.h>
#include <avr/interrupt.h>
void setup(){
  
  
    DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
    PORTD |= (1 << PORTD2);    // turn On the Pull-up
    // PD2 is now an input with pull-up enabled
  /****************************************************/
    DDRD &= ~(1 << DDD3);     // Clear the PD3 pin
    PORTD |= (1 << PORTD3);    // turn On the Pull-up
    // PD3 is now an input with pull-up enabled
  /****************************************************/
    DDRB &= ~(1 << DDB0);     // Clear the PB0(pin8) pin
    PORTB |= (1 << PORTB0);    // turn On the Pull-up
    // PB0 is now an input with pull-up enabled
  /****************************************************/
  
   /*tips1:   D2-->INT0   EIMSK之INT0設為1*/
   /*功能:  (正緣觸發) EICRA之  ISC00  設為1
                     EICRA之  ISC01  設為1*/
    EIMSK |= (1 << INT0);     // Turns on INT0
    EICRA |= (1 << ISC00);    // set INT0 to trigger on ANY logic change
    EICRA |= (1 << ISC01);    // set INT0 to trigger on ANY logic change
   /*tips2:   D3-->INT1   EIMSK之INT1設為1*/
   /*功能:  (負緣觸發) EICRA之  ISC10  設為0
                     EICRA之  ISC11  設為1*/
    EIMSK |= (1 << INT1);     // Turns on INT1
    EICRA &= ~(1 << ISC10);
    EICRA |= (1 << ISC11);    // set INT1 to trigger on ANY logic change
  /*tips3:   D8-->PCINT0   PCMSK0之PCINT0設為1，且PCICR之PCIE0設為1*/
    PCMSK0 |= (1 << PCINT0);   // set PCINT0 to trigger an interrupt on state change   
    PCICR  |= (1 << PCIE0);     // set PCIE0 to enable PCMSK0 scan
  

  
    sei();                    // turn on interrupts
  
  

  
  DDRD |= (1<<DDB5) ;//pin 13 is in output mode
  DDRD |= (1<<DDB6) ;//pin 12 is in output mode
  DDRD |= (1<<DDB7) ;//pin 11 is in output mode


}

void loop()
{
}

ISR (INT0_vect)
{
     PORTD ^=(1<< PORTD5);//make pin 13 high and power on the led
}
ISR (INT1_vect)
{ 
     PORTD ^=(1<< PORTD6);//make pin 13 high and power on the led
}
ISR (PCINT0_vect)
{
    PORTD ^=(1<< PORTD7);//make pin 13 high and power on the led
}