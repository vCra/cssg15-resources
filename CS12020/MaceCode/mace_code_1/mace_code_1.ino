void setup() {
  // put your setup code here, to run once:*
  Serial.begin(9600);

  setupLED();
}

void setupLED(){
  pinMode(2,  INPUT); //IR in
  pinMode(3,  INPUT); //Switch
  pinMode(5,  OUTPUT);//red
  pinMode(6,  OUTPUT);//orange
  pinMode(9,  OUTPUT);//yellow
  pinMode(10, OUTPUT);//green
  pinMode(11, OUTPUT);//blie
  pinMode(A0, INPUT);//pot
  pinMode(A1, OUTPUT);//IR out
}  
 
 
String mace2sentence(String a){
  int countOfSlash = 0;
  char last;
  String sentence = "";
  char currentWord [] = {};
  bool atEnd = false;
  int sentencePointer = 0;
  int wordPointer = 0;
  char currentChar;
  
  while (!atEnd){
    currentChar = a[sentencePointer];
    if (currentChar == '/'){ //Its the end of the word
      if (countOfSlash > 2){ //Its the end of the transmission
        atEnd = true;
        break;
      }
      else{
        //sentence = sentence + morse2string(currentWord);
        //currentWord = [];
        //countOfSlash++;
        ;
      }
    }
    else{ // It is a standard character, and we can add it to CurrentWord
      currentWord[wordPointer] = currentChar;
      wordPointer++;
    }
  }
  return sentence;
}
 
  
  
String string2morse(String a){
  String output;
  //Serial.print(a);
  int pointer = 0 ;
  // char lastChar = 'a';
  char x;
  for(int pointer = 0; pointer < a.length(); pointer ++){ 
    x = a[pointer];
    //Serial.print(pointer);
    //Serial.print("+");
    output = output + char2morse(x);
    if ((a[pointer]==' ')||(a[pointer+1]==' ')){
      ;
    }
    else{
      output = output + ("/");
    }
//    if (char2morse(a[pointer]) == "!"){
//      break;
//    }
//    //Serial.print(a[pointer]);
//    // lastChar = a[pointer +1];
//    pointer = pointer +1; 
//    delay(10);
//    Serial.print(" ");
  }
  return output;
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


int timedelay;
int passes = 0;
int loopcounter = 0;
int delayLength = 10;
char morse [100] = "";
String input;
void loop() {
  timedelay = readPot();
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    input = String(Serial.readString());
    Serial.println(input);
    Serial.println(mace2char(input));
  }
  
//  if (irValue() == 1){
//    Serial.print("True");
//    if (passes > delayLength*5){
//      morse[loopcounter] = '/';
//    }
//    else if (passes > delayLength){
//      morse[loopcounter] = '-';
//    }
//    else{
//      morse[loopcounter] = '.';
//    }
//    loopcounter ++;
//    passes = 0;
//  }
  passes ++;
  //delay(timedelay);
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
