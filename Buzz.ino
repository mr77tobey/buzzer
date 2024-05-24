#include "pitches.h"
#define BUTTON 6
#define A0 0
#define A1 441
#define A2 495
#define A3 556
#define A4 589
#define A5 661
#define A6 742

#define AL1 221
#define AL2 248
#define AL3 278
#define AL4 294
#define AL5 330
#define AL6 371
#define AL7 416

#define AH1 882
#define AH2 990
#define AH3 1112
#define AH4 1178
#define AH5 1322
#define AH6 1484
#define AH7 1665
 
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

int melody1[] = {
  NOTE_B4, NOTE_B4, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5
};
int melody2[] = {
  A0,A0,A0,A3,A5,
A6,A0,A0,A5,A6,A0,A0,A5,
A6,AH1,A5,A6,A3,A0,A3,A5,
A6,A0,A0,A5,A6,A0,A0,A5,
A6,AH3,AH1,AH2,A6,A0,A3,A5,
A6,A0,A0,A5,A6,A0,A0,A5,
A6,AH1,A5,A6,A3,A5,A1,A2,
A3,AH1,A6,AH3,
AH2,AH3,AH2,AH1,AH2,A6,A0,
A6,A6,A6,A6,AH1,AH2,AH3,
A6,A6,A6,A5,A5,A6,
A6,A6,A6,A6,AH1,AH2,AH3,
A6,A6,A6,AH4,AH4,AH3,
A6,A6,A6,A6,AH1,AH2,AH3,
A6,A6,A6,A5,A5,A6,
A6,A6,A6,A6,AH1,AH2,AH3,
AH6,A5,A5,A6,A6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 8, 4,
};
float tuneNoteDurations[]={
  1,1,1,0.5,0.5,
  0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
   0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
    0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
     0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
      0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
       0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
       1,1,1,1,
       0.5,0.25,0.25,0.5,0.5,1,1,
       1,1,1,0.25,0.25,0.25,0.25,
       1,1,1,0.5,0.5,0.5,0.5,
       1,1,1,0.25,0.25,0.25,0.25,
       1,1,0.5,0.5,0.5,0.5,
       1,1,1,0.25,0.25,0.25,0.25,
       1,1,0.5,0.5,0.5,0.5,
       1,1,1,0.25,0.25,0.25,0.25,
       1+0.5,0.5,0.5,0.5,1
       
};
int length;
void setup() {
  // iterate over the notes of the melody:
   pinMode(6, INPUT_PULLUP);  
   Serial.begin(9600);
   length = sizeof(melody2) / sizeof(melody2[0]);
}

byte present=1,previous=1,num=0;

void loop() {

  Serial.println(num);
  
  if(num==0){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody1[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
      present = digitalRead(BUTTON);
  if(present==1&&previous==0){
    num++;
    if(num>1)num=0;
    thisNote=8;
  }
  previous=present;
    //present=digitalRead(BUTTON);if(present==0)break;
  }
  }

  else if(num==1){
    for (int thisNote = 0; thisNote < length; thisNote++) {
       
       tone(8, melody2[thisNote], tuneNoteDurations);
        delay(450*tuneNoteDurations[thisNote]);
       noTone(8);
       
         present = digitalRead(BUTTON);
  if(present==1&&previous==0){
    num++;
    if(num>1)num=0;
    thisNote=length;
  }
  previous=present;
      // present=digitalRead(BUTTON);if(present==0)break;
    }
  }

  delay(200);
  
  // no need to repeat the melody.
}

/*#define A0 0
#define A1 441
#define A2 495
#define A3 556
#define A4 589
#define A5 661
#define A6 742

#define AL1 221
#define AL2 248
#define AL3 278
#define AL4 294
#define AL5 330
#define AL6 371
#define AL7 416

#define AH1 882
#define AH2 990
#define AH3 1112
#define AH4 1178
#define AH5 1322
#define AH6 1484
#define AH7 1665
 
#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int tune[] = {
A0,A0,A0,A3,A5,
A6,A0,A0,A5,A6,A0,A0,A5,
A6,AH1,A5,A6,A3,A0,A3,A5,
A6,A0,A0,A5,A6,A0,A0,A5,
A6,AH3,AH1,AH2,A6,A0,A3,A5,
A6,A0,A0,A5,A6,A0,A0,A5,
A6,AH1,A5,A6,A3,A5,A1,A2,
A3,AH1,A6,AH3,
AH2,AH3,AH2,AH1,AH2,A6,A0,
A6,A6,A6,A6,AH1,AH2,AH3,
A6,A6,A6,A5,A5,A6,
A6,A6,A6,A6,AH1,AH2,AH3,
A6,A6,A6,AH4,AH4,AH3,
A6,A6,A6,A6,AH1,AH2,AH3,
A6,A6,A6,A5,A5,A6,
A6,A6,A6,A6,AH1,AH2,AH3,
AH6,A5,A5,A6,A6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int melodyNoteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
float tuneNoteDurations[]={
  1,1,1,0.5,0.5,
  0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
   0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
    0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
     0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
      0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
       0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
       1,1,1,1,
       0.5,0.25,0.25,0.5,0.5,1,1,
       1,1,1,0.25,0.25,0.25,0.25,
       1,1,1,0.5,0.5,0.5,0.5,
       1,1,1,0.25,0.25,0.25,0.25,
       1,1,0.5,0.5,0.5,0.5,
       1,1,1,0.25,0.25,0.25,0.25,
       1,1,0.5,0.5,0.5,0.5,
       1,1,1,0.25,0.25,0.25,0.25,
       1+0.5,0.5,0.5,0.5,1
       
};
int length;

void setup() {
  length = sizeof(tune) / sizeof(tune[0]);
  pinMode(9, INPUT_PULLUP);
}

void loop() {
  int btn_state = digitalRead(9);

  // 檢查按鈕狀態
  if (btn_state == 0) {
    // 播放預設旋律
    for (int i = 0; i < 8; i++) {
      int noteDuration = 1000 / melodyNoteDurations[i];
      tone(8, melody[i], noteDuration);
      delay(noteDuration * 1.3);
      noTone(8);
    }
  } else {
    // 播放自定義旋律
    for (int i = 0; i < length; i++) {
      float noteDuration = 450 * tuneNoteDurations[i];
      tone(8, tune[i], noteDuration);
      delay(noteDuration);
      noTone(8);
    }
  }
}*/
/*int length;
void setup() {
  // iterate over the notes of the melody:
  length =sizeof(tune)/sizeof(tune[0]);
  pinMode(9, INPUT_PULLUP);
}
int p;
void loop() {
  // no need to repeat the melody.
    int btn_state = digitalRead(9);
     
    for (int thisNote = 0; thisNote < 8; thisNote++) {
 if(btn_state == LOW){
     int notedurations = 1000 / noteduration[thisNote];
     tone(8, melody[thisNote], noteduration);
    int pause = noteduration * 1.3;
    delay(pause);
     noTone(8);
    p = thisNote;
  }
 
  if(btn_state == HIGH){
  
    tone(8, tune[thisNote], duration);
    delay(450*duration[thisNote]);
    noTone(8);
  }
  else{
     thisNote= p ;
  }
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  
    //tone(8, melody[thisNote], noteDuration);
  


    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    //int pauseBetweenNotes = noteDuration * 1.30;
    //delay(pauseBetweenNotes);
    
    // stop the tone playing:
    
  
}*/
