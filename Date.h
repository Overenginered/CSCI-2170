#ifndef DATE_H_
#define DATE_H_

class Date {
private:
  int month;
  int day;
  int year;

public:
  Date();
  Date(int mo, int da, int yr);
  void set_date(int mo, int da, int yr);
  void display() const;
  Date NextDate();
};
#endif