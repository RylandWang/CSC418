#include "rgb_to_gray.h"

void rgb_to_gray(
    const std::vector<unsigned char> &rgb,
    const int width,
    const int height,
    std::vector<unsigned char> &gray)
{
  gray.resize(height * width);

  // rows
  for (int i = 0; i < height; i++)
  {
    // columns
    for (int j = 0; j < width; j++)
    {
      int index = (i * width + j);
      // calculate weighted average of rgb values
      float grayscale = (rgb[index * 3] * 0.2126 + rgb[index * 3 + 1] * 0.7152 + rgb[index * 3 + 2] * 0.0722);
      gray[index] = grayscale;
    }
  }
}