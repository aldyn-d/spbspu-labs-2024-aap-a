#include "base-types.hpp"
#include <cmath>

double savintsev::getLength(point_t lhs, point_t rhs)
{
  return std::sqrt(std::pow((lhs.x - rhs.x), 2) + std::pow((lhs.y - rhs.y), 2));
}

bool savintsev::isPointInTriangle(point_t t1, point_t t2, point_t t3, point_t p)
{
  int part1 = (t1.x - p.x) * (t2.y - t1.y) - (t2.x - t1.x) * (t1.y - p.y);
  int part2 = (t2.x - p.x) * (t3.y - t2.y) - (t3.x - t2.x) * (t2.y - p.y);
  int part3 = (t3.x - p.x) * (t1.y - t3.y) - (t1.x - t3.x) * (t3.y - p.y);
  if (part1 > 0 && part2 > 0 && part3 > 0)
  {
    return true;
  }
  else if (part1 < 0 && part2 < 0 && part3 < 0)
  {
    return true;
  }
  return false;
}

bool savintsev::isTriangle(point_t p1, point_t p2, point_t p3)
{
  double l1 = getLength(p1, p2);
  double l2 = getLength(p2, p3);
  double l3 = getLength(p3, p1);
  double largest = std::fmax(l1, std::fmax(l2, l3));
  return largest < (l1 + l2 + l3 - largest);
}

savintsev::point_t savintsev::findLinesIntersect(point_t m1, point_t m2, point_t n1, point_t n2, bool * finded)
{
  double a1 = m2.y - m1.y;
  double b1 = m1.x - m2.x;
  double c1 = a1 * (m1.x) + b1 * (m1.y);
  double a2 = n2.y - n1.y;
  double b2 = n1.x - n2.x;
  double c2 = a2 * (n1.x) + b2 * (n1.y);
  double determinant = a1 * b2 - a2 * b1;
  if (determinant == 0)
  {
    if (finded != nullptr)
    {
      *finded = false;
    }
    return {0., 0.};
  }
  else
  {
    double x = (b2 * c1 - b1 * c2) / determinant;
    double y = (a1 * c2 - a2 * c1) / determinant;
    if (finded != nullptr)
    {
      *finded = true;
    }
    return {x, y};
  }
}

double savintsev::getTriangleArea(point_t p1, point_t p2, point_t p3)
{
  double l1 = getLength(p1, p2);
  double l2 = getLength(p2, p3);
  double l3 = getLength(p3, p1);
  double per = (l1 + l2 + l3) / 2.;
  return std::sqrt(per * (per - l1) * (per - l2) * (per - l3));
}
