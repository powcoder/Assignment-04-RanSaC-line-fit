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

#include <memory>
#include <vector>

#include "Line.hpp"

namespace course
{
  class Plot
  {
  public:
    Plot();

    Plot(const Plot& other) = delete;

    ~Plot();

    void xLimits(double x0, double x1);

    void yLimits(double y0, double y1);

    void autoFormat(const Point& p1, const Point& p2, int gridLines);

    void autoFormat(const std::vector<Point>& points, int gridLines);

    void autoFormat(const Point* points, int numPts, int gridLines);

    void addLine(const Line& line, int styleIndex = -1);

    void addPoints(const std::vector<Point>& points, int styleIndex = -1);

    void addPoints(const Point* points, int numPts, int styleIndex);

    void save(const char* filename_svg);

  private:
    class Impl;
    std::unique_ptr<Impl> impl_;
  };
}