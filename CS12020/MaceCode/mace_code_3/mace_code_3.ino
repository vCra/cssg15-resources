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
 
char* char2mace(char x){
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
     //Numbers
     case '1':
       return "$^^=";
     case '2':
       return "$^^$";
     case '3':
       return "$^=^";
     case '4':
       return "$^==";
     case '5':
       return "$^=$";
     case '6':
       return "$^$^";
     case '7':
       return "$^$=";
     case '8':
       return "$^$$";
     case '9':
       return "$=^^";
     case '0':
       return "$^^^";
    //Others
     case '.':
       return "$^^";
     case ',':
       return "$^=";
     case '\'':
       return "$=^";
     case '?':
       return "$==";
     case '!':
       return "$=$";
     case '+':
       return "$$^";
     case '-':
       return "$$=";
     case '*':
       return "$$$";
     case '/':
       return "$^$";
     case '=':
       return "$===$";
     case ' ':
       return " ";
     default :
       return "~";
  }
}
char mace2char(String m){
  int pointer = 0;
  //CONVERTS A SINGLE MACE STRING INTO A SINGLE CHARACTER
  // e.g. mace2char("^") will return 'e'
  if (m == "="){
     return 'A' ;
  }
  else if (m == "^^="){
    return 'B';
  }
  else if (m == "^=$"){
    return 'C';
  }
  else if (m == "=^"){
    return 'D';
  }
  else if (m == "^"){
    return 'E';
  }
  else if (m == "^=^"){
    return 'F';
  }
  else if (m == "=="){
    return 'G';
  }
  else if (m == "^=="){
    return 'H';
  }
  else if (m == "^^"){
    return 'I';
  }
  else if (m == "=^^"){
    return 'J';
  }
  else if (m == "^="){
    return 'K';
  }
  else if (m == "^^$"){
    return 'L';
  }
  else if (m == "^="){
    return 'M';
  }
  else if (m == "=$"){
    return 'N';
  }
  else if (m == "$="){
    return 'O';
  }
  else if (m == "$^"){
    return 'P';
  }
  else if (m == "=^$"){
    return 'Q';
  }
  else if (m == "^$="){
    return 'R';
  }
  else if (m == "^$^"){
    return 'S';
  }
  else if (m == "$"){
    return 'T';
  }
  else if (m == "$$"){
    return 'U';
  }
  else if (m == "==^"){
    return 'V';
  }
  else if (m == "==$"){
    return 'W';
  }
  else if (m == "=$^"){
    return 'X';
  }
  else if (m == "^$$"){
    return 'Y';
  }
  else if (m == "==="){
    return 'Z';
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
    return '~';
  }
}

char newchar; // The new character that has been produced, and is going to be placed into a word

// ERRORS
int error = false; //Is true when an error occures
/* 
11 = error converting mace to char
12 = mace string contains
13 = mace countains non mace character
3 = 
22 = char does not exist in mace language
*/

void loop(){
  String value;
  while (Serial.available() == 0){
    ; // Does nothing while they is nothing on the serial port to process
    red_on();
  }
  red_off();
  yellow_on();
  delay(1);
  input = String(Serial.readString());
  //input = deblank(input);
  if (input[0] == '$' || input[0] == '^' || input[0] == '='){ // If the code is mace code
    input = input + "//";
    value = (loopMace(input));
    Serial.println(value);
    if (value == "RXIR"){
      if (irValue){
        Serial.println("HIGH");
      }
      else{
        Serial.println("LOW");
      }
    }
    else if (value == "+-IR"){
      ir_on();
      delay(1000);
      ir_off();
      Serial.println("IR SENT");
    }
    else if (value == "VRV"){
      int reading;
      reading = 50;
      String toPrint = reading.ToString("D" + 4);
      Serial.println(toPrint+'~');
    }
    macestring2LED(input);
  }
  else { // The string is not mace code...
    input.toLowerCase();
    input = input + "~";
    value = (loopAscii(input));
    Serial.println(value);
    macestring2LED(value);
  }
  yellow_off();
}


String loopMace(String input){
  String currentString = "";
  String output = "";
  int loopcounter = 0;
  while (true){
    if (input[loopcounter] == '$' || input[loopcounter] == '^' || input[loopcounter] == '='){ // If the code is mace code
      currentString = currentString + input[loopcounter];
    }
    else if (input[loopcounter] == '/'){
      output = output + mace2char(currentString);
      currentString = "";
      if (input[loopcounter + 1] == '/'){
        return output;
      }
    }
    else if(input[loopcounter] == ' '){
      output = output + mace2char(currentString);
      output = output + ' ';
      currentString = "";
    }
    else{
      error = 13;
      break;
    }
  loopcounter ++;
  }
}

String loopAscii(String input){
  String output = "";
  int loopcounter = 0;
  while (true){
    if (input[loopcounter] == '~'){ // Its the end of the string
      return output+'/';
    }
    else{
      output = output + char2mace(input[loopcounter]);
      if ((char2mace(input[loopcounter+1]) == " ") || (char2mace(input[loopcounter]) == " ")){
        ; // Don't add a "/"         
      }
      else{
        output = output + "/";
      }
    }
  loopcounter ++;
  }
}

/*
//Code from http://stackoverflow.com/questions/13084236/function-to-remove-spaces-from-string-char-array-in-c
char * deblank(char * input)                                                  
{
    char *output=input;
    for (int i = 0, j = 0; i<strlen(input); i++,j++)                       
    {
        if (input[i]!=' ')                                                 
            output[j]=input[i];                                             
        else
            j--;                                                   
    }
    return output;                                                         
}
*/

void macestring2LED(String input){
  int loopcounter = 0;
  while (true){
    if (input[loopcounter] == '/'){
      if (input[loopcounter + 1] == '/'){
        break;
      }
    }
    sendLedSignal(input[loopcounter]);
    loopcounter ++;
  }
}



bool irValue(){
  return (digitalRead(2));
}

void sendLedSignal(char sim){
  if (sim=='^'){
    blue_on();
    delay(1*potReadingToDelay());
    blue_off();
  }

  else if (sim=='='){
    blue_on();
    delay(2*potReadingToDelay());
    blue_off();
  }
  else if (sim=='$'){
    blue_on();
    delay(4*potReadingToDelay());
    blue_off();
  }
  else if (sim=='/'){
    blue_off(); // fixes a bug which im not sure why its being caused
    delay(2*potReadingToDelay());
  }
  else if (sim==' '){
    blue_off(); // same here
    delay(4*potReadingToDelay());
  }
  delay(1*potReadingToDelay());
  
}

void allOff(){
  red_off();
  green_off();
  orange_off();
  blue_off();
  yellow_off();  
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

int potReadingToDelay(){//Reads the value from the potentiometer and returns the delay in ms
  //someone told me that they is a map funcion that does this... I spent too much time revising GCSE maths to implament it though...
  return ((9.74609375 * readPot())+20);
}

