#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace sveshnikov
{
  class Ellipse : public Shape
  {
  private:
    point_t center_;
    double vert_radius_;
    double horiz_radius_;

  public:
    Ellipse(point_t center, double vert_radius_, double horiz_radius_);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  };
}

#endif
