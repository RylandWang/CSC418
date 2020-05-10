#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
    const std::vector<unsigned char> &rgb,
    const int &width,
    const int &height,
    std::vector<unsigned char> &bayer)
{
  bayer.resize(width * height);

  for (int i = 0; i < height - 1; i += 2)
  {
    for (int j = 0; j < width - 1; j += 2)
    {
      int index = i * width + j;
      // top left pixel - take green
      bayer[index] = rgb[(index * 3) + 1];
      //right neighbor - take blue
      bayer[index + 1] = rgb[((index + 1) * 3) + 2];
      //below neighbor - take red
      bayer[index + width] = rgb[(index + width)*3];
      // bottom right - take green
      bayer[index + width + 1] = rgb[(index + width + 1)*3 + 1];
    }
  }
}
