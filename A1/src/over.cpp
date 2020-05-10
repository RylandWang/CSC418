#include "over.h"
#include <iostream>

void over(
    const std::vector<unsigned char> &A,
    const std::vector<unsigned char> &B,
    const int &width,
    const int &height,
    std::vector<unsigned char> &C)
{
  C.resize(A.size());

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      int index = i * width + j;

      double alpha = A[index * 3 + 3] ? 1 : 0; 
      
      // A[index * 3 + 3]) ? (B[index * 3 + 3] + A[index * 3 + 3]) : 1);

      // if (alpha)
      // std::cout<< alpha << "\n";; 

      C[index * 3] = alpha * A[index * 3] + (1 - alpha) * B[index * 3];
      C[index * 3 + 1] = alpha * A[index * 3 + 1] + (1 - alpha) * B[index * 3 + 1];
      C[index * 3 + 2] = alpha * A[index * 3 + 2] + (1 - alpha) * B[index * 3 + 2];
      C[index * 3 + 3] = A[index * 3 + 3] + (1 - alpha) * B[index * 3 + 3];
    }
  }
}
