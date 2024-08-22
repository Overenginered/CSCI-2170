#ifndef _RECTANGLE_H
#define _RECTANGLE_H

class Rectangle {
private:
  int length;
  int width;

public:
  Rectangle(){};
  Rectangle(int l, int w);
  int get_length() const;
  int get_width() const;
  int get_area() const;

  bool operator<(Rectangle rhs);  // less than
  bool operator>(Rectangle rhs);  // greater than
  bool operator!=(Rectangle rhs); // not equal
  bool operator==(Rectangle rhs); // equal
  bool operator<=(Rectangle rhs); // less than or equal to
  bool operator>=(Rectangle rhs); // greater than or equal to
  void operator++();              // prefix increment
  void operator--();              // prefix decrement
};

#endif