#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
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

      // convert to hsv, adjust saturation, the convert back to rgb
      rgb_to_hsv(r, g, b, h, s, v);
      s *= factor;
      hsv_to_rgb(h, s, v, r, g, b);
      desaturated[index * 3] = r;
      desaturated[(index)*3 + 1] = g;
      desaturated[(index)*3 + 2] = b;
    }
  }
}
