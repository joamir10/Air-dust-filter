#define measurePin 0 //Connect dust sensor to Arduino A0 pin
#define ledPower 7   //Connect 3 led driver pins of dust sensor to Arduino D2
#define measurePin1 1 //Connect dust sensor to Arduino A0 pin
#define ledPower1 8   //Connect 3 led driver pins of dust sensor to Arduino D2
int samplingTime = 280; // time required to sample signal coming out of the sensor
int deltaTime = 40; //
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
float voMeasured1 = 0;
float calcVoltage1 = 0;
float dustDensity1 = 0;
float percent = 0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
  pinMode(ledPower1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(ledPower,LOW); // power on the LED
 digitalWrite(ledPower1,LOW);
   (samplingTime);
  voMeasured = analogRead(measurePin); // read the dust value
  voMeasured1 = analogRead(measurePin1); 
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  digitalWrite(ledPower1,HIGH);
  delayMicroseconds(sleepTime);
  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 170 * calcVoltage - 0.1;
  calcVoltage1 = voMeasured1 * (5.0 / 1024.0);
  dustDensity1 = 170 * calcVoltage1 - 0.1;
  percent = ((dustDensity - dustDensity1) / dustDensity) * 100;
Serial.print("dustDensity1= ");  
Serial.print(dustDensity);
Serial.print("  dustDensity2= ");  
Serial.print(dustDensity1);
Serial.print(" Filteration percent = ");  
Serial.print(percent);
Serial.println("%");
delay(1000);
}
