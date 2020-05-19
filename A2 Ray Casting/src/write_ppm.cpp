#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
      (num_channels == 3 || num_channels == 1) &&
      ".ppm only supports RGB or grayscale images");

  std::ofstream file(filename, std::ios::binary);
  int color = 255;

  // https://stackoverflow.com/questions/28896001/read-write-to-ppm-image-file-c
  file << "P6"
       << "\n"
       << width << " "
       << height << "\n"
       << color << "\n";

  // 3 channel rgb image
  if (num_channels == 3)
  {

    for (int i = 0; i < data.size(); i++)
    {
      file << data[i];
    }
    file.close();
    return true;
  }
  // 1 channel image
  else if (num_channels == 1)
  {

    for (int i = 0; i < data.size() * 3; i++)
    {
      file << data[i / 3];
    }

    file.close();
    return true;
  }
  return false;
}
