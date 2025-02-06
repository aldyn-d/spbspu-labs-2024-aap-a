#include "processShapes.hpp"
#include <iostream>

double smirnov::sumArea(const Shape * const * const shapes, size_t count)
{
  double sumArea = 0;
  for (size_t i = 0; i < count; i++)
  {
    sumArea += shapes[i]->getArea();
  }
  return sumArea;
}

void smirnov::destroyShapes(Shape ** shapes, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    delete shapes[i];
  }
}

void smirnov::printFrameRect(const Shape * const * const shapes,
    size_t count, std::ostream & out)
{
  for (size_t i = 0; i < count; i++)
  {
    rectangle_t rectangle = shapes[i]->getFrameRect();
    double x1 = rectangle.pos.x - rectangle.width / 2.0;
    double y1 = rectangle.pos.y - rectangle.height / 2.0;
    double x2 = rectangle.pos.x + rectangle.width / 2.0;
    double y2 = rectangle.pos.y + rectangle.height / 2.0;
    out << x1 << " " << y1 << " " << x2 << " " << y2;
    if (i != count - 1)
    {
      out << " ";
    }
  }
}

void smirnov::scaleShapes(Shape ** shapes, size_t count, point_t p, double factor)
{
  for (size_t i = 0; i < count; i++)
  {
    point_t startPos = shapes[i]->getFrameRect().pos;
    shapes[i]->move(p);
    shapes[i]->scale(factor);
    point_t newPos = shapes[i]->getFrameRect().pos;
    point_t vector;
    vector.x = (newPos.x - startPos.x);
    vector.y = (newPos.y - startPos.y);
<<<<<<< HEAD
    shapes[i]->scale(factor);
=======
>>>>>>> 180f519d0bd7990d0f245d2dcd03e4fec924302a
    shapes[i]->move(-vector.x, -vector.y);
  }
}

