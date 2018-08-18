/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0, the teeth button ladder:
  int teethButtons = analogRead(A0);
  int tButton = map((teethButtons+50), 0, 900, 0, 6); //+
  Serial.print("rawTeeth: \t");
  Serial.print(teethButtons);
  Serial.print("\ttooth: \t");
  Serial.print(tButton);


  // read the input on analog pin 1, the voltage of the battery
  int rawVoltage = analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 4.2 V):
  float voltage = rawVoltage * (5.0 / 1023.0);
  Serial.print("\t\trawVoltage: \t");
  Serial.print(rawVoltage);
  Serial.print("\t\tVoltage: \t");
  Serial.println(voltage);


/*
 * for getting voltage
 * int value = analogRead(pin);
 * float voltage = map(value, 0,1023,0,50) / 10.0); (maps 5v to 50 increaments, then divides by 10 for 1 dec place)
 * 
 * Serial.print( voltage );
 * 
 * */


}
