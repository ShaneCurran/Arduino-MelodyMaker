// The pin the piezo speaker is connected to
int speaker = 9;

// The pin our beat lead is connected to
int ledPin = 13;

// The number of notes in the melody
int length = 15;

// The notes of the melody (a space indicates a rest in the notes)
// The default notes (below) are Twinkle Twinkle Little Star :P
char notes[] = "ccggaagffeeddc "; 

// The beat length for each note
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };

// The tempo of the melody
// higher = slower
int tempo = 200;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speaker, HIGH);
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speaker, LOW);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  pinMode(speaker, OUTPUT);
}

void loop() {
  for (int x = 0; x < length; x++) {
    if (notes[x] == ' ') {
      delay(beats[x] * tempo); // Take a rest
    } else {
      playNote(notes[x], beats[x] * tempo);
    }

    // Pause between each note
    delay(tempo / 2); 
  }
}
