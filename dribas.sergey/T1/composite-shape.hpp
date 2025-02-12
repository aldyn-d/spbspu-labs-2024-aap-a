#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace dribas
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& shp) noexcept = default;
    CompositeShape(CompositeShape&& shp) noexcept = default;
    CompositeShape & operator=(const CompositeShape & shp) noexcept = default;
    CompositeShape & operator=(CompositeShape && shp) noexcept = default;
    ~CompositeShape();
    Shape * operator[](size_t id);

    double getArea() const noexcept;
    rectangle_t getFrameRect() const;
    void push_back(Shape * shp);
    Shape * at(size_t id);
    void pop_back();
    bool empty() const noexcept;
    size_t size() const noexcept;
    void move(point_t point);
    void move(double x, double y);
    void scale(double ratio);
  private:
    Shape* shapes_[10000];
    size_t size_;
  };
}
#endif
