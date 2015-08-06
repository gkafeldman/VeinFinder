/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13.
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

 * Note: because most Arduinos have a built-in LED attached
 to pin 13 on the board, the LED is optional.


 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe

 This example code is in the public domain.

 http://arduino.cc/en/Tutorial/AnalogInput

 */

int pwm = 13; // assigns pin 12 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int t1 = 0;   // declares variable t1
int t2 = 0;   // declares variable t2

void setup()  // setup loop
{
  pinMode(pwm, OUTPUT); // declares pin 12 as output
  pinMode(pot, INPUT);  // declares pin A0 as input
}

void loop()
{
  t2= analogRead(pot); // reads the voltage at A0 and saves in t2
  t1= 1000-t2;         // subtracts t2 from 1000 ans saves the result in t1
  digitalWrite(pwm, HIGH); // sets pin 12 HIGH
  delayMicroseconds(t2);   // waits for t1 uS (high time)
  digitalWrite(pwm, LOW);  // sets pin 12 LOW
  if (t1 > 1000)
    t1 = 0;
  delayMicroseconds(t1);   // waits for t2 uS (low time)
}
