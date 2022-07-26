void setup() {

    DDRB=B11111100;//pin 13 ~ 10 is in output mode


}
void loop() {
	PORTB=B11100000; 
	delay(1000);
	PORTB=B11010000;
	delay(1000);
    PORTB=B11001000;
	delay(1000);
    PORTB=B11000100;
	delay(1000);

}

