#include <Wire.h>
#define EEP 0x50

const byte ir = 2;

boolean inputButton = false;
unsigned long value = 0;

int up = 8;
int down = 9;
int RRR = 10;
int LLL = 2;
int address = 0;
int address2 = 1;
byte score = readEEP(EEP, address);
byte score2 = readEEP(EEP, 2);
int scoreFlag = 0;

int volumeP = 0;
int volumeM = 0;

int cntD = 0;
int cntL = 0;

int cntU = 0;
int cntR = 0;

int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int flag4 = 0;
int flag5 = 0;
int flag6 = 0;
int flag7 = 0;
int flag8 = 0;
int flag9 = 0;
int powerOnFlag = 0;
int powerCounter = 0;
int playCounter = 0;

int downFlag = 0;
int LLLFlag = 0;

int upFlag = 0;
int RRRFlag = 0; 

int wFlag = 0;
int LFlag = 0;
int c = 50;

int nums[9][12] {
  {RRR, up, down, up, 0, 0, 0, 0, 0, 0, 0, 0}, //1
  {RRR, up, down, up, RRR, 0, 0, 0, 0, 0, 0, 0}, //2
  {RRR, up, down, up, RRR, up, 0, 0, 0, 0, 0, 0}, //3
  {RRR, up, down, up, RRR, up, LLL, 0, 0, 0, 0, 0}, //4
  {RRR, up, down, up, RRR, up, LLL, RRR, 0, 0, 0, 0}, //5
  {RRR, up, down, up, RRR, up, LLL, RRR, up, 0, 0, 0}, //6
  {RRR, up, down, up, RRR, up, LLL, RRR, up, LLL, 0, 0}, //7
  {RRR, up, down, up, RRR, up, LLL, RRR, up, LLL, up, 0}, //8
  {RRR, up, down, up, RRR, up, LLL, RRR, up, LLL, up, RRR}, //9
};


typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);

} task;

const unsigned short tasksNum = 4;
task tasks[tasksNum];


enum SM1_States { SM1_INIT, SM1_S0};
int SM1_Tick(int state1) {
  switch (state1) { // State transitions
    case SM1_INIT:
      state1 = SM1_S0;
      break;
    case SM1_S0:
      state1 = SM1_S0;
      break;

  }
  switch (state1) { // State Action
    case SM1_INIT:
      break;
    case SM1_S0:
           if ((value == 0xFF30CF || readIR() == 0xFF30CF) && flag1 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 4; ++i) {
                digitalWrite(nums[0][i], HIGH);
                digitalWrite(nums[0][i], LOW);
            }
            ++flag1;    
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;
            flag5 = 0;
            flag6 = 0;
            flag7 = 0;
            flag8 = 0;
            flag9 = 0;
            ++cntD;
            ++cntU;
          }
          if ((value == 0xFF18E7 || readIR() == 0xFF18E7) && flag2 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 5; ++i) {
                digitalWrite(nums[1][i], HIGH);
                digitalWrite(nums[1][i], LOW);
            }
            ++flag2;
            flag1 = 0;
            flag3 = 0;
            flag4 = 0;
            flag5 = 0;
            flag6 = 0;
            flag7 = 0;
            flag8 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF7A85 || readIR() == 0xFF7A85) && flag3 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 6; ++i) {
                digitalWrite(nums[2][i], HIGH);
                digitalWrite(nums[2][i], LOW);
            }
            ++flag3;
            flag1 = 0;
            flag2 = 0;
            flag4 = 0;
            flag5 = 0;
            flag6 = 0;
            flag7 = 0;
            flag8 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF10EF || readIR() == 0xFF10EF) && flag4 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 7; ++i) {
                digitalWrite(nums[3][i], HIGH);
                digitalWrite(nums[3][i], LOW);
            }
            ++flag4;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag5 = 0;
            flag6 = 0;
            flag7 = 0;
            flag8 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF38C7 || readIR() == 0xFF38C7) && flag5 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 8; ++i) {
                digitalWrite(nums[4][i], HIGH);
                digitalWrite(nums[4][i], LOW);
            }
            ++flag5;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;
            flag6 = 0;
            flag7 = 0;
            flag8 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF5AA5 || readIR() == 0xFF5AA5) && flag6 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 9; ++i) {
                digitalWrite(nums[5][i], HIGH);
                digitalWrite(nums[5][i], LOW);
            }
            ++flag6;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;
            flag5 = 0;
            flag7 = 0;
            flag8 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF42BD || readIR() == 0xFF42BD) && flag7 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 10; ++i) {
                digitalWrite(nums[6][i], HIGH);
                digitalWrite(nums[6][i], LOW);
            }
            ++flag7;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;
            flag5 = 0;
            flag6 = 0;
            flag8 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF4AB5 || readIR() == 0xFF4AB5) && flag8 == 0){
            volumeP = 0;
            volumeM = 0;
            for (int i = 0; i < 11; ++i) {
                digitalWrite(nums[7][i], HIGH);
                digitalWrite(nums[7][i], LOW);
            }
            ++flag8;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;
            flag5 = 0;
            flag6 = 0;
            flag7 = 0;
            flag9 = 0;
          }
          if ((value == 0xFF52AD || readIR() == 0xFF52AD) && flag9 == 0){
            volumeP = 0;
            volumeM = 0;
            upFlag = 20;
            downFlag = 0;
            for (int i = 0; i < 12; ++i) {
                digitalWrite(nums[8][i], HIGH);
                digitalWrite(nums[8][i], LOW);
            }
            ++flag9;
            flag1 = 0;
            flag2 = 0;
            flag3 = 0;
            flag4 = 0;
            flag5 = 0;
            flag6 = 0;
            flag7 = 0;
            flag8 = 0;
            ++cntL;
            ++cntR;
            powerOnFlag = 2;
          }
          
        if ((value == 0xFFA25D || readIR() == 0xFFA25D) && powerCounter == 0) {  
            volumeP = 0;
            volumeM = 0;
            if (powerOnFlag != 1) {
            displayMenu();
            ++powerOnFlag;
            }
            if (powerOnFlag > 1) {
              displayClean();
              digitalWrite(up, LOW);
              digitalWrite(down, LOW);
              digitalWrite(RRR, LOW);
              digitalWrite(LLL, LOW);
              powerCounter = 1;         
            }
            playCounter = 0;
        }
        
        if ((value == 0xFF906F || readIR() == 0xFF906F) && upFlag != 10) {
            volumeP = 0;
            volumeM = 0;
            digitalWrite(up, HIGH);
            digitalWrite(down, LOW);
            digitalWrite(RRR, LOW);
            digitalWrite(LLL, LOW);
            if (cntU == 1 || cntU == 3) {
               ++upFlag;
            }
            if (upFlag == 10) {
              digitalWrite(down, LOW);
              digitalWrite(up, LOW);
              digitalWrite(RRR, LOW);
              digitalWrite(LLL, LOW);
              //lcd displays winning screen
              displayClean();
              whereAmI(21,0);
              printMe("You Win!", 1);
              whereAmI(26, 10);
              printMe("Score:", 1);
              if (score == 0) {
                score = 1;
              }
              if (score2 == 0) {
                  writeEP(address, score);
                  whereAmI(35, 20);
                  printMe2(score);
                  digitalWrite(up, LOW);
                }
                else {
                  whereAmI(34, 20);
                  printMe("1", 1);
                  digitalWrite(up, LOW);
                }
            }
        }
        
        if ((value == 0xFFE01F || readIR() == 0xFFE01F) && downFlag != 10) {    
            volumeP = 0;
            volumeM = 0;
            digitalWrite(down, HIGH);
            digitalWrite(up, LOW);
            digitalWrite(RRR, LOW);
            digitalWrite(LLL, LOW);
            if (cntD == 2) {
               ++downFlag;
            }
            if (downFlag == 10) {
              digitalWrite(down, LOW);
              digitalWrite(up, LOW);
              digitalWrite(RRR, LOW);
              digitalWrite(LLL, LOW);
              //lcd displays losing screen
              displayClean();
              whereAmI(21,0);
              printMe("You Lose!", 1);
              digitalWrite(down, LOW);
              playCounter = 0;
            }
        }

        if ((value == 0xFFC23D || readIR() == 0xFFC23D) && RRRFlag != 25) {    
            volumeP = 0;
            volumeM = 0;
            digitalWrite(RRR, HIGH);
            digitalWrite(up, LOW);
            digitalWrite(down, LOW);
            digitalWrite(LLL, LOW);
            if (cntR == 1 || cntR == 3) {
              ++RRRFlag;
            }
            if (RRRFlag == 25) {
              digitalWrite(down, LOW);
              digitalWrite(up, LOW);
              digitalWrite(RRR, LOW);
              digitalWrite(LLL, LOW);
              LFlag = 1;
            }
            wFlag = 1;
        }

        if ((value == 0xFF22DD || readIR() == 0xFF22DD) && LLLFlag != 3) {  
            volumeP = 0;
            volumeM = 0;
            digitalWrite(LLL, HIGH);
            digitalWrite(up, LOW);
            digitalWrite(down, LOW);
            digitalWrite(RRR, LOW);
            if (cntL == 2) {
               ++LLLFlag;
            }
            if (LLLFlag == 3) {
              digitalWrite(down, LOW);
              digitalWrite(up, LOW);
              digitalWrite(RRR, LOW);
              digitalWrite(LLL, LOW);
              LFlag = 1;
            }
            wFlag = 1;
        }

        if ((value == 0xFF629D || readIR() == 0xFF629D) && volumeP == 0) {  
              playCounter = 0;
              displayClean();
              whereAmI(24,0);
              printMe("Choose", 1);
              whereAmI(40,10);
              printMe("a", 1);
              whereAmI(27,20);
              printMe("Level:", 1);
              whereAmI(27,30);
              printMe("(1-9)", 1);
              volumeP = 1;
              if (value || readIR()) {
              displayClean();
              whereAmI(29,0);
              printMe("Good", 1);
              whereAmI(28,10);
              printMe("Luck!", 1);
              }
        }

        if ((value == 0xFFA857 || readIR() == 0xFFA857) && volumeM == 0) {  
              playCounter = 0;
             displayClean();
             whereAmI(27,0);
             printMe("Best", 1);
             whereAmI(25,10);
             printMe("Score:", 1);
             whereAmI(35, 20);
             printMe2(score);
             volumeM = 1;
                     
        }

         if ((value == 0xFF02FD || readIR() == 0xFF02FD) && playCounter == 0) {  
               displayMenu();
               ++playCounter;
               RRRFlag = 0;
               digitalWrite(down, LOW);
               digitalWrite(up, LOW);
               digitalWrite(RRR, LOW);
               digitalWrite(LLL, LOW);
               int flag1 = 0;
               int flag2 = 0;
               int flag3 = 0;
               int flag4 = 0;
               int flag5 = 0;
               int flag6 = 0;
               int flag7 = 0;
               int flag8 = 0;
               int flag9 = 0;
         }
     
      break;
  }

  return state1;
}

enum SM2_States { SM2_INIT, SM2_S0};
int SM2_Tick(int state2) {
  switch (state2) { // State transitions
    case SM2_INIT:
      //State Transition
      state2 = SM2_S0;
      break;
    case SM2_S0:
      state2 = SM2_S0;
      break;
  }
  switch (state2) { // State Action
    case SM2_INIT:
      break;
    case SM2_S0:
      if (value || readIR()) {
        if (value) {
          Serial.println(value, HEX);
          value = 0;
        }
        else if (readIR()) {
          Serial.println(readIR(), HEX);
          readIR() = 0;
        }
      }
      inputButton = true;
      break;
  }
  return state2;
}

enum SM3_States { SM3_INIT, SM3_S0};
int SM3_Tick(int state3) {
  switch (state3) { // State transitions
    case SM3_INIT:
      //State Transition
      state3 = SM3_S0;
      break;
    case SM3_S0:
      state3 = SM3_S0;
      break;
  }
  switch (state3) { // State Action
    case SM3_INIT:
      break;
    case SM3_S0:
      if (wFlag = 1) {
         //lcd displays winning screen
              displayClean();
              whereAmI(21,0);
              printMe("You Win!", 1);
              whereAmI(26, 10);
              printMe("Score:", 1);
              if (score == 1) {
                score = 9;
                writeEP(EEP, address, score);
                writeEP(EEP, address2, 1);         
              }
              whereAmI(35, 20);
              printMe2(score);
       }
       WFlag = 0;
      break;
  }
  return state3;
}

enum SM4_States { SM4_INIT, SM4_S0};
int SM4_Tick(int state4) {
  switch (state4) { // State transitions
    case SM4_INIT:
      //State Transition
      state4 = SM4_S0;
      break;
    case SM4_S0:
      state4 = SM4_S0;
      break;
  }
  switch (state4) { // State Action
    case SM4_INIT:
      break;
    case SM4_S0:
      if (LFlag = 1) {
      displayClean();
      whereAmI(21,0);
      printMe("You Lose!", 1);
      }
      LFlag = 0;
      break;
  }
  return state4;
}

void setup() {  
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(RRR, OUTPUT);
  pinMode(LLL, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
  beginDaNokia();
  displayClean();
  pinMode(ir, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ir), doIt, FALLING);

  unsigned char i = 0;
  tasks[i].state = SM1_INIT;
  tasks[i].period = 200;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM1_Tick;
  i++;
  tasks[i].state = SM2_INIT;
  tasks[i].period = 200;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM2_Tick;
  i++;
  tasks[i].state = SM3_INIT;
  tasks[i].period = 200;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM3_Tick;
  i++;
  tasks[i].state = SM4_INIT;
  tasks[i].period = 200;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM4_Tick;
  i++;
  tasks[i].state = SM5_INIT;
  tasks[i].period = 200;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &SM5_Tick;
}

void loop() {
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
      tasks[i].state = tasks[i].TickFct(tasks[i].state);
      tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
}

void displayMenu() {
    displayClean();
    whereAmI(15, 0);
    printMe("Main Menu", 1);
    whereAmI(0, 11);   //(column(left/right), row(up/down))
    printMe("VOL+:Level #", 1);
    whereAmI(0, 21);
    printMe("VOL-:Best", 1);
    whereAmI(30, 30);
    printMe("Score", 1);
    whereAmI(0, 40);
    printMe("Power:Quit", 1);
    whereAmI();
}

void displayClean() {
    whereAmI(15, 0);
    printMe("                 ", 1);
    whereAmI(0, 11);
    printMe("                          ", 1);
    whereAmI(0, 21);
    printMe("                              ", 1);
    whereAmI(30, 30);
    printMe("                                  ", 1);
    whereAmI(0, 40);
    printMe("                              ", 1);
    whereAmI();
}

byte readEEP(int add0, int add1) {
  Wire.beginTransmission(add0);
  byte pp = 0x00;
  Wire.write((int)(add1 >> 8));
  Wire.write((int)(add1 & 0xFF);
  Wire.endTransmission();
  pp = Wire.read();
  return pp;
}

void writeEP(int add0, int add1, byte value) {
  Wire.beginTransmission(add0);
  Wire.write((int)(add1 >> 8));
  Wire.write((int)(add2 & 0xFF));
  Wire.write(value);
  Wire.endTransmission();
}

void doIt () {
  int x = 0;
  byte count = 0;
  if (inputButton) {
    inputButton = false;
    unsigned long pulse1;
    for (count = 0; count < 32; ++count) {
      while (pulse1 < 64 || x == 0) {
        pulse1 = pulseIn(ir, HIGH, 2200);
        x = 1;
      }
      bitWrite (value, count, pulse1 > 1120);
    }
  }
}
