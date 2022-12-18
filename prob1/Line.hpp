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

#include "Point.hpp"

#include <iostream>

// This file contains the declaration of a class named `Line` (inside
// the namespace `course`). The skeleton of the class is given. Students
// must complete this skeleton. The implementation of `Line` is in the
// file `Line.cpp`. Complete that file too, where appropriate.
//
// Line is a class representing a 2-dimensional line. There are several
// ways to describe a line (e.g. two points, point and vector, etc.). It
// is up to the student to choose the internals of this class.
//
// Line must have a default constructor that makes the line `x = 0` (i.e.
// a vertical line passing through x = 0):
//
//     course::Line line1;               //vertical line x = 0
//
// Line can also be constructed from two points as follows:
//
//     course::Point p1;
//     course::Point p2{ 1.0, 2.0 };
//     course::Line line2{ p1, p2};      //a line through p1 and p2
//
// Equality and inequality operators must be supported too:
//
//     line1 == line2     // returns false
//     line1 != line2     // returns true
//
// In addition, all the member functions included below must be implemented
// following their stated requirements.
//
namespace course
{
  // Represents a 2D line
  class Line
  {
  public:
    Line();

    Line(const Point& a, const Point& b);

    //Returns the signed distance from a point `p` to this line.
    double signeDistance(const Point& p) const;

    //Evaluate the line at y.
    //Returns the x coordinate for the given y coordinate.
    double x(double y) const;

    //Evaluate the line at x.
    //Returns the y coordinate for the given x coordinate.
    double y(double x) const;

    //Return `true` only if this line is horizontal.
    bool isHorizontal() const;

    //Return `true` only if this line is vertical.
    bool isVertical() const;

    //Makes a new horizontal line at `y == offset`.
    static Line makeHorizontal(double offset = 0.0);

    //Makes a new vertical line at `x == offset`.
    static Line makeVertical(double offset = 0.0);

    //Makes a new line perpendicular to this one and passing through `p`
    Line perpendicular(const Point& p) const;

    //Makes a new line parallel to this one and passing through `p`
    Line parallel(const Point& p) const;

    //Returns `true` only if this line intersects `other`,
    //If `pPoint` is not `nullptr`, then the intersection point is written
    //to the `Point` that its points to.
    bool intersect(const Line& other, Point* pPoint = nullptr) const;
  };

  //Displays a line
  std::ostream& operator<<(std::ostream& stream, const Line& line);
}
