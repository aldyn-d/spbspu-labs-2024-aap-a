#include "parallelogram.hpp"
#include <cmath>
#include <stdexcept>

bocharov::Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3):
  pos_({(p1.x + p3.x) / 2.0, (p1.y + p3.y) / 2.0}),
  p1_({p1.x - pos_.x, p1.y - pos_.y}),
  p2_({p2.x - pos_.x, p2.y - pos_.y})
{
  if (!(((p1.y == p2.y) && (p1.y != p3.y)) || ((p2.y == p3.y) && (p1.y != p2.y))))
  {
    throw std::invalid_argument("Error in PARALLELOGRAM parameters");
  }
}
double bocharov::Parallelogram::getArea() const
{
  double base = 0.0;
  if (p1_.y == p2_.y)
  {
    base = p2_.x - p1_.x;
  }
  else
  {
    base = 2.0 * pos_.x - p2_.x - p1_.x;
  }
  return std::abs(base * p1_.y * 2.0);
}

bocharov::rectangle_t bocharov::Parallelogram::getFrameRect() const
{
  rectangle_t rect;
  rect.pos = pos_;
  rect.height = std::abs(p1_.y) * 2.0;
  rect.width = std::abs(p1_.x) * 2.0;
  return rect;
}

void bocharov::Parallelogram::move(point_t point)
{
  pos_ = point;
}

void bocharov::Parallelogram::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}

void bocharov::Parallelogram::scale(double ratio)
{
  p1_.x *= ratio;
  p1_.y *= ratio;
  p2_.x *= ratio;
  p2_.y *= ratio;
}
