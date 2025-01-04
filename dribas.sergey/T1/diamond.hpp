#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"
namespace dribas
{
  class Diamond final: public Shape
  {
  public:
    Diamond(point_t a, point_t b, point_t c);
    double getArea() const  override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double x, double y) override;
    void scale(double ratio) override;
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}
#endif
