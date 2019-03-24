#include <Arduino.h>
#include <intmap.h>

double n ;
unsigned long time;
const int number = 10000;

void measueStart(char* sz)
{
	Serial.println(sz);
	time = micros();
}

void measureStop(char* sz){
	unsigned long span = micros() - time;
	Serial.print(sz);
	Serial.println(span);
}

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	randomSeed(analogRead(0)); // 未接続ピンのノイズを利用
	
	// Serial.begin(9600);
    // Serial.println(pow(2,16));
    // n = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2.0*2.0; 
    // Serial.println(n);
}

void loop() {
	IntMap intmap(0, 180, 500, 2400);

	measueStart("map");
	for (int i=0; i<number; ++i) {
		int n = map(i, 0, 180, 500, 2400);
	}
	measureStop("map: ");

	measueStart("intmap");
	for (int i=0; i<number; ++i) {
		int n = intmap.Value(i);
	}
	measureStop("intmap: ");
	
	/*
	// put your main code here, to run repeatedly:
	time = micros();
	Serial.println(time);
	Serial.print("pow 2^16 ");
	for (int i = 0; i<10; i++){
		double n = pow(2,16);
	}
	Serial.println(micros()- time);
	time = micros();
	Serial.println(micros());
	Serial.print("1/ (pow 2^16) ");
	for (int i = 0; i<10; i++){
		double n = 1 / pow(2,16);
	}
	Serial.println(micros()- time);
	time = micros();
	Serial.println(micros());
	Serial.print("2^16 ");
	for (int i = 0; i<10; i++){
		double n = 2*2*2*2*2*2*2*2*2*2*2*2*2*2*2.0*2.0;
	}
	Serial.println(micros()- time);
	time = micros();
	Serial.println(micros());
	Serial.print("1/2^16 ");
	for (int i = 0; i<10; i++){
		double n = 1/(2*2*2*2*2*2*2*2*2*2*2*2*2*2*2.0*2.0);
	}
	Serial.println(micros()- time);
	Serial.println("----------------");
	*/
	
	Serial.println("----------------");
	delay(2000);
}