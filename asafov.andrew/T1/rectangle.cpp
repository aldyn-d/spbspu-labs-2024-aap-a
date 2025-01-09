#include "rectangle.hpp"
#include <cmath>

using asafov::point_t;
using asafov::rectangle_t;

asafov::Rectangle::Rectangle(point_t a, point_t b):
lb(a), rt(b)
{}

double asafov::Rectangle::getArea() const
{
  return pow((lb.x - rt.x)*(lb.x - rt.x), 0.5) * pow((lb.y - rt.y)*(lb.y - rt.y), 0.5);
}

rectangle_t asafov::Rectangle::getFrameRect() const
{
  rectangle_t frect;
  frect.height = rt.y - lb.y;
  frect.width = rt.x - lb.x;
  frect.pos.x = lb.x + (rt.x - lb.x) / 2.0;
  frect.pos.y = lb.y + (rt.y - lb.y) / 2.0;
  return frect;
}

void asafov::Rectangle::move(double x, double y)
{
  lb.x += x;
  rt.x += x;
  lb.y += y;
  rt.y += y;
}

void asafov::Rectangle::move(point_t pos)
{
  rectangle_t rect = getFrameRect();
  double temp = pos.x - rect.pos.x;
  lb.x += temp;
  rt.x += temp;
  temp = pos.y - rect.pos.y;
  lb.y += temp;
  rt.y += temp;
}

void asafov::Rectangle::scale(double scale)
{
  rectangle_t rect = getFrameRect();
  rt.x += (rt.x - rect.pos.x) * (scale - 1.0);
  rt.y += (rt.y - rect.pos.y) * (scale - 1.0);
  lb.x += (lb.x - rect.pos.x) * (scale - 1.0);
  lb.y += (lb.y - rect.pos.y) * (scale - 1.0);
}
