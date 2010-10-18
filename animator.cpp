/*
  animator - Library for animating properties.
  Created by Hans Häggström, 2010.
  Released under the new BSD license.

  Useful for various smoothly blinking leds, rgb led animation sequences, servo animations, sound wave generation, and many other things.
*/

#include "animator.h"


// Continuous functions
long pause(long timeSinceStart_ms, long startValue, long wavelength, long amplitude) {return startValue; }
long sine(long timeSinceStart_ms, long startValue, long wavelength, long amplitude) {return sin(timeSinceStart_ms) }
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
    void setLimits(int minValue, int maxValue);
    void setRepeat(bool repeating);

    Property animate(function: ContinuousFunction);
    Property animate(function: ContinuousFunction, long duration_ms);
    Property animate(function: ContinuousFunction, long duration_ms, long wavelength_ms);
    Property animate(function: ContinuousFunction, long duration_ms, long wavelength_ms, int amplitude);

    Property animateTo(target: int);
    Property animateTo(target: int, long duration_ms);
    Property animateTo(target: int, long duration_ms, changeFunction: ChangeFunction);
    Property animateTo(target: int, long duration_ms, startChange: ChangeFunction, endChange: ChangeFunction);

    // Copy another property but apply some filter function
    // Fade between two other properties using a change function
    // Mix two other properties using a continous function

    // Change this property by another property

    // Follow another property with some inertia, acceleration, friction, etc - can this be implemented simply using some other functions?

    void pause();
    void play();
    void stop();
    void clear();

    void update(long millisecondsSinceLastCall);

// Animate to

// 

  private:
    int _value;
};

#endif

