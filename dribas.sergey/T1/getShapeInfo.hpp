#ifndef GETSHAPEINFO_HPP
#define GETSHAPEINFO_HPP

#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace dribas
{
  size_t getShapeInfo(std::istream& input, std::ostream& error, Shape** Shapes, double* scalingFactor);
  void clear(Shape ** myshape, size_t shapeCount);
  double getAllArea(const Shape* const* shapes, size_t shapeCount);
  void scalingAll(Shape** shapes, size_t shapeCount, point_t center, double ratio);
  void scaleOne(Shape& t, double ratio, point_t Point);
}
#endif
