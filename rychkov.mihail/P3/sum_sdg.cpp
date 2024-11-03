#include "get_max_sum_sdg.hpp"

int rychkov::getMaxSumSdg(int* matrix, size_t height, size_t width)
{
  int result = getSumOfSdgWithCell(matrix, height, width, 0, 0);
  for (size_t i = 1; i < height; i++)
  {
    int curSum = getSumOfSdgWithCell(matrix, height, width, i, 0);
    result = (result >= curSum ? result : curSum);
  }
  for (size_t i = 1; i < width; i++)
  {
    int curSum = getSumOfSdgWithCell(matrix, height, width, 0, i);
    result = (result >= curSum ? result : curSum);
  }
  return result;
}

int getSumOfSdgWithCell(int* matrix, size_t height, size_t width, size_t basisY, size_t basisX)
{
  if(basisY >= basisX)
  {
    basisY -= basisX;
  }
  else
  {
    basisX -= basisY
  }
  
  int result = 0;
  for (; (basisY < height) && (basisX < width); basisY++, basisX++)
  {
    result += matrix[basisY * width + basisX];
  }
  return result;
}
