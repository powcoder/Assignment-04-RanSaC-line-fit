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

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <Support.hpp>

#include "Line.hpp"
#include "Point.hpp"
#include "LineRansac.hpp"
#include "Plot.hpp"

//makes a plot and saves it to a file named `lineplot_ransac.svg`
// line: the line to plot (the line which was fit)
// points: vector of points to plot (the points used to fit line)
// inlierIndices: vector with the indices of the points considered inliers
//                to `line`
static void makePlot(
  const course::Line& line,
  const course::Vector<course::Point>& points,
  const course::Vector<int>& inlierIndices);

int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // NOTE: Do not delete or modify this line. It helps for running
  //   checks such as testing for memory leaks.
  Support::Support support;
  // DO NOT WRITE ANYTHING BEFORE THIS LINE.
  // ALL STUDENT'S CODE MUST BE BELOW.
  //--------------------------------------------------------------------------

  // Students must refer to the assignment page for detailed instructions
  // about this application.
  // Here is a summary for your convenience:
  //  1) `linefit_ransac` takes as arguments two parameters and a list of
  //      point coordinates like this:
  //        linefit_ransac numIter distThreshold x1 y1 x2 y2 x3 y3 ...
  //  2) The parameter `numIter` is a positive integer corresponding to
  //     number of iterations of the RanSaC algorithm.
  //  3) The parameter `distThreshold` is a non-negative floating point number
  //     corresponding to the distance threshold for inliers in the RanSaC
  //     algorithm.
  //  4) Each pair (x, y) corresponds to one input point. For instance,
  //     (x1, y1) are the coordinates of the first point.
  //  5) Place the points in a Vector and call your implementation of the
  //     class `LineRansac` to fit a line.
  //  6) On error situations, display an error message beginning with `ERROR`.
  //     as usual.
  //  7) If the line fit operation succeeds, display the line, RMSE, and
  //     number of inlier points.
  //  7) Call `makePlot` to create a plot of the line and points. The function
  //     `makePlot` is defined in this same file.
  //  8) `main` must always return 0.
  //

  //TODO: write your code here...

  // Make a plot:
  //  makePlot(line, points, inliers);

  return 0;
}

void makePlot(
  const course::Line& line,
  const course::Vector<course::Point>& points,
  const course::Vector<int>& inlierIndices)
{
  course::Plot plot;
  constexpr int styleIndex{ 0 };
  plot.autoFormat(points.data(), points.size(), 10);

  course::Vector<bool> isInlier(points.size(), false);
  for (int i = 0; i < inlierIndices.size(); ++i)
  {
    isInlier[inlierIndices[i]] = true;
  }

  course::Vector<course::Point> inliers, outliers;
  for (int i = 0; i < isInlier.size(); ++i)
  {
    if (isInlier[i])
    {
      printf("inlier %d: p %lf %lf\n", i, points[i].x(), points[i].y());
      inliers.push_back(points[i]);
    }
    else
    {
      printf("outlier %d: p %lf %lf\n", i, points[i].x(), points[i].y());
      outliers.push_back(points[i]);
    }
  }

  plot.addPoints(inliers.data(), inliers.size(), styleIndex);
  plot.addPoints(outliers.data(), outliers.size(), styleIndex + 1);
  plot.addLine(line, styleIndex);

  const char filename_svg[]{ "lineplot_ransac.svg" };
  plot.save(filename_svg);

  std::cout << "Saved: " << filename_svg << std::endl;
}