// cpp code here
#include "Rectangle.h"

//Rectangle::Rectangle() {}
Rectangle::Rectangle(int l, int w) {
  length = l;
  width = w;
}
int Rectangle::get_length() const { return length; }
int Rectangle::get_width() const { return width; }
int Rectangle::get_area() const { return (length * width); }

bool Rectangle::operator<(Rectangle rhs) {
  bool lessthan = false;
  if (get_area() < rhs.get_area())
    lessthan = true;
  return lessthan;
}
bool Rectangle::operator>(Rectangle rhs) {
  bool greaterthan = false;
  if (get_area() > rhs.get_area())
    greaterthan = true;
  return greaterthan;
}
bool Rectangle::operator!=(Rectangle rhs) {
  bool notequals = false;
  if (get_area() != rhs.get_area())
    notequals = true;
  return notequals;
}
bool Rectangle::operator==(Rectangle rhs) {
  bool equals = false;
  if (get_area() == rhs.get_area())
    equals = true;
  return equals;
}
bool Rectangle::operator<=(Rectangle rhs) {
  bool lessthanequals = false;
  if (get_area() <= rhs.get_area())
    lessthanequals = true;
  return lessthanequals;
}
bool Rectangle::operator>=(Rectangle rhs) {
  bool greaterthanequals = false;
  if (get_area() >= rhs.get_area())
    greaterthanequals = true;
  return greaterthanequals;
}
void Rectangle::operator++() {
  ++length;
  ++width;
}
void Rectangle::operator--() {
  --length;
  --width;
}