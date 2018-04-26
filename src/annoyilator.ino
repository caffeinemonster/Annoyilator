// The Annoyilator.
// With the correct settings and right placement this device will quickly drive its target bonkers.
// Great fun and an ideal starter project. 
// Project was designed and tested using the arduino nano.
// You will need 1x piezo electric buzzer (3-5v) (Different types can be found in many low cost consumer devices, clocks, radios, anything that beeps.)
// Connect the GND (Black or Brown wire) to the GND connention on the arduino.
// Connect the V+ / positive (White or Red) to pin number 9 on your arduino.
// That's it edit the variabls below and upload.
// Have fun finding the perfect settings.
// http://hakology.co.uk/
// http://twitter.com/hakology
// http://youtube.com/hakology
// Coding powered by caffeine.

// define pins
int ledPin = 13;                
int pinSpeaker = 9;

// define program variables
// amount of beeps
int beeps = 32;

// length of beeps
int minlength = 100;
int maxlength = 100;

// frequency range
int minfreq = 180;
int maxfreq = 2600;

// pause between beeps (ms)
int minpause = 50;
int maxpause = 100;

// rest for x seconds after beeps
long minrest = 15 * 1000;     
long maxrest = 60 * 1000;

// arduino initialisation
void setup() {
  pinMode(ledPin, OUTPUT); // initialise LED pin
  pinMode(pinSpeaker, OUTPUT); // initialise speaker pin 
  Serial.begin(9600); // enable serial for debugging
}

// main program loop
void loop(){
    digitalWrite(ledPin, 1);
    for (int i = 0; i < beeps; i++){
      playTone(random(minlength,maxlength), random(minfreq, maxfreq));
      delay(random(minpause, maxpause)); 
    }
    digitalWrite(ledPin, 0);
    delay(random(minrest, maxrest));
}

// function to play tones
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(pinSpeaker,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}

