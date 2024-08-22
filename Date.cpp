#include "Date.h"
#include <iomanip>
#include <iostream>

Date::Date() {
  month = 10;
  day = 30;
  year = 2023;
}

Date::Date(int mo, int da, int yr) {
  month = mo;
  day = da;
  year = yr;
}

void Date::set_date(int mo, int da, int yr) {
  month = mo;
  day = da;
  year = yr;
}

void Date::display() const {
  std::cout << month << "/" << day << "/" << std::setfill('0') << std::setw(2)
            << year % 100 << std::setfill(' ') << std::endl;
}

Date Date::NextDate() {
  Date next;
  next.month = month;
  next.day = day;
  next.year = year;

  if (next.month == 4 || next.month == 6 || next.month == 9 ||
      next.month == 11) {
    if (next.day == 30) {
      next.day = 1;
      next.month = next.month + 1;
    } else {
      next.day++;
    }
  }

  else if (next.month == 1 || next.month == 3 || next.month == 5 ||
           next.month == 7 || next.month == 8 || next.month == 10 ||
           next.month == 12) {
    if (next.day == 31) {
      next.day = 1;
      next.month = next.month + 1;
    } else {
      next.day++;
    }

    if (next.month > 12) {
      next.month = 1;
      next.year = next.year + 1;
    }

  } else if (next.month == 2) {
    if (next.day < 28) {
      next.day++;
    }

    else if (next.day == 29) {
      next.day = 1;
      next.month = next.month + 1;
    } 
    else if (next.day == 28) {
      if (next.year % 100 == 0) {
        if (next.year % 400 == 0) {
          next.day = 29;
        } else {
          next.day = 1;
          next.month = next.month + 1;
        }
      } else if (next.year % 4 == 0) {
        next.day = 29;
      } else{
          next.day = 1;
          next.month = next.month + 1;
      }
    }
  }

  return next;
}