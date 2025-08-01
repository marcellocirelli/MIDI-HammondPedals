#include <MIDIUSB.h>
#include <Bounce2.h>

// Pins
const uint8_t keyPins[12] = {A5, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const uint8_t stompPins[3] = {A0, A1, A2};
const uint8_t potPins[2] = {A3, A4};

// MIDI CCs and Notes
const uint8_t keyNotes[12] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59};
const uint8_t stompCCs[3] = {16, 17, 18};
const uint8_t potCCs[2] = {64, 19};

int lastPotVals[2] = {0, 0};
uint8_t midiChannel = 3;
uint8_t threshold = 2;

Bounce keyDebouncers[12];
Bounce stompDebouncers[3];

void sendCC(uint8_t cc, uint8_t val, uint8_t ch) {
  midiEventPacket_t event = {0x0B, uint8_t(0xB0 | (ch - 1)), cc, val};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

void sendNoteOn(uint8_t note, uint8_t vel, uint8_t ch) {
  midiEventPacket_t event = {0x09, uint8_t(0x90 | (ch - 1)), note, vel};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

void sendNoteOff(uint8_t note, uint8_t vel, uint8_t ch) {
  midiEventPacket_t event = {0x08, uint8_t(0x80 | (ch - 1)), note, vel};
  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}

void setup() {

  for (int i = 0; i < 12; i++) {
    pinMode(keyPins[i], INPUT_PULLUP);
    keyDebouncers[i].attach(keyPins[i]);
    keyDebouncers[i].interval(5);
  }

  for (int i = 0; i < 3; i++) {
    pinMode(stompPins[i], INPUT_PULLUP);
    stompDebouncers[i].attach(stompPins[i]);
    stompDebouncers[i].interval(20);
  }

  for (int i = 0; i < 2; i++) {
    lastPotVals[i] = map(analogRead(potPins[i]), 0, 1023, 0, 127);
  }
}

void loop() {
  for (int i = 0; i < 12; i++) {
    keyDebouncers[i].update();
    if (keyDebouncers[i].rose()) {
      sendNoteOn(keyNotes[i], 127, midiChannel);
    }
    if (keyDebouncers[i].fell()) {
      sendNoteOff(keyNotes[i], 0, midiChannel);
    }
  }

  for (int i = 0; i < 3; i++) {
    stompDebouncers[i].update();
    if (stompDebouncers[i].fell() || stompDebouncers[i].rose()) {
      sendCC(stompCCs[i], 127, midiChannel);
      sendCC(stompCCs[i], 0, midiChannel);
    }
  }

  for (int i = 0; i < 2; i++) {
    int currentVal = map(analogRead(potPins[i]), 0, 1023, 0, 127);
    if (abs(currentVal - lastPotVals[i]) > threshold) {
      sendCC(potCCs[i], currentVal, midiChannel);
      lastPotVals[i] = currentVal;
    }
  }
}