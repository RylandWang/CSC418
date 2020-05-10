#include "reflect.h"
#include <iostream>

void reflect(
    const std::vector<unsigned char> &input,
    const int width,
    const int height,
    const int num_channels,
    std::vector<unsigned char> &reflected)
{
  reflected.resize(width * height * num_channels);

  for (int i = 0; i < height; i++)
  {
    // reverse pixels in each row
    for (int j = 0; j < width; j++)
    {
      int skip_rows = i * width;
      int index = (skip_rows + j) * 3;
      int reverse_row_index = (skip_rows + width - j) * 3;

      // map to pixel on opposite side of same row
      reflected[index] = input[reverse_row_index];
      reflected[index + 1] = input[reverse_row_index + 1];
      reflected[index + 2] = input[reverse_row_index + 2];
    }
  }
}
