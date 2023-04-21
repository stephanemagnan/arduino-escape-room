/*
ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
*/
int thisA0;
int thisA1;
int thisA2;
int thisA3;
int thisA4;
int thisA5;
int thisA6;
int thisA7;

int lastA0;
int lastA1;
int lastA2;
int lastA3;
int lastA4;
int lastA5;
int lastA6;
int lastA7;

bool stateA0 = true;
bool stateA1 = true;
bool stateA2 = true;
bool stateA3 = true;
bool stateA4 = true;
bool stateA5 = true;
bool stateA6 = true;
bool stateA7 = true;

int wires_cut = 0;
int cutA0 = 1;
int cutA1 = 2;
int cutA2 = 3;
int cutA3 = 4;
int cutA4 = 5;
int cutA5 = 6;
int cutA6 = 7;
int cutA7 = 8;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  lastA0 = analogRead(A0);
  lastA1 = analogRead(A1);
  lastA2 = analogRead(A2);
  lastA3 = analogRead(A3);
  lastA4 = analogRead(A4);
  lastA5 = analogRead(A5);
  lastA6 = analogRead(A6);
  lastA7 = analogRead(A7);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  thisA0 = analogRead(A0);
  thisA1 = analogRead(A1);
  thisA2 = analogRead(A2);
  thisA3 = analogRead(A3);
  thisA4 = analogRead(A4);
  thisA5 = analogRead(A5);
  thisA6 = analogRead(A6);
  thisA7 = analogRead(A7);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
 
  // print out the value you read:
//  Serial.print(thisA0);
//  Serial.print(" ");
//  Serial.print(thisA1);
//  Serial.print(" ");
//  Serial.print(thisA2);
//  Serial.print(" ");
//  Serial.print(thisA3);
//  Serial.print(" ");
//  Serial.print(thisA4);
//  Serial.print(" ");
//  Serial.print(thisA5);
//  Serial.print(" ");
//  Serial.print(thisA6);
//  Serial.print(" ");
//  Serial.print(thisA7);
//  Serial.println("");

  int upper_thresh = 1020;
  int lower_thresh = 1000;
  if (lastA0 > upper_thresh && thisA0<lower_thresh && stateA0){
    stateA0 = false;
    Serial.println("A0 lost");
    wires_cut = wires_cut+1;
    if( wires_cut!=cutA0){
      Serial.println("Penalty");
    }
  }
  if (lastA1 > upper_thresh && thisA1<lower_thresh && stateA1){
    stateA1 = false;
    wires_cut = wires_cut+1;
    Serial.println("A1 lost");
    if( wires_cut!=cutA1){
      Serial.println("Penalty");
    }
  }
  if (lastA2 > upper_thresh && thisA2<lower_thresh && stateA2){
    stateA2 = false;
    wires_cut = wires_cut+1;
    Serial.println("A2 lost");
    if( wires_cut!=cutA2){
      Serial.println("Penalty");
    }
  }
  if (lastA3 > upper_thresh && thisA3<lower_thresh && stateA3){
    stateA3 = false;
    wires_cut = wires_cut+1;
    Serial.println("A3 lost");
    if( wires_cut!=cutA3){
      Serial.println("Penalty");
    }
  }
  if (lastA4 > upper_thresh && thisA4<lower_thresh && stateA4){
    stateA4 = false;
    wires_cut = wires_cut+1;
    Serial.println("A4 lost");
    if( wires_cut!=cutA4){
      Serial.println("Penalty");
    }
  }
  if (lastA5 > upper_thresh && thisA5<lower_thresh && stateA5){
    stateA5 = false;
    wires_cut = wires_cut+1;
    Serial.println("A5 lost");
    if( wires_cut!=cutA5){
      Serial.println("Penalty");
    }
  }
  if (lastA6 > upper_thresh && thisA6<lower_thresh && stateA6){
    stateA6 = false;
    wires_cut = wires_cut+1;
    Serial.println("A6 lost");
    if( wires_cut!=cutA6){
      Serial.println("Penalty");
    }
  }
  if (lastA7 > upper_thresh && thisA7<lower_thresh && stateA7){
    stateA7 = false;
    wires_cut = wires_cut+1;
    Serial.println("A7 lost");
    if( wires_cut!=cutA7){
      Serial.println("Penalty");
    }
  }


  lastA0 = thisA0;
  lastA1 = thisA1;
  lastA2 = thisA2;
  lastA3 = thisA3;
  lastA4 = thisA4;
  lastA5 = thisA5;
  lastA6 = thisA6;
  lastA7 = thisA7;
  
}
