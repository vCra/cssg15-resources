int timer = 0;
// Morse chars defined
char morse_a[] = ".-";
char morse_b[] = "-...";
char morse_c[] = "-.-.";
char morse_d[] = "-..";
char morse_e[] = ".";
char morse_f[] = "..-.";
char morse_g[] = "--.";
char morse_h[] = "....";
char morse_i[] = "..";
char morse_j[] = ".---";
char morse_k[] = "-.-";
char morse_l[] = ".-..";
char morse_m[] = "--";
char morse_n[] = "-.";
char morse_o[] = "---";
char morse_p[] = ".--.";
char morse_q[] = "--.-";
char morse_r[] = ".-.";
char morse_s[] = "...";
char morse_t[] = "-";
char morse_u[] = "..-";
char morse_v[] = "...-";
char morse_w[] = ".--";
char morse_x[] = "-..-";
char morse_y[] = "-.--";
char morse_z[] = "--..";
char space[]   = "  ";


void setup() {
  // put your setup code here, to run once:*
  Serial.begin(9600);
  //String testString = "morse code ";
  //Serial.print(string2morse(testString));
  Serial.print("");
  Serial.print(morse2string(".-/"));//a
  Serial.print(morse2string("-.../"));//b
  Serial.print(morse2string("-.-./"));//c
  Serial.print(morse2string("-../"));//d
  Serial.print(morse2string("./"));//e
  Serial.print(morse2string("..-./"));//f
  Serial.print(morse2string("--./"));//g
  Serial.print(morse2string("..../"));//h
  Serial.print(morse2string("../"));//i
  Serial.print(morse2string(".---/"));//j
  Serial.print(morse2string("-.-/"));//k
  Serial.print(morse2string(".-../"));//l
  Serial.print(morse2string("--/"));//m
  Serial.print(morse2string("-./"));//n
  Serial.print(morse2string("---/"));//o
  Serial.print(morse2string(".--./"));//p
  Serial.print(morse2string("--.-/"));//q
  Serial.print(morse2string(".-./"));//r
  Serial.print(morse2string(".../"));//s
  Serial.print(morse2string("-/"));//t
  Serial.print(morse2string("..-/"));//u
  Serial.print(morse2string("...-/"));//v
  Serial.print(morse2string(".--/"));//w
  Serial.print(morse2string("-..-/"));//x
  Serial.print(morse2string("-.--/"));//y
  Serial.print(morse2string("--../"));//z
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
 
 
String morse2sentence(String a){
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
      return morse_a;
    case 'b':
      return morse_b;
     case 'c':
       return morse_c;
     case 'd':
       return morse_d;
     case 'e':
       return morse_e;
     case 'f':
       return morse_f;
     case 'g':
       return morse_g;
     case 'h':
       return morse_h;
     case 'i':
       return morse_i;
     case 'j':
       return morse_j;
     case 'k':
       return morse_k;
     case 'l':
       return morse_l;
     case 'm':
       return morse_m;
     case 'n':
       return morse_n;
     case 'o':
       return morse_o;
     case 'p':
       return morse_p;
     case 'q':
       return morse_q;
     case 'r':
       return morse_r;
     case 's':
       return morse_s;
     case 't':
       return morse_t;
     case 'u':
       return morse_u;
     case 'v':
       return morse_v;
     case 'w':
       return morse_w;
     case 'x':
       return morse_x;
     case 'y':
       return morse_y;
     case 'z':
       return morse_z;
     case ' ':
       return space;
     default :
       return "!";
  }
}

char morse2string(String m){
  int pointer = 0;
  if (m[pointer] == '.'){
    pointer ++;
    if (m[pointer] == '/'){
      return 'e';
    }
    else if (m[pointer] == '.'){
      pointer ++;
      if (m[pointer] == '/'){
        return 'i';
      }
      else if (m[pointer] == '.'){
        pointer ++;
        if (m[pointer] == '/'){
          return 's';
        }
        else if (m[pointer] == '.'){
          return 'h';
        }
        else if (m[pointer] == '-'){
          return 'v';
        }
      }
      else if (m[pointer] == '-'){
        pointer ++;
        if (m[pointer] == '/'){
          return 'u';
        }
        else if (m[pointer] == '.'){
          return 'f';
        }
      }
    }
    else if (m[pointer] == '-'){
      pointer ++;
      if (m[pointer] == '/'){
        return 'a';
      }
      else if (m[pointer] == '.'){
        pointer ++;
        if (m[pointer] == '/'){
          return 'r';
        }
        else if (m[pointer] == '.'){
          return 'l';
        }
      }
      else if (m[pointer] == '-'){
        pointer ++;
        if (m[pointer] == '/'){
          return 'w';
        }
        else if (m[pointer] == '.'){
          return 'p';
        }
        else if (m[pointer] == '-'){
          return 'j';
        }
      } 
    }
  }
  else if (m[pointer] == '-'){
    pointer ++;
    if (m[pointer] == '/'){
      return 't' ;
    }
    else if (m[pointer] == '.'){
      pointer ++;
      if (m[pointer] == '/'){
        return 'n';
      }
      else if (m[pointer] == '.'){
        pointer ++;
        if (m[pointer] == '/'){
         return 'd';
        }
        else if (m[pointer] == '.'){
         return 'b';
        }
        else if (m[pointer] == '-'){
         return 'x';
        } 
      }
      else if (m[pointer] == '-'){
        pointer ++;
        if (m[pointer] == '/'){
          return 'k';
        }
        else if (m[pointer] == '.'){
          return 'c';
        }
        else if (m[pointer] == '-'){
          return 'y';
        }
      }  
    }
    else if (m[pointer] == '-'){
      pointer ++;
      if (m[pointer] == '/'){
        return 'm';
      }
      else if (m[pointer] == '.'){
        pointer ++;
        if (m[pointer] == '/'){
          return 'g';
        }
        else if (m[pointer] == '.'){
          return 'z';
        }
        else if (m[pointer] == '-'){
          return 'q';
        }  
      }
      else if (m[pointer] == '-'){
        return 'o';
      }
    }   
  }

  else if (m[pointer] == '-'){
    return 'o';
  }
}

int timedelay;
int passes = 0;
int loopcounter = 0;
int delayLength = 10;
char morse [100] = "";
void loop() {
  timedelay = readPot();
  // put your main code here, to run repeatedly:
  blinkLED();
  if (irValue() == 1){
    Serial.print("True");
    if (passes > delayLength*5){
      morse[loopcounter] = '/';
    }
    else if (passes > delayLength){
      morse[loopcounter] = '-';
    }
    else{
      morse[loopcounter] = '.';
    }
    loopcounter ++;
    passes = 0;
  }
  passes ++;
  Serial.print(loopcounter);
  Serial.print(" ");
  Serial.print(passes);
  Serial.println(morse);
  //delay(timedelay);
  }

bool irValue(){
  return (!digitalRead(2));
}

void blinkLED(){
  readPot();
  blue_on();
  delay(readPot());
  blue_off();
  delay(readPot());
  
}

bool buttonPressed(){
   return digitalRead(3);
}
int readPot(){
   return analogRead(A0);
   
 }

void yellow_on(){
  digitalWrite(9,HIGH);
}
void yellow_off(){
  digitalWrite(9,LOW);
}
  
void ir_on(){
  digitalWrite(A1,HIGH);
}  
void ir_off(){
  digitalWrite(A1,LOW);
}

void blue_on(){
  digitalWrite(11,HIGH);
}
void blue_off(){
  digitalWrite(11,LOW);
}

void red_on(){
  digitalWrite(5,HIGH);
}

void red_off(){
  digitalWrite(5,LOW);
}
