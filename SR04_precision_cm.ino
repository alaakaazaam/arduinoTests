/*
  HC-SR04 Ultrasonic Distance Sensor with Arduino Example Code
  More info: https://www.makerguides.com
*/
//Define Trig and Echo pin
#define trigPin 12
#define echoPin 11

//Define variables
long duration;
int distance;

void setup()
{
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Begin Serial communication
  Serial.begin(9600); // Starts the serial communication at a baudrate of 9600
}
void loop()
{
  //Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  //Trigger the sensor by setting the trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds.
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance, rappel le son va à 340 M/s soient 34000cm/s = 34000*10-6 en une microseconde = 34^10(3) / 10(6)
  //  = 34 * 10^(-3) = 0.034 cm/microSeconde
  distance = duration * 0.034 / 2;
  //Print the distance on the Serial Monitor (Ctrl+Shift+M)
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);
}
