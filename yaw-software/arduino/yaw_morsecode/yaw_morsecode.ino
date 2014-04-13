/*
  A quick and dirty morse code generator for driving the 27 MHz transmitter.
  
  This code was done for NASA's International Space Apps Challenge 2014, https://2014.spaceappschallenge.org/
  and the "You Are WelCOMEe" project for the Distributed Ground Station Network, http://dgsn.aerospaceresearch.net
  
  This code is licensed unter the MIT License (MIT), copyright (c) 2014 Andreas HORNIG, Sebastian KÜHN
 */
 
// Pin 13 has an LED connected on most Arduino boards.
int led = 13;

String code[41][2];
int duration = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  codetable();  
}

void codetable() {
  //only capital letters!
  code[0][0] = "A";
  code[0][1] = "01";
  code[1][0] = "B";
  code[1][1] = "1000";
  code[2][0] = "C";
  code[2][1] = "1010";
  code[3][0] = "D";
  code[3][1] = "100";
  code[4][0] = "E";
  code[4][1] = "100";
  code[5][0] = "F";
  code[5][1] = "0010";
  code[6][0] = "G";
  code[6][1] = "110";
  code[7][0] = "H";
  code[7][1] = "0000";
  code[8][0] = "I";
  code[8][1] = "00";
  code[9][0] = "J";
  code[9][1] = "0111";
  code[10][0] = "K";
  code[10][1] = "101";
  code[11][0] = "L";
  code[11][1] = "0100";
  code[12][0] = "M";
  code[12][1] = "11";
  code[13][0] = "N";
  code[13][1] = "10";
  code[14][0] = "O";
  code[14][1] = "111";
  code[15][0] = "P";
  code[15][1] = "0110";
  code[16][0] = "Q";
  code[16][1] = "1101";
  code[17][0] = "R";
  code[17][1] = "010";
  code[18][0] = "S";
  code[18][1] = "000";
  code[19][0] = "T";
  code[19][1] = "1";
  code[20][0] = "U";
  code[20][1] = "001";
  code[21][0] = "V";
  code[21][1] = "0001";
  code[22][0] = "W";
  code[22][1] = "011";
  code[23][0] = "X";
  code[23][1] = "1001";
  code[24][0] = "Y";
  code[24][1] = "1011";
  code[25][0] = "Z";
  code[25][1] = "1100";
  //numbers
  code[26][0] = "0";
  code[26][1] = "11111";
  code[27][0] = "1";
  code[27][1] = "01111";
  code[28][0] = "2";
  code[28][1] = "00111";
  code[29][0] = "3";
  code[29][1] = "00011";
  code[30][0] = "4";
  code[30][1] = "00001";
  code[31][0] = "5";
  code[31][1] = "00000";
  code[32][0] = "6";
  code[32][1] = "10000";
  code[33][0] = "7";
  code[33][1] = "11000";
  code[34][0] = "8";
  code[34][1] = "11100";
  code[35][0] = "9";
  code[35][1] = "11110";
  // cyphers
  code[36][0] = ".";
  code[36][1] = "010101";
  code[37][0] = ",";
  code[37][1] = "110011";
  code[38][0] = "?";
  code[38][1] = "001100";
  code[39][0] = "'";
  code[39][1] = "011110";
  code[40][0] = "!";
  code[40][1] = "101011";
  // and wait, there is more.... later!
}

// the loop routine runs over and over again forever:
void loop() {
  
  String text = "space rocks!";
  text.toUpperCase();
  Serial.println(text);
  for(int i=0; i<text.length(); i++){
    String test = (String) text[i];
    morse(test);
  }
  delay(5*duration);
}

void morse(String test){
  String morsecode;
  int wasfound = 0;
  for(int i=0; i<41; i++){
    if(test==(String)code[i][0]){
      morsecode = (String) code[i][1];
      wasfound = 1;
    }
  }
  if(wasfound==1){
    Serial.print(test);
    beep(morsecode);
  } else{
    Serial.println("spacer");
    delay(3*duration);  //spacer
  }
}

void beep(String morsecode){
  Serial.println(morsecode);
  for(int i=0; i<morsecode.length(); i++){
    String length = (String)morsecode[i];
    signal(length.toInt());
  }
}

void signal(int length){
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(duration*(length+1));               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(duration); 
}
