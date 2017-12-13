#pragma once

#include "JuceHeader.h"

class Oscillator {
public:
    //void midiOn(int midiNoteNumber, double hostSampleRate);
    //void midiOff();
    double get(int wave);
    void phaseIncrement();
    
private:
    bool midiInput = false;
    double n = 0;
    double f = 440;
    double p = 100;
};
