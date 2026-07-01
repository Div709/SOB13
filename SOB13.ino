/* SOB 13
HC-06  arduino
VCC---> 5V
GND--->GND
TXD--->D2
RXD--->D3
*/
int led =9;
#include "SoftwareSerial.h"
// Using software serial port, can speak digital port analog into serial port
SoftwareSerial BT(4, 5);  //BT(rx,tx)
char val;  //Store received variables
 
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);   //Serial Port Connection with Computer
  Serial.println("BT Module is ready!");
  BT.begin(9600);  //set baud rate
 delay(3000); //delay 5000ms
  BT.print("AT"); //Send AT.
}
 
void loop() {
  //If the serial port receives the data, it outputs it to the Bluetooth serial port.
  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
  }
 
  //If the Bluetooth module data is received, it is output to the screen.
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
    
    if (val=='1')
    {
     digitalWrite(led, HIGH);
    
    }
    else if (val=='0')
    {
     digitalWrite(led, LOW); 
     
    } 
    
  }
}
