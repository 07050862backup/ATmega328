void setup() {

    DDRB=B11111100;//pin 13 ~ 10 is in output mode


}
void loop() {
    
    PORTB=B11101000;
	delay(1000);
	PORTB=B11010100; 
	delay(1000);
	
   

}

