#include "rgb_to_hsv.h"
#include <cmath>

void rgb_to_hsv(
    const double r,
    const double g,
    const double b,
    double &h,
    double &s,
    double &v)
{

// http://www.faculty.jacobs-university.de/llinsen/teaching/320322_Fall2009/lecture11.pdf
double min =  (r < g) ? (r < b ? r : b) : (g < b ? g : b);
double max = (r > g) ? (r > b ? r : b) : (g > b ? g : b);

v = max;

if (max == 0)
    s = 0;
else
    s = 1 - (min/max);

if (max == min)
    h = 0;
else if (max == r) 
    h = fmod((60 * (g-b)/(max-min)), 360);
else if (max == g)
    h = 60*(b-r)/(max-min) + 120;
else if (max == b) 
    h = 60 * (r-g) / (max-min) + 240;

   
}
