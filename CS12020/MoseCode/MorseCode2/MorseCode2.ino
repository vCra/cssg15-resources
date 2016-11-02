
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
  String testString = "morse code ";
  Serial.print(string2morse(testString));
  //Serial.print(morse2string("..../"));
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

//void morse2led(String a){
//
//  //Serial.print(a);
//  int pointer = 0 ;
//  // char lastChar = 'a';
//  char x;
//  for(int pointer = 0; pointer < a.length(); pointer ++){ 
//    x = a[pointer];
//    //Serial.print(pointer);
//    //Serial.print("+");
//    output = output + char2morse(x);
//    if ((a[pointer]==' ')||(a[pointer+1]==' ')){
//      ;
//    }
//    else{
//      output = output + ("/");
//    }
////    if (char2morse(a[pointer]) == "!"){
////      break;
////    }
////    //Serial.print(a[pointer]);
////    // lastChar = a[pointer +1];
////    pointer = pointer +1; 
////    delay(10);
////    Serial.print(" ");
//  }
//  return output;
//}

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
  }
  else if (m[pointer] == '-'){
    return 'o';
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
