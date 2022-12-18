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

#include "Line.hpp"

// This file contains the declaration of a class named `LineLsq` (inside
// the namespace `course`). The skeleton of the class is given. Students
// must complete this skeleton. The implementation of `LineLsq` is in the
// file `LineLsq.cpp`. Complete that file too, where appropriate.
//
// This class implements an algorithm for estimating the best fit line to
// a set of give points in the least-squares sense.
//
// The way this class must be used is as follows:
//
//     LineLsq solver;                    //we create an instance of this class
//     if (solver.solve(points, numPts))  //we call `solve` with a list of points
//     { //solver returned true means the line was estimated correctly
//       Line line{ solver.getLine() };
//       double rmse{ solver.rmse() };
//       //do something we line and rmse as they are valid
//     }
//     else
//     { //solver return false: some error occurred
//       //handle error
//       // solver.getLine() and solver.rmse() may return anything and
//       // they must not be considered valid.
//     }
//
// Students must complete the member functions of this class as detailed
// below, inside the class.
//
namespace course
{
  // Line Least Squares solver
  class LineLsq
  {
  public:

    // Fits a line using the least-squares method.
    //  - points: array of points
    //  - numPts: number of points in the array
    // Returns `true` on success and `false` on any error.
    // At least 2 points are required.
    bool solve(const Point* points, int numPts);

    // Returns the estimated line.
    // This result is only valid if the last call to `solve` returned true.
    const Line& line() const;

    // Returns the root mean squared error for the estimated line.
    // This result is only valid if the last call to `solve` returned true.
    double rmse() const;
  };
}