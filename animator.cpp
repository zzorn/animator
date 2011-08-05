/*
  animator - Library for animating properties.
  Created by Hans Häggström, 2010.
  Released under the new BSD license.

  Useful for various smoothly blinking leds, rgb led animation sequences, servo animations, sound wave generation, and many other things.
*/

#include <math.h>
#include "animator.h"

#define PI  3.14159265
#define TAU 6.28318530

#define PROGRESS_SCALE 1024

// Continuous functions
long pause(long t, long startValue, long wavelength, long amplitude) {return startValue; }
long sine(long t, long startValue, long wavelength, long amplitude) {return startValue + sin(TAU * t / wavelength) * amplitude; }
long square(long t, long startValue, long wavelength, long amplitude) {return startValue + (t % wavelength) > wavelength / 2 ? amplitude / 2 : -amplitude / 2;}

// Change functions
long jump(long t, long startValue, long targetValue) {return targetValue; }
long slide(long t, long startValue, long targetValue) {return (t * startValue + (PROGRESS_SCALE - t) * targetValue ) / PROGRESS_SCALE; }


class Property
{
  public:
    Property(long initialValue);
    Property(long initialValue, long min, long max);

    long get();
    void set(long newValue);

    void setRange(long minValue, long maxValue);

    Property animate(ContinuousFunction function, long duration_us, long wavelength_us, int amplitude);

    Property animateTo(int target, long duration_us, ChangeFunction startChange, ChangeFunction endChange);

    void setRepeat(bool repeating);

    bool isFinished();
    void stop();
    
  private:
    long _scaling = 1024;
    long _value = 0;
};

#endif

