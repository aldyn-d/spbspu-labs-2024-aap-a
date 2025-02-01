#include "composite-shape.hpp"

#include <limits>
#include <stdexcept>

#include "parallelogram.hpp"
#include "rectangle.hpp"
#include "square.hpp"

zholobov::CompositeShape::CompositeShape():
  items_(),
  items_num_(0)
{}

zholobov::CompositeShape::CompositeShape(const CompositeShape& other)
{
  for (items_num_ = 0; items_num_ < other.items_num_; ++items_num_) {
    Square* square = dynamic_cast< Square* >(other.items_[items_num_]);
    if (square != nullptr) {
      items_[items_num_] = new Square(*square);
    } else {
      Rectangle* rect = dynamic_cast< Rectangle* >(other.items_[items_num_]);
      if (rect != nullptr) {
        items_[items_num_] = new Rectangle(*rect);
      } else {
        Parallelogram* parallelogram = dynamic_cast< Parallelogram* >(other.items_[items_num_]);
        if (parallelogram != nullptr) {
          items_[items_num_] = new Parallelogram(*parallelogram);
        } else {
          throw std::invalid_argument("Unknown Shape type");
        }
      }
    }
  }
}

zholobov::CompositeShape::CompositeShape(CompositeShape&& other)
{
  for (size_t i = 0; i < other.items_num_; ++i) {
    items_[i] = other.items_[i];
  }
  items_num_ = other.items_num_;
  other.items_num_ = 0;
}

zholobov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < items_num_; ++i) {
    delete items_[i];
  }
}

void zholobov::CompositeShape::push_back(Shape* shape)
{
  if (items_num_ == max_elem_num) {
    throw std::out_of_range("CompositeShape storage is full");
  }
  items_[items_num_++] = shape;
}

void zholobov::CompositeShape::pop_back()
{
  if (items_num_ == 0) {
    throw std::out_of_range("CompositeShape storage is empty");
  }
  delete items_[--items_num_];
}

zholobov::Shape* zholobov::CompositeShape::at(size_t idx) const
{
  if (idx > items_num_) {
    throw std::out_of_range("idx out of range");
  }
  return items_[idx];
}

zholobov::Shape* zholobov::CompositeShape::operator[](size_t idx) const
{
  return items_[idx];
}

bool zholobov::CompositeShape::empty() const
{
  return items_num_ == 0;
}

size_t zholobov::CompositeShape::size() const
{
  return items_num_;
}

double zholobov::CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < items_num_; ++i) {
    sum += items_[i]->getArea();
  }
  return sum;
}

zholobov::rectangle_t zholobov::CompositeShape::getFrameRect() const
{
  double left = std::numeric_limits< double >::max();
  double right = std::numeric_limits< double >::min();
  double down = std::numeric_limits< double >::max();
  double up = std::numeric_limits< double >::min();

  for (size_t i = 0; i < items_num_; ++i) {
    rectangle_t cur_rect = items_[i]->getFrameRect();
    double cur_left = cur_rect.pos.x - cur_rect.width / 2.0;
    double cur_right = cur_rect.pos.x + cur_rect.width / 2.0;
    double cur_down = cur_rect.pos.y - cur_rect.height / 2.0;
    double cur_up = cur_rect.pos.y + cur_rect.height / 2.0;
    if (cur_left < left) {
      left = cur_left;
    }
    if (cur_right > right) {
      right = cur_right;
    }
    if (cur_down < down) {
      down = cur_down;
    }
    if (cur_up > up) {
      up = cur_up;
    }
  }
  return rectangle_t{right - left, up - down, {(right + left) / 2.0, (up + down) / 2.0}};
}

void zholobov::CompositeShape::move(point_t p)
{
  rectangle_t rect = getFrameRect();
  move(p.x - rect.pos.x, p.y - rect.pos.y);
}

void zholobov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < items_num_; ++i) {
    items_[i]->move(dx, dy);
  }
}

void zholobov::CompositeShape::scale(double k)
{
  rectangle_t rect = getFrameRect();
  for (size_t i = 0; i < items_num_; ++i) {
    items_[i]->scale(k);
    rectangle_t cur = items_[i]->getFrameRect();
    items_[i]->move((cur.pos.x - rect.pos.x) * k, (cur.pos.y - rect.pos.y) * k);
  }
}
