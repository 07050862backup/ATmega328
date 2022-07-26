/*EX-02

3個按鈕 + 8個LED
    完成以下功能
    按鈕001，右旋跑馬燈
    按鈕010，左旋跑馬燈
    按鈕100，霹靂燈
    按鈕110，單數及偶數LED交替閃爍*/

byte shift = 0;
void setup()
{
  //Serial.begin(9600);

  
  DDRD = B11111111;//DDRD是決定pinD0~pinD7是否輸出
  DDRB = B11000000;//DDRB是決定pinD8~pinD13是否為輸出
         
  //PORTB = LEDs[index1];//PORTD讀取pinD8~pinD13的值決定是高電壓還是低電壓
  //PORTD = LEDs2[index2];//PORTB讀取pinD0~pinD7的值決定是高電壓還是低電壓
  
  PORTD = B00000000;
}

void loop()
{
    if ((PINB & B00111000)==8)  //按鈕001，右旋跑馬燈
    {
        Serial.println("001");
      
        PORTD = B10000000 >> shift;
        shift =  ++shift %8 ;
        delay(500);

	}
	else if ((PINB & B00111000)==16)//按鈕010，左旋跑馬燈
    {
        Serial.println("010");
      
        PORTD = B00000001 << shift;
        shift =  ++shift %8 ;
        delay(500);
        
	}
    else if ((PINB & B00111000)==32)//按鈕100，霹靂燈
    {   
        shift=0;
        PORTD = B00000000;
        delay(500);
    
        PORTD = B10000000;
         delay(500);
        PORTD = B11000000;
        delay(500);
      
      
        for(int i = 0 ; i < 5;i++)
        {
            PORTD = B11100000 >> shift++;
            shift%=8;
             delay(500);
        }
      PORTD = B00000011;
       delay(500);
      PORTD = B00000001;
       delay(500);
      PORTD = B00000011;
       delay(500);
      shift=0;
      for(int i = 0 ; i < 5;i++)
        {
            PORTD = B00000111 << shift++;
            shift%=8;
             delay(500);
        }
      PORTD = B11000000;
      delay(500);
      PORTD = B10000000;
      delay(500);
		
	}
    else if ((PINB & B00111000)==48)//按鈕110，單數及偶數LED交替閃爍
    {
        Serial.println("110");
      
        PORTD = B10101010 ;
        delay(500);
        PORTD = B01010101 ;
        delay(500);
	}
     else
     {
    PORTD = B00000000;
     }
  
  
  
  /*兩顆右旋
  for(int i = 0 ; i < 7;i++)
        {
            PORTD = B11000000 >> shift++;
            shift%=8;
            delay(1000);
        }
        shift=0;
        PORTD = B10000001;
        delay(1000);
  
  */
 
  
    
}