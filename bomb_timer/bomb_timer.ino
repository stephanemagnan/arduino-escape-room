#include "SevSeg.h"
SevSeg sevseg; //Initiate a seven segment controller object

//Refs 
//https://github.com/DeanIsMe/SevSeg

// Wiring diagram for Arduino UNO/NANO
//   Pins of 3641AS when looking at front of display
//Top Row:    1 A F  2 3 B
//Bottom Row: E D DP C G 4
// D2: 1 (through 330 Ohm resistor)
// D3: 2 (through 330 Ohm resistor)
// D4: 3 (through 330 Ohm resistor)
// D5: 4 (through 330 Ohm resistor)
// D6: A
// D7: B
// D8: C
// D9: D
// D10: E
// D11: F
// D12: G
// D13: DP


// Initialize 3641AS +Cathode 4x7 Segment Display
int mins;
int secs;
unsigned long start_time;
unsigned long this_time;
unsigned long last_time;
unsigned long time_step = 1000;
bool game_over = false;
bool keep_counting = false;

// Initialize analog continuity portion
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
int penalty_count = 0;

int upper_thresh = 1020;
int lower_thresh = 1000;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
  byte numDigits = 4;  
  byte digitPins[] = {2, 3, 4, 5}; // 1 2 3 4
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; // A B C D E F G DP
  bool resistorsOnSegments = 0; 
  // variable above indicates that 4 resistors were placed on the digit pins.
  // set variable to 1 if you want to use 8 resistors on the segment pins.
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(120);
  
  //Initialize countdown times
  mins = 45;
  secs = 00;
  last_time = millis();
  sevseg.setNumber(mins*100+secs,2);

  // Initialize wire states
  lastA0 = analogRead(A0);
  lastA1 = analogRead(A1);
  lastA2 = analogRead(A2);
  lastA3 = analogRead(A3);
  lastA4 = analogRead(A4);
  lastA5 = analogRead(A5);
  lastA6 = analogRead(A6);
  lastA7 = analogRead(A7);
}
void loop() {
   // Read all the latest sensor statuses
  thisA0 = analogRead(A0);
  thisA1 = analogRead(A1);
  thisA2 = analogRead(A2);
  thisA3 = analogRead(A3);
  thisA4 = analogRead(A4);
  thisA5 = analogRead(A5);
  thisA6 = analogRead(A6);
  thisA7 = analogRead(A7);

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

// check to see if any of the wires were cut since the previous iteration
  if (lastA0 > upper_thresh && thisA0<lower_thresh && stateA0){
    stateA0 = false;
    Serial.println("A0 lost");
    wires_cut = wires_cut+1;
    if( wires_cut!=cutA0){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA1 > upper_thresh && thisA1<lower_thresh && stateA1){
    stateA1 = false;
    wires_cut = wires_cut+1;
    Serial.println("A1 lost");
    if( wires_cut!=cutA1){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA2 > upper_thresh && thisA2<lower_thresh && stateA2){
    stateA2 = false;
    wires_cut = wires_cut+1;
    Serial.println("A2 lost");
    if( wires_cut!=cutA2){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA3 > upper_thresh && thisA3<lower_thresh && stateA3){
    stateA3 = false;
    wires_cut = wires_cut+1;
    Serial.println("A3 lost");
    if( wires_cut!=cutA3){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA4 > upper_thresh && thisA4<lower_thresh && stateA4){
    stateA4 = false;
    wires_cut = wires_cut+1;
    Serial.println("A4 lost");
    if( wires_cut!=cutA4){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA5 > upper_thresh && thisA5<lower_thresh && stateA5){
    stateA5 = false;
    wires_cut = wires_cut+1;
    Serial.println("A5 lost");
    if( wires_cut!=cutA5){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA6 > upper_thresh && thisA6<lower_thresh && stateA6){
    stateA6 = false;
    wires_cut = wires_cut+1;
    Serial.println("A6 lost");
    if( wires_cut!=cutA6){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
      Serial.println("Penalty");
    }
  }
  if (lastA7 > upper_thresh && thisA7<lower_thresh && stateA7){
    stateA7 = false;
    wires_cut = wires_cut+1;
    Serial.println("A7 lost");
    if( wires_cut!=cutA7){
      penalty_count = penalty_count+1;
      time_step = 0.75*time_step;
      if(mins>0){
        mins = mins-1;
      }else if(secs>0){
        secs=secs-5;
      }
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

  if(stateA0 || stateA1 || stateA2 || stateA3 || stateA4 || stateA5 || stateA6 || stateA7){
    
    this_time = millis();
    if (this_time-last_time>=time_step){
      if (secs == 0){
        if (mins != 0){
          secs = 59;
          mins = mins-1;
        }
        else{
          //flash screen
          while (true){
            sevseg.setNumber(0, 2);
            sevseg.refreshDisplay();
                    
          }
        }
      }
      else{
        secs = secs-1;
      }
      last_time = this_time;
    }

    sevseg.setNumber(mins*100+secs, 2);
    sevseg.refreshDisplay(); // Must run repeatedly
  }
  else{
   while (true){
    sevseg.setNumber(mins*100+secs, 2);
    sevseg.refreshDisplay();
           
  }
  }
}
