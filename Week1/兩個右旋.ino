void setup() {

    DDRB=B11111100;//pin 13 ~ 10 is in output mode


}
void loop() {
	PORTB=B11110000; 
	delay(1000);
	PORTB=B11011000;
	delay(1000);
    PORTB=B11001100;
	delay(1000);
    PORTB=B11100100;
	delay(1000);

}

