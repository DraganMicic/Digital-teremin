import processing.serial.*;

Serial myPort;

int in;
int mem;
int hird;
int lord;
int frekvencija;

void setup() {
  //size(200, 1000);
  //background(#FFFFFF);
  //fill(0, 0, 0);
  
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[1], 57600);
}

void draw() {
  
  while (myPort.available() > 0) {

  in = myPort.read();   
  //println(in);
  
  if(in == 1){
    mem = 1;}
  if(in == 2){
    mem = 2;}
  if(in != 2 && in != 1 && mem == 1){
    hird = in;}
  if(in != 2 && in != 1 && mem == 2){
    lord = in;}
    
  if(in ==1) {
    frekvencija = (256*hird + lord - 1000)/(8);
    println(frekvencija);}
    
    
   /* println(hird);
    println(lord);*/
  
    
    
  
  }
}