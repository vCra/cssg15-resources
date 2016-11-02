
// Morse chars defined
String morse_a[] = ".-";
String morse_b[] = "-...";
String morse_c[] = "-.-.";
String morse_d[] = "-..";
String morse_e[] = ".";
String morse_f[] = "..-.";
String morse_g[] = "--.";
String morse_h[] = "....";
String morse_i[] = "..";
String morse_j[] = ".---";
String morse_k[] = "-.-";
String morse_l[] = ".-..";
String morse_m[] = "--";
String morse_n[] = "-.";
String morse_o[] = "---";
String morse_p[] = ".--.";
String morse_q[] = "--.-";
String morse_r[] = ".-.";
String morse_s[] = "...";
String morse_t[] = "-";
String morse_u[] = "..-";
String morse_v[] = "...-";
String morse_w[] = ".--";
String morse_x[] = "-..-";
String morse_y[] = "-.--";
String morse_z[] = "--..";
String space[]   = "  ";


void setup() {
  // put your setup code here, to run once:*
  Serial.begin(9600);
  String testString = "morse code ";
  string2morse(testString);
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
    strcat(output,(char2morse(x)));
    if ((a[pointer]==' ')||(a[pointer+1]==' ')){
      ;
    }
    else{
      strcat(output,("/"));
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
  
}

String char2morse(char x){
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


void loop() {
  // put your main code here, to run repeatedly:

}
