#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
    const std::vector<unsigned char> &rgb,
    const int width,
    const int height,
    const double shift,
    std::vector<unsigned char> &shifted)
{
  shifted.resize(rgb.size());
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int index = width * i + j;
      double h, s, v;
      double r, g, b;

      r = rgb[index * 3];
      g = rgb[index * 3 + 1];
      b = rgb[index * 3 + 2];

      // convert to hsv, adjust hue, the convert back to rgb
      rgb_to_hsv(r, g, b, h, s, v);
      h += shift;
      hsv_to_rgb(h, s, v, r, g, b);
      shifted[index * 3] = r;
      shifted[(index)*3 + 1] = g;
      shifted[(index)*3 + 2] = b;
    }
  }
}
