/*
  animator.h - Library for animating properties.
  Created by Hans Häggström, 2010.
  Released under the new BSD license.

  Useful for various smoothly blinking leds, rgb led animation sequences, servo animations, sound wave generation, and many other things.
*/

/*

Types of animations:

- continuous, e.g. random function or noise - can be seen as consisting of a sequence of sequential ones
  - wave - a repeating wave of some shape.
- parametrized - using some input value as the goal or other parameter - enough if this can be configured from the arduino program
- value change over time - change the value to a target value over some time in some way




A change function takes as parameter the relative position on the change, and the start and end values.

A wave function takes as parameter the time since start, the start value, the wavelength, and the amplitude




Values of a property could be connected directly to some output ports later, or just read manually.

*/


#ifndef animator_h
#define animator_h

// Include arduino default lib
#include "WProgram.h"


typedef long (*ContinuousFunction) (long, long, long, long);
typedef long (*ChangeFunction) (long, long, long );

//AnimationFunction numeral[10] = {zero,one,two,three,four,five,six,seven,eight,nine};

// Continuous functions
long pause(long t, long startValue, long wavelength, long amplitude);
long sine(long t, long startValue, long wavelength, long amplitude);
long square(long t, long startValue, long wavelength, long amplitude);

/* TODO: Implement
long sawtooth(long t, long startValue, long wavelength, long amplitude);
long pinkNoise(long t, long startValue, long wavelength, long amplitude);
long brownNoise(long t, long startValue, long wavelength, long amplitude);
long whiteNoise(long t, long startValue, long wavelength, long amplitude);
long noise(long t, long startValue, long wavelength, long amplitude);
*/

// Change functions
long jump(long t, long startValue, long targetValue);
long slide(long t, long startValue, long targetValue);

/* TODO: Implement
long smooth(long t, long startValue, long targetValue);
long snap(long t, long startValue, long targetValue);
long bounce(long t, long startValue, long targetValue);
long wave(long t, long startValue, long targetValue);
long randomWalk(long t, long startValue, long targetValue);
long speed(long t, long startValue, long targetValue);
long brake(long t, long startValue, long targetValue);
*/

class Property
{
  public:
    Property(long initialValue);
    Property(long initialValue, long min, long max);

    long get();
    void set(long newValue);

/* TODO: Implement
    void setMin(int minValue);
    void setMax(int maxValue);
    void setRange(int minValue, int maxValue);
*/    

/* TODO: Implement
    void setPwmScaling(int division, int shift);
    void setAutomaticPwmScaling(); // Scales based on current range.
    void setPwmOutPin(int pwmPin);
    void detachPwmOutPin();
*/    

/* TODO: Implement
    Property animate(ContinuousFunction function);
    Property animate(ContinuousFunction function, long duration_ms);
    Property animate(ContinuousFunction function, long duration_ms, long wavelength_ms);
    Property animate(ContinuousFunction function, long duration_ms, long wavelength_ms, int amplitude);
    Property animate(ContinuousFunction function, long duration_ms, long wavelength_ms, int amplitude, int offset);
*/

/* TODO: Implement
    Property animateTo(int target);
    Property animateTo(int target, long duration_ms);
    Property animateTo(int target, long duration_ms, ChangeFunction changeFunction);
*/
    Property animateTo(int target, long duration_us, ChangeFunction startChange, ChangeFunction endChange);

    Property animate(Animation animation);

    // Copy another property but apply some filter function
    // Fade between two other properties using a change function
    // Mix two other properties using a continous function

    // Change this property by another property

    // Follow another property with some inertia, acceleration, friction, etc - can this be implemented simply using some other functions?

/*
    void waitUntilFinished();
*/

    void setRepeat(bool repeating);
/*
    void pause();
    void resume();
    void setPaused(bool paused);
*/

    bool isFinished();
    void stop();
    

/*
    static void updateAll();
*/

// Animate to

// 

  private:
    long _scaling = 1024;
    long _value = 0;
};


abstract class Animation {
  public:
  
    long calculateValue(long currentTime, long timeSinceLastUpdate);


}


#endif

