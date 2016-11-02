int timedelay;
int passes = 0;
int loopcounter = 0;
int delayLength = 10;
char morse [100] = "";
String input;



void setup() {
  // put your setup code here, to run once:*
  Serial.begin(9600);

  setupLED();
}

void setupLED(){
  pinMode(2,  INPUT); //IR in
  pinMode(3,  INPUT); //Switch
  pinMode(5,  OUTPUT);//red - to be used when not doing anything
  pinMode(6,  OUTPUT);//orange
  pinMode(9,  OUTPUT);//yellow
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blie
  pinMode(A0, INPUT);//pot
  pinMode(A1, OUTPUT);//IR out
}  
 
char* char2morse(char x){
  switch(x){
    case 'a':
      return "=";
    case 'b':
      return "^^=";
     case 'c':
       return "^=$";
     case 'd':
       return "=^";
     case 'e':
       return "^";
     case 'f':
       return "^=^";
     case 'g':
       return "==";
     case 'h':
       return "^==";
     case 'i':
       return "^^";
     case 'j':
       return "=^^";
     case 'k':
       return "^$";
     case 'l':
       return "^^$";
     case 'm':
       return "^=";
     case 'n':
       return "=$";
     case 'o':
       return "$=";
     case 'p':
       return "$^";
     case 'q':
       return "=^$";
     case 'r':
       return "^$=";
     case 's':
       return "^$^";
     case 't':
       return "$";
     case 'u':
       return "$$";
     case 'v':
       return "==^";
     case 'w':
       return "==$";
     case 'x':
       return "=$^";
     case 'y':
       return "^$$";
     case 'z':
       return "===";
     case ' ':
       return "/";
     default :
       return "!";
  }
}
char mace2char(String m){
  int pointer = 0;
  //CONVERTS A SINGLE MACE STRING INTO A SINGLE CHARACTER
  // e.g. mace2char("^") will return 'e'
  if (m == "="){
     return 'a' ;
  }
  else if (m == "^^="){
    return 'b';
  }
  else if (m == "^=$"){
    return 'c';
  }
  else if (m == "=^"){
    return 'd';
  }
  else if (m == "^"){
    return 'e';
  }
  else if (m == "^=^"){
    return 'f';
  }
  else if (m == "=="){
    return 'g';
  }
  else if (m == "^=="){
    return 'h';
  }
  else if (m == "^^"){
    return 'i';
  }
  else if (m == "=^^"){
    return 'j';
  }
  else if (m == "^="){
    return 'k';
  }
  else if (m == "^^$"){
    return 'l';
  }
  else if (m == "^="){
    return 'm';
  }
  else if (m == "=$"){
    return 'n';
  }
  else if (m == "$="){
    return 'o';
  }
  else if (m == "$^"){
    return 'p';
  }
  else if (m == "=^$"){
    return 'q';
  }
  else if (m == "^$="){
    return 'r';
  }
  else if (m == "^$^"){
    return 's';
  }
  else if (m == "$"){
    return 't';
  }
  else if (m == "$$"){
    return 'u';
  }
  else if (m == "==^"){
    return 'v';
  }
  else if (m == "==$"){
    return 'w';
  }
  else if (m == "=$^"){
    return 'x';
  }
  else if (m == "^$$"){
    return 'y';
  }
  else if (m == "==="){
    return 'z';
  }
  
  // NUMBERS
  else if (m == "$^^="){
    return '1';
  }
  else if (m == "$^^$"){
    return '2';
  }
  else if (m == "$^=^"){
    return '3';
  }
  else if (m == "$^=="){
    return '4';
  }
  else if (m == "$^=$"){
    return '5';
  }
  else if (m == "$^$^"){
    return '6';
  }
  else if (m == "$^$="){
    return '7';
  }
  else if (m == "$^$$"){
    return '8';
  }
  else if (m == "$=^^"){
    return '9';
  }
  else if (m == "$^^^"){
    return '0';
  }
  
  //OTHERS
  else if (m == "$^^"){
    return '.';
  }
  else if (m == "$^="){
    return ',';
  }
  else if (m == "$=^"){
    return '\'';
  }
  else if (m == "$=="){
    return '?';
  }
  else if (m == "$=$"){
    return '!';
  }
  else if (m == "$$^"){
    return '+';
  }
  else if (m == "$$="){
    return '-';
  }
  else if (m == "$$$"){
    return '*';
  }
  else if (m == "$^$"){
    return '/';
  }
  else if (m == "$===$"){
    return '=';
  }
  else{
    return '£';
  }
}

char newchar; // The new character that has been produced, and is going to be placed into a word

// ERRORS
int error = false; //Is true when an error occures
/* 
11 = error converting mace to char
12 = mace string contains 
3 = 
22 = char does not exist in mace language
*/

void loop() {
  // put your main code here, to run repeatedly:
  
  
  while (Serial.available() == 0){
    ; // Does nothing while they is nothing on the serial port to process
    red_on();
  }
  red_off();
  input = String(Serial.readString());
  if (input[0] == '$' || input[0] == '^' || input[0] == '='){ // If the code is mace code
    Serial.println(input);
    newchar = mace2char(input); // Get the letter from the mace code
    if (newchar != '£'){ // Then an error occured, and it just r
      Serial.println("ERROR");
    }
    else {
      Serial.println("An error Occured... :/");
    }
  }
  else { // The string is not mace code...
    Serial.println(input);
  }
}

bool irValue(){
  return (!digitalRead(2));
}

void blinkLED(){
  delay(readPot());
  blue_on();
  red_off();
  delay(readPot());
  blue_off();
  green_on();
  delay(readPot());
  green_off();
  yellow_on();
  delay(readPot());
  yellow_off();
  orange_on();  
  delay(readPot());
  orange_off();
  red_on();
}
void allOff(){
  red_off();
  green_off();
  orange_off();
  blue_off();
  yellow_off();  
}

void ledStuff(){
  allOff();
  blue_on();
  red_on();
  delay(readPot());
  green_on();
  orange_on();
  delay(readPot());
  yellow_on();
  delay(readPot());
  blue_off();
  red_off();
  delay(readPot());
  green_off();
  orange_off();
  delay(readPot());
}

bool buttonPressed(){
   return digitalRead(3);
}
int readPot(){
   return analogRead(A0);
   
 }


  
void ir_on(){
  digitalWrite(A1,HIGH);
}  
void ir_off(){
  digitalWrite(A1,LOW);
}



void red_on(){
  digitalWrite(5,HIGH);
}
void red_off(){
  digitalWrite(5,LOW);
}
void orange_on(){
   digitalWrite(6,HIGH); 
}
void orange_off(){
  digitalWrite(6,LOW);
}
void yellow_on(){
  digitalWrite(9,HIGH);
}
void yellow_off(){
  digitalWrite(9,LOW);
}
void green_on(){
  digitalWrite(10,HIGH); 
}
void green_off(){
  digitalWrite(10,LOW);
}
void blue_on(){
  digitalWrite(11,HIGH);
}
void blue_off(){
  digitalWrite(11,LOW);
}
