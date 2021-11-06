#include <Arduino.h>


// Raws
#define C1 2
#define C2 3
#define C3 4
#define C4 5
#define C5 6
#define C6 7
#define C7 8
#define C8 9
//Columns
#define R8 10
#define R7 11
#define R6 12
#define R5 13
#define R4 A0
#define R3 A1
#define R2 A2
#define R1 A3

// Button
#define BTN A7
#define LIMIT 5
int pause=300;

int emoji[8][8];


  int Cat [8] [8] ={
  {1,0,0,0,1,0,0,0},
  {1,1,1,1,1,0,0,0},
  {1,0,1,0,1,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,1,1,1,1,0,0,1},
  {0,1,1,1,1,1,0,1},
  {1,0,1,1,1,1,1,0},
  };

  int Smile [8] [8] ={
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,1,0,0,1,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,1,0,0,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  };

  int Heart [8] [8] ={
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  };

  int Melody [8] [8] ={
    {0,0,0,0,0,1,1,1},
    {0,0,1,1,1,1,1,1},
    {0,0,1,1,1,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,1,0,0,1,1,1},
    {1,1,1,0,0,1,1,0},
    {1,1,0,0,0,0,0,0},
  };

  int Ghost [8] [8] ={
    {0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,0,1},
    {1,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,0,1,1,0,1,1},
  };
void setup() {
   pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
   pinMode(R3, OUTPUT);
   pinMode(R4, OUTPUT);
   pinMode(R5, OUTPUT);
   pinMode(R6, OUTPUT);
   pinMode(R7, OUTPUT);
   pinMode(R8, OUTPUT);
   pinMode(C1, OUTPUT);
   pinMode(C2, OUTPUT);
   pinMode(C3, OUTPUT);
   pinMode(C4, OUTPUT);
   pinMode(C5, OUTPUT);
   pinMode(C6, OUTPUT);
   pinMode(C7, OUTPUT);
   pinMode(C8, OUTPUT);


  digitalWrite(R1,LOW);
  digitalWrite(R2,LOW);
  digitalWrite(R3,LOW);
  digitalWrite(R4,LOW);
  digitalWrite(R5,LOW);
  digitalWrite(R6,LOW);
  digitalWrite(R7,LOW);
  digitalWrite(R8,LOW);
  digitalWrite(C1,HIGH);
  digitalWrite(C2,HIGH);
  digitalWrite(C3,HIGH);
  digitalWrite(C4,HIGH);
  digitalWrite(C5,HIGH);
  digitalWrite(C6,HIGH);
  digitalWrite(C7,HIGH);
  digitalWrite(C8,HIGH);
  pinMode(A7,INPUT);


Serial.begin(9600);

}


void set_emoji(int emo[8][8]){
  for(int j = 0; j < 8; j++)
  {
      for(int i = 0; i < 8; i++)
      {
          emoji[i][j] = emo[i][j];
      }
  }
}

int pressed_count = 1;
void toggle_images(int btn_pressed){
  if(btn_pressed != 0){
    Serial.println("PRESSED");
    delay(500);
    if(pressed_count == LIMIT){
      pressed_count = 1;
    }
    else{
      pressed_count++;

    }
    Serial.println( pressed_count);


    switch (pressed_count) {
      case 1:
        set_emoji(Smile);
        break;
      case 2:
        set_emoji(Heart);
        break;
      case 3:
        set_emoji(Cat);
        break;
      case 4:
        set_emoji(Melody);
        break;
      case 5:
        set_emoji(Ghost);
        break;
    };
  }
}

void SelectRow(int row){
  if (row==1) digitalWrite(R1,HIGH); else digitalWrite(R1,LOW);
  if (row==2) digitalWrite(R2,HIGH); else digitalWrite(R2,LOW);
  if (row==3) digitalWrite(R3,HIGH); else digitalWrite(R3,LOW);
  if (row==4) digitalWrite(R4,HIGH); else digitalWrite(R4,LOW);
  if (row==5) digitalWrite(R5,HIGH); else digitalWrite(R5,LOW);
  if (row==6) digitalWrite(R6,HIGH); else digitalWrite(R6,LOW);
  if (row==7) digitalWrite(R7,HIGH); else digitalWrite(R7,LOW);
  if (row==8) digitalWrite(R8,HIGH); else digitalWrite(R8,LOW);
}

void Set_LED_in_Active_Row(int column, int state){
  if (column==1) digitalWrite(C1,!state);
  if (column==2) digitalWrite(C2,!state);
  if (column==3) digitalWrite(C3,!state);
  if (column==4) digitalWrite(C4,!state);
  if (column==5) digitalWrite(C5,!state);
  if (column==6) digitalWrite(C6,!state);
  if (column==7) digitalWrite(C7,!state);
  if (column==8) digitalWrite(C8,!state);
}



void loop() {

    for (int j=0;j<8;j++){
      SelectRow(j+1);
      for (int i=0;i<8;i++){
        Set_LED_in_Active_Row(i+1 ,emoji[j][i]);
      }
      delay(1);
    }

    toggle_images(analogRead(BTN));
}
