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
#include "Vector.hpp"

// This file contains the declaration of a class named `LineRansac` (inside
// the namespace `course`). The skeleton of the class is given. Students
// must complete this skeleton. The implementation of `LineRansac` is in the
// file `LineRansac.cpp`. Complete that file too, where appropriate.
//
// LineRansac implements an algorithm for estimating the best fit line to
// a set of given points in the presence of outliers (outliers are points
// that do not belong the line).
//
// The way this class must be used is as follows:
//
//     int numIter{ 50 };             //let's do 50 iterations
//     double distThreshold{ 0.02 };  /inliers threshold
//     course::Vector<course::Point> points;
//     ...
//     // fill the vector of points with actual points
//     ...
//     LineRansac solver;
//     if (solver.solve(points, numIter, distThreshold))
//     { //success
//       std::cout << "Line " << solver.line() << std::endl;
//       std::cout << "RMSE " << solver.rmse() << std::endl;
//       std::cout << "Number of Inliers " << solver.inliers().size() << std::endl;
//     }
//
// Students must complete the member functions in this class to meet their
// expected behavior as described below for each of them.
//
namespace course
{
  // Line RanSaC solver
  class LineRansac
  {
    Line line_;
    double rmse_;
    Vector<int> inliers_;
  public:

    // Fits a line using RanSaC.
    //  - points: array of points
    //  - numIter: number of iterations (positive number)
    //  - distThreshold: non-negative distance threshold for inliers
    // Returns `true` on success and `false` on any error.
    // At least 2 points are required.
    bool solve(const Vector<Point>& points, int numIter, double distThreshold);

    // Returns the estimated line.
    // This result is only valid if the last call to `solve` returned true.
    const Line& line() const;

    // Returns the root mean squared error for the estimated line.
    // This result is only valid when the last called to `solve`
    // returned true.
    //
    // RMSE is computed only with inlier points.
    double rmse() const;

    // Returns the indices of the inlier points.
    // This result is only valid when the last called to `solve`
    // returned true.
    //
    // Inliers are those points that the algorithm determined belong to the
    // line and were used in the final least squares line fit.
    //
    // Inlier point indices are number indicating which points in the input
    // vector are considered inliers.
    // The following is a code example of how the indices can be used for
    // displaying the inlier points (if operator<< was implemented for Point):
    //
    //     course::Vector<course::Points> points;
    //     ...
    //     course::LineRansac ransac;
    //     ransac.solve(points, ... );
    //     ...
    //     const course::Vector<int>& indices{ ransac.inliers() };
    //     for (int i = 0; i < inliers.size(); ++i)
    //     { //display all inliers
    //       std::cout << "Inlier " << i << ": " << points[inlier[i]] << "\n";
    //     }
    //
    const Vector<int>& inliers() const;
  };
}