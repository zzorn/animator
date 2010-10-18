/*
  animator.h - Library for animating properties.
  Created by Hans Häggström, 2010.
  Released under the new BSD license.

  Useful for various smoothly blinking leds, rgb led animation sequences, servo animations, sound wave generation, and many other things.
*/

#ifndef animator_h
#define animator_h

// Include arduino default lib
#include "WProgram.h"


typedef long (*ContinuousFunction) (long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
typedef long (*ChangeFunction) (long timeSinceStart_ms, long startValue, long targetValue);

//AnimationFunction numeral[10] = {zero,one,two,three,four,five,six,seven,eight,nine};

// Continuous functions
long pause(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long sine(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long square(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long sawtooth(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long pinkNoise(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long brownNoise(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long whiteNoise(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);
long noise(long timeSinceStart_ms, long startValue, long wavelength, long amplitude);

// Change functions
long jump(long timeSinceStart_ms, long startValue, long targetValue);
long slide(long timeSinceStart_ms, long startValue, long targetValue);
long smooth(long timeSinceStart_ms, long startValue, long targetValue);
long snap(long timeSinceStart_ms, long startValue, long targetValue);
long bounce(long timeSinceStart_ms, long startValue, long targetValue);
long wave(long timeSinceStart_ms, long startValue, long targetValue);
long randomWalk(long timeSinceStart_ms, long startValue, long targetValue);
long speed(long timeSinceStart_ms, long startValue, long targetValue);
long brake(long timeSinceStart_ms, long startValue, long targetValue);

class Property
{
  public:
    Property(int initialValue);

    int get();
    void set(int newValue);

    void setMin(int minValue);
    void setMax(int maxValue);
    void setRange(int minValue, int maxValue);
    void setRepeat(bool repeating);

    void setPwmScaling(int division, int shift);
    void setAutomaticPwmScaling(); // Scales based on current range.
    void setPwmOutPin(int pwmPin);
    void detachPwmOutPin();

    Property animate(ContinuousFunction function);
    Property animate(ContinuousFunction function, long duration_ms);
    Property animate(ContinuousFunction function, long duration_ms, long wavelength_ms);
    Property animate(ContinuousFunction function, long duration_ms, long wavelength_ms, int amplitude);

    Property animateTo(int target);
    Property animateTo(int target, long duration_ms);
    Property animateTo(int target, long duration_ms, ChangeFunction changeFunction);
    Property animateTo(int target, long duration_ms, ChangeFunction startChange, ChangeFunction endChange);

    // Copy another property but apply some filter function
    // Fade between two other properties using a change function
    // Mix two other properties using a continous function

    // Change this property by another property

    // Follow another property with some inertia, acceleration, friction, etc - can this be implemented simply using some other functions?

    bool isFinished();
    void waitUntilFinished();
    void stop();

    void pause();
    void resume();
    void setPaused(bool paused);

    void update(long millisecondsSinceLastCall);
    static void updateAll(long time);
    static void updateAll();

// Animate to

// 

  private:
    int _value;
};

#endif

