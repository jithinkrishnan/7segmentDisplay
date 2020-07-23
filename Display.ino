#define SEG_A 12
#define SEG_B 11
#define SEG_C 10
#define SEG_D 9
#define SEG_E 8
#define SEG_F 7
#define SEG_G 6
#define SEG_1 5
#define SEG_2 4
#define SEG_3 3
#define SEG_4 2
#define SEG_5 13

void InitDisplay();
void Display(char digit);
void DisplayDot(void);
void DisplayHour(char hr);
void DisplayMinute(char mi); 

bool toggle = 0;
int sec = 0, mi = 0;
// the setup function runs once when you press reset or power the board

void setup() {
 InitDisplay();
   cli(); // Stop interrupts
  //set timer1 interrupt at 1Hz
  TCCR1A = 0;  // Set entire TCCR1A register to 0
  TCCR1B = 0;  // Same for TCCR1B
  TCNT1  = 0;  // Initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei(); // Enable interrupts
}


void loop() {
 DisplayMinute(sec);
 if(toggle)
 DisplayDot();
 DisplayHour(mi);
}


ISR(TIMER1_COMPA_vect) {
  toggle = !toggle;
  sec++;
  if (sec > 59) {
      sec = 0;
      mi++;
      if(mi > 59)
      mi = 0;
  }
 
}



void InitDisplay() {
   // initialize digital pin LED_BUILTIN as an output.
  pinMode(SEG_A, OUTPUT);   // A
  pinMode(SEG_B, OUTPUT);   // B
  pinMode(SEG_C, OUTPUT);   // C
  pinMode(SEG_D, OUTPUT);   // D
  pinMode(SEG_E, OUTPUT);   // E
  pinMode(SEG_F, OUTPUT);   // F
  pinMode(SEG_G, OUTPUT);   // G
  pinMode(SEG_1, OUTPUT);   // SEG1  
  pinMode(SEG_2, OUTPUT);   // SEG2
  pinMode(SEG_3, OUTPUT);   // SEG3
  pinMode(SEG_4, OUTPUT);   // SEG4
  pinMode(SEG_5, OUTPUT);  // Others
}

void Display(char digit) {
switch(digit) {
  case 0:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 0);    // D
  digitalWrite(SEG_E, 0);   // E
  digitalWrite(SEG_F, 0);  // F
  digitalWrite(SEG_G, 1);   // G
  break;
  case 1:
  digitalWrite(SEG_A, 1);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 1);    // D
  digitalWrite(SEG_E, 1);   // E
  digitalWrite(SEG_F, 1);  // F
  digitalWrite(SEG_G, 1);   // G
  break;
  case 2:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 1);   // C
  digitalWrite(SEG_D, 0);    // D
  digitalWrite(SEG_E, 0);   // E
  digitalWrite(SEG_F, 1);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
  case 3:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 0);    // D
  digitalWrite(SEG_E, 1);   // E
  digitalWrite(SEG_F, 1);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
  case 4:
  digitalWrite(SEG_A, 1);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 1);    // D
  digitalWrite(SEG_E, 1);   // E
  digitalWrite(SEG_F, 0);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
  case 5:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 1);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 0);    // D
  digitalWrite(SEG_E, 1);   // E
  digitalWrite(SEG_F, 0);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
  case 6:
  digitalWrite(SEG_A, 1);   // A
  digitalWrite(SEG_B, 1);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 0);    // D
  digitalWrite(SEG_E, 0);   // E
  digitalWrite(SEG_F, 0);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
  case 7:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 1);    // D
  digitalWrite(SEG_E, 1);   // E
  digitalWrite(SEG_F, 1);  // F
  digitalWrite(SEG_G, 1);   // G
  break;
  case 8:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 0);    // D
  digitalWrite(SEG_E, 0);   // E
  digitalWrite(SEG_F, 0);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
  case 9:
  digitalWrite(SEG_A, 0);   // A
  digitalWrite(SEG_B, 0);   // B
  digitalWrite(SEG_C, 0);   // C
  digitalWrite(SEG_D, 1);    // D
  digitalWrite(SEG_E, 1);   // E
  digitalWrite(SEG_F, 0);  // F
  digitalWrite(SEG_G, 0);   // G
  break;
}
}
void DisplayDot() 
{
  digitalWrite(SEG_A, 1);   // A
  digitalWrite(SEG_B, 1);   // B
  digitalWrite(SEG_C, 1);   // C
  digitalWrite(SEG_D, 1);   // D
  digitalWrite(SEG_E, 0);   // E
  digitalWrite(SEG_F, 1);   // F
  digitalWrite(SEG_G, 1);   // G
  digitalWrite(SEG_1, 0);
  digitalWrite(SEG_2, 0);
  digitalWrite(SEG_3, 0);
  digitalWrite(SEG_4, 0);
  digitalWrite(SEG_5, 1);
  delay(2);
}


void DisplayHour(char hr) {

 if (hr > 59)
 return;
 
 Display(hr / 10);
 digitalWrite(SEG_1, 1);
 digitalWrite(SEG_2, 0);
 digitalWrite(SEG_3, 0);
 digitalWrite(SEG_4, 0);
 digitalWrite(SEG_5, 0);
 delay(1);
 Display(hr % 10);
 digitalWrite(SEG_1, 0);
 digitalWrite(SEG_2, 1);
 digitalWrite(SEG_3, 0);
 digitalWrite(SEG_4, 0);
 digitalWrite(SEG_5, 0);
 delay(1);
}

void DisplayMinute(char mi) {

 if (mi > 59)
 return;
 Display(mi / 10);
 digitalWrite(SEG_1, 0);
 digitalWrite(SEG_2, 0);
 digitalWrite(SEG_3, 1);
 digitalWrite(SEG_4, 0);
 digitalWrite(SEG_5, 0);
 delay(1);
 Display(mi % 10);
 digitalWrite(SEG_1, 0);
 digitalWrite(SEG_2, 0);
 digitalWrite(SEG_3, 0);
 digitalWrite(SEG_4, 1);
 digitalWrite(SEG_5, 0);
 delay(1);
  
}
