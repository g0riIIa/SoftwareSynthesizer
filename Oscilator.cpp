#include "Oscilator.h"

enum Wave
{
    SINE    = 0,
    SQURE   = 1,
    SAW     = 2,
    TRIANGLE= 3,
    NOISE   = 4,
};

/*
void Oscillator::midiOn(int midiNoteNumber, double hostSampleRate) {
    midiInput = true;
    n = 0;
    f = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    p = hostSampleRate / f;
}

void Oscillator::midiOff() {
    midiInput = false;
}
 */

double Oscillator::get(int wave) {
    if (!midiInput) { return 0.0; }
    
    switch(wave){
        case SINE:
            return sin(2.0 * double_Pi * n / p);
            break;
            
        case SQURE:
            return sin(2.0 * double_Pi * n / p);
            break;
            
        case SAW:
            return (n / p) * 2.0 - 1.0;
            break;
            
        case TRIANGLE:
            if (n / p >= 0.5) return 1 - (4.0 * ((n / p) - 0.5));
            else return (4.0 * n / p) - 1;
            break;
            
        case NOISE:
            Random rnd;
            return (rnd.nextDouble() * 2.0 - 1) * 0.5;
            break;
    }
}

void Oscillator::phaseIncrement() {
    if (++n >= p) { n = n - int(n / p) * p; }
}
