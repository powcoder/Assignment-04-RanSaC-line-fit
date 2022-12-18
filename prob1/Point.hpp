https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
//  Copyright (c) 2022 Daniel Moreno. All rights reserved.
//

#pragma once

#include <iostream>

// This file contains the declaration of a class named `Point` (inside
// the namespace `course`). The skeleton of the class is given. Students
// must complete this skeleton. The implementation of `Point` is in the
// file `Point.cpp`. Complete that file too, where appropriate.
//
// Point contains two components of type `double` named `x` and `y`. The
// values of them can be read or written by using the `x()` and `y()` member
// functions. The signature of those functions is provided but students must
// complete their implementation. Students must also add any member variables
// they deem necessary to fulfill the requirements of the class API.
//
// A point constructed by default must have `x = 0` and `y = 0`. A point can
// also be constructed by providing custom x and y values. For instance, the
// following must work:
//
//     course::Point p1;               //sets x=0 and y=0
//     course::Point p2{ 1.0, 2.0 };   //sets x=1.0 and y=2.0
//
// Add support for addition and subtraction of points, as well as,
// multiplication with a scalar. For instance, the following must work as
// expected:
//
//     course::Point p1{ 1.0, 2.0 };
//     course::Point p2{ 3.0, 5.0 };
//     double a{ 10.0 };
//     course::Point p3{ p1 + p2 };   // x=4 and y=7
//     course::Point p4{ p2 - p1 };   // x=2 and y=3
//     course::Point p5{ p1 * a };    // x=10 and y=20
//     course::Point p6{ p1 / a };    // x=0.1 and y=0.2
//
// Equality and inequality operators must be supported too:
//
//     p1 == p2     // returns false
//     p1 != p2     // returns true
//
namespace course
{
  // Represents a 2D point
  class Point
  {
  public:
    Point(double x = 0.0, double y = 0.0);

    double& x();
    double& y();

    const double& x() const;
    const double& y() const;
  };

  //Displays a point
  std::ostream& operator<<(std::ostream& stream, const Point& point);
}