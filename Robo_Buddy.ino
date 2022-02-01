#include "pitches.h"
#include "Servo.h"

Servo servoMotor; 
int servoPin = 3;

int melody1[]{ 
  NOTE_D5, NOTE_A5, NOTE_FS5, NOTE_D5,
  NOTE_E5, NOTE_FS5,8, NOTE_G5,
  NOTE_FS5, NOTE_E5, NOTE_FS5,
  NOTE_D5,
  NOTE_D5, NOTE_A5,
    };

int melody2[]{ 
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5,
  NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C4, 
  NOTE_E4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_GS4, 
  NOTE_B4, NOTE_C5
    };

int melody3[]{ 
  NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, 
  NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, 
  NOTE_DS4, NOTE_F4, NOTE_G4
    };

int melody4[]{ 
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_E5, 
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_FS4, NOTE_G4,
  NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_E5, 
  NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, 
  NOTE_DS4
    };

//13 notes
int noteDurations1[] = {4, 8, 8, 8, 4, 8, 4, 4, 8, 4, 2, 4, 8};
int noteDurations2[] = {8, 8, 8, 8, 8, 4, 8, 8, 4, 8, 8, 8, 2, 8, 8, 8, 2};
int noteDurations3[] = {4, 4, 8, 8, 4, 4, 8, 8, 4, 4, 8, 8, 4};
int noteDurations4[] = {8, 16, 8, 8, 8, 8, 8, 8, 8, 8, 8, 16, 8, 8, 8, 8, 8, 8, 2, 8, 1};
void setup() {
  // put your setup code here, to run once:
//servo motor
  Serial.begin(96000);
  servoMotor.attach(servoPin);

  //buttons for sound
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  //led lights
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

 //sound and lights 
  if(digitalRead(A0) == HIGH){
    for(int thisNote = 0; thisNote<13; thisNote++){
      int noteDuration = 1000/noteDurations1[thisNote];
      tone(8, melody1[thisNote], noteDuration);
      delay(noteDuration+30);

//when jigglypuff theme is playing, first light is on
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);

//the robot turns 90 degrees while jiggly puff song is playing
    servoMotor.write(90);
    }
  }
  if(digitalRead(A1) == HIGH){
    for(int thisNote = 0; thisNote<17; thisNote++){
    int noteDuration = 1000/noteDurations2[thisNote];
    tone(8, melody2[thisNote], noteDuration);
    delay(noteDuration+30);

    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);

    servoMotor.write(180);
    }
  }
  if(digitalRead(A2) == HIGH){
    for(int thisNote = 0; thisNote<13; thisNote++){
    int noteDuration = 1000/noteDurations3[thisNote];
    tone(8, melody3[thisNote], noteDuration);
    delay(noteDuration+30);

    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);

    servoMotor.write(90);
    }
  }
  if(digitalRead(A3) == HIGH){
    for(int thisNote = 0; thisNote<21; thisNote++){
    int noteDuration = 1000/noteDurations4[thisNote];
    tone(8, melody4[thisNote], noteDuration);
    delay(noteDuration+30);

    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);

    servoMotor.write(180);
    }
  }
  else{
    noTone(8);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);

    servoMotor.write(0);
  }
}
}
