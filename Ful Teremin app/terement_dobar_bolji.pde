
import processing.serial.*;
import processing.sound.*;

Serial myPort1;
Serial myPort2;

int in1;
int in2;
int mem1;
int mem2;
int hird1;
int lord1;
int hird2;
int lord2;
int frekvencija;
float vol;


SinOsc[] sineWaves; // Array of sines
float[] sineFreq; // Array of frequencies
int numSines =5; // Number of oscillators to use

void setup() {
  size(640, 360);
  background(255);
  
  printArray(Serial.list());
  myPort1 = new Serial(this, Serial.list()[2], 80000);
  myPort2 = new Serial(this, Serial.list()[1], 80000);
  
  sineWaves = new SinOsc[numSines]; // Initialize the oscillators
  sineFreq = new float[numSines]; // Initialize array for Frequencies

  for (int i = 0; i < numSines; i++) {
    // Calculate the amplitude for each oscillator
    float sineVolume = (1.0 / numSines) / (i + 1);
    // Create the oscillators
    sineWaves[i] = new SinOsc(this);
    // Start Oscillators
    sineWaves[i].play();
    // Set the amplitudes for all oscillators
    sineWaves[i].amp(sineVolume);
  }
    vol=11/10;
}


void draw() {
  while (myPort1.available() > 0) {
    in1 = myPort1.read();   
    if(in1 == 1){mem1 = 1;}
    if(in1 == 2){mem1 = 2;}
    if(in1 != 2 && in1 != 1 && mem1 == 1){hird1 = in1;}
    if(in1 != 2 && in1 != 1 && mem1 == 2){lord1 = in1;}
      
    if(in1 ==1) {frekvencija=((256*hird1 + lord1-1000)/10); 
    } }
    
    while (myPort2.available() > 0) {
    in2 = myPort2.read();   
    if(in2 == 1){mem2 = 1;}
    if(in2 == 2){mem2 = 2;}
    if(in2 != 2 && in2 != 1 && mem2 == 1){hird2 = in2;}
    if(in2 != 2 && in2 != 1 && mem2 == 2){lord2 = in2;}
      
  //  if(in2 ==1) {vol=((256*hird2 + lord2-1000)/100); 
   // }
  
}
  
 
 
  //float yoffset = map(frekvencija, 0, height, 0, 1);
  //Map mouseY logarithmically to 150 - 1150 to create a base frequency range
  //float frequency = pow(1000, yoffset) + 150;
  float frequency = frekvencija;
  //Use mouseX mapped from -0.5 to 0.5 as a detune argument
  float detune = map(mouseX, 0, width, -1, 10);
  
  for (int i = 0; i < numSines; i++) { 
    sineFreq[i] = frequency * (i + 1 * detune);
    // Set the frequencies for all oscillators
    sineWaves[i].freq(sineFreq[i]);
    sineWaves[i].amp(0.1);
  }
 // if (mousePressed){vol=vol + 0.001;}
  
 //println(frekvencija);

  println(vol);
  }  