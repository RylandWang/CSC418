#include "rotate.h"

void rotate(
    const std::vector<unsigned char> &input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> &rotated)
{
  rotated.resize(height * width * num_channels);

  // rows
  for (int i = 0; i < height; i++)
  {
    // columns
    for (int j = 0; j < width; j++)
    {
      // rgb
      for (int k = 0; k < num_channels; k++)
      {
        // rotate 90 degrees counterclockwise
        int index = (i * width + j) * 3;
        rotated[index + k] = input[(i  + (height - j - 1)*width) * 3 + k];
      }
    }
  }
}