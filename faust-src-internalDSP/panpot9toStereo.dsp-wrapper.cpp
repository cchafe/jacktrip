//
// notes from CC
// see faust2jacktrip
// this file generated from jacktrip_faust.template
// use make to update the template
// and use jtHeaderMake <file>.dsp to generate this file

#ifndef __panpot9toStereo_H__
#define __panpot9toStereo_H__

#include <iostream>
#include <unistd.h>
//cc for random()
#include <cstdlib>

// any QT classes
#include <QTimer>

#include "ProcessPlugin.h"
#include "Faust.h"

/*
 * FAUST intrinsic
 */
<<includeIntrinsic>>

/*
 * FAUST defines UI values as private, but provides no getters/setters.
 * In our particular case it's way more convenient to access them directly
 * than to set up a complicated UI structure.  Also get rid of everything
 * being "virtual", since it may stop the compiler from inlining properly!
 */
#define private public
#define virtual

// definition of derived dsp class

/* Rename the class the name of our DSP. */
#define mydsp panpot9toStereodsp

/*
 * FAUST class
 */
<<includeclass>>


// our jacktrip dsp class, inheriting from ProcessPlugin and Faust dsp
class panpot9toStereo : public ProcessPlugin, public panpot9toStereodsp
{
    Q_OBJECT
public:
    panpot9toStereo(int nChans) : mNumChannels(nChans){}
    virtual ~panpot9toStereo() {}
    int getNumInputs() {return panpot9toStereodsp::getNumInputs();}
    int getNumOutputs() {return panpot9toStereodsp::getNumOutputs();}
    void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output)
      {panpot9toStereodsp::compute (count, input, output);}
    void instanceInit(int samplingFreq)
    {panpot9toStereodsp::instanceInit (samplingFreq);}
private:
    int mNumChannels;
};

// always undefine this stuff for compatibility with the rest of the project compilations
#undef private
#undef virtual
#undef mydsp

  #endif // __panpot9toStereo_H__


