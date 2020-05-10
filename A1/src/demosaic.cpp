#include "demosaic.h"

void demosaic(
    const std::vector<unsigned char> &bayer,
    const int &width,
    const int &height,
    std::vector<unsigned char> &rgb)
{
  rgb.resize(width * height * 3);

  // linear interpolation on pixels
  for (int i = 1; i < height - 1; i++)
  {
    for (int j = 1; j < width - 1; j++)
    {
      int index = width * i + j;

      float red = 0;
      float green = 0;
      float blue = 0;

      if ((i + j) % 2 == 0)
      {
        // green corners
        green += bayer[(index - width - 1)]; // top left
        green += bayer[(index - width + 1)]; // top right
        green += bayer[(index + width - 1)]; // bottom left
        green += bayer[(index + width + 1)]; // bottom right
      }
      else if (i % 2 == 0)
      {
        // red corner neighbors
        red += bayer[(index - width - 1)]; // top left
        red += bayer[(index - width + 1)]; // top right
        red += bayer[(index + width - 1)]; // bottom left
        red += bayer[(index + width + 1)]; // bottom right

        // // green adjacent
        // green += bayer[(index - width)]; // top 
        // green += bayer[(index + width)]; // bottom
        // green += bayer[(index - 1)];     //  left
        // green += bayer[(index + 1)];     //  right
      }
      else
      {
        // blue corner neighbors
        blue += bayer[(index - width - 1)]; // top left
        blue += bayer[(index - width + 1)]; // top right
        blue += bayer[(index + width - 1)]; // bottom left
        blue += bayer[(index + width + 1)]; // bottom right
      }

      rgb[index * 3] = red / 4;
      rgb[index * 3 + 1] = green / 4;
      rgb[index * 3 + 2] = blue / 4;
    }
  }
}
