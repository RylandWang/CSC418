#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
    const double h,
    const double s,
    const double v,
    double &r,
    double &g,
    double &b)
{

  // http://www.faculty.jacobs-university.de/llinsen/teaching/320322_Fall2009/lecture11.pdf

  double i = fmod(floor(h / 60), 6);
  double f = h / 60 - floor(h / 60);

  double p = v * (1 - s);
  double q = v * (1 - f * s);
  double t = v * (1 - (1 - f) * s);

  if (i == 0)
  {
    r = v;
    g = t;
    b = p;
  }
  else if (i == 1){
    r = q;
    g = v;
    b = p;
  }
  else if (i == 2){
    r  = p;
    g = v;
    b = t;
  }
  else if (i == 3) {
    r = p;
    g = q;
    b = v;
  }
  else if (i == 4) {
    r = t;
    g = p;
    b = v;
  }
  else if (i == 5){
    r = v;
    g = p;
    b = q;
  }
}
