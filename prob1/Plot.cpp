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

#include "Plot.hpp"

#include <cfloat>

#include "../3rd-party/plotlib/plot.h"

namespace course
{
  class Plot::Impl
  {
  public:
    signalsmith::plot::Plot2D plot;
    double x0, x1;
    double y0, y1;
    int numSamples;

    Impl() :
      plot{},
      x0{ 0.0 }, x1{ 1.0 },
      y0{ 0.0 }, y1{ 1.0 },
      numSamples{ 10 }
    {

    }
  };

  Plot::Plot() : impl_{ std::make_unique<Impl>() }
  {
    auto& plot{ impl_->plot };
    plot.x.label("X");
    plot.y.label("Y");
  }

  Plot::~Plot()
  {

  }

  void Plot::xLimits(double x0, double x1)
  {
    impl_->x0 = x0;
    impl_->x1 = x1;
    impl_->plot.x.linear(x0, x1);
  }

  void Plot::yLimits(double y0, double y1)
  {
    impl_->y0 = y0;
    impl_->y1 = y1;
    impl_->plot.y.linear(y0, y1);
  }

  void Plot::autoFormat(const Point& p1, const Point& p2, int gridLines)
  {
    const int n{ std::max(gridLines, 2) };

    double x0{ std::min(p1.x(), p2.x()) };
    double x1{ std::max(p1.x(), p2.x()) };
    double xStep{ (x1 - x0) / n };

    double y0{ std::min(p1.y(), p2.y()) };
    double y1{ std::max(p1.y(), p2.y()) };
    double yStep{ (y1 - y0) / n };

    if (xStep < DBL_EPSILON && yStep < DBL_EPSILON)
    {  //error: do nothing
      return;
    }
    if (xStep < DBL_EPSILON)
    {
      xStep = yStep;
    }
    if (yStep < DBL_EPSILON)
    {
      yStep = xStep;
    }

    double sx{ 1.0 };
    while (std::floor(xStep * sx) / sx == 0.0)
    {
      sx *= 10;
    }
    if (sx > 1.0)
    {
      xStep = std::floor(xStep * sx) / sx;
    }
    sx = 1.0;
    while (std::floor(xStep * sx) / sx > 0.0)
    {
      sx *= 0.1;
    }
    if (sx < 1.0)
    {
      xStep = std::floor(xStep * sx) / sx;
    }

    double sy{ 1.0 };
    while (std::floor(yStep * sy) / sy == 0.0)
    {
      sy *= 10;
    }
    if (sy > 1.0)
    {
      yStep = std::floor(yStep * sy) / sy;
    }
    sy = 1.0;
    while (std::floor(yStep * sy) / sy > 0.0)
    {
      sy *= 0.1;
    }
    if (sy < 1.0)
    {
      yStep = std::floor(yStep * sy) / sy;
    }

    if (std::abs(x1 - x0) < DBL_EPSILON)
    {
      x0 -= xStep;
      x1 += xStep;
    }

    if (std::abs(y1 - y0) < DBL_EPSILON)
    {
      y0 -= yStep;
      y1 += yStep;
    }

    xLimits(x0, x1);
    yLimits(y0, y1);

    auto& plot{ impl_->plot };

    if (y0 <= 0.0 && 0.0 <= y1)
    {
      plot.y.major(0); //draw x axis at y=0
    }
    if (x0 <= 0.0 && 0.0 <= x1)
    {
      plot.x.major(0); //draw y axis at x=0
    }

    const double step{ std::max(xStep, yStep) };
    const int m{ static_cast<int>(
      std::max(std::ceil(x1 - x0) / step, std::ceil(y1 - y0) / step)) };
    for (int i = 0; i <= m; ++i)
    {
      const double x{ x0 + i * step };
      const double y{ y0 + i * step };
      if (x < x1) { plot.x.minor(x); }
      if (y < y1) { plot.y.minor(y); }
    }
    plot.x.minor(x1);
    plot.y.minor(y1);
  }

  void Plot::autoFormat(const Point* points, int numPts, int gridLines)
  {
    Point pMin{ DBL_MAX, DBL_MAX }, pMax{ -DBL_MAX, -DBL_MAX };
    for (int i = 0; i < numPts; ++i)
    {
      const Point& p{ points[i] };
      pMin.x() = std::min(pMin.x(), p.x());
      pMin.y() = std::min(pMin.y(), p.y());
      pMax.x() = std::max(pMax.x(), p.x());
      pMax.y() = std::max(pMax.y(), p.y());
    }
    autoFormat(pMin, pMax, gridLines);
  }

  void Plot::autoFormat(const std::vector<Point>& points, int gridLines)
  {
    autoFormat(points.data(), static_cast<int>(points.size()), gridLines);
  }

  void Plot::addLine(const Line& line, int styleIndex)
  {
    signalsmith::plot::Line2D& linePlot{
      styleIndex < 0 ? impl_->plot.line() : impl_->plot.line(styleIndex) };

    std::vector<Point> points;

    const Line Lx0{ Line::makeVertical(impl_->x0) };
    const Line Lx1{ Line::makeVertical(impl_->x1) };
    const Line Ly0{ Line::makeHorizontal(impl_->y0) };
    const Line Ly1{ Line::makeHorizontal(impl_->y1) };

    Point p;
    if (Lx0.intersect(line, &p) && p.y() <= impl_->y1 && p.y() > impl_->y0)
    {
      points.emplace_back(p);
    }
    if (Ly0.intersect(line, &p) && p.x() >= impl_->x0 && p.x() < impl_->x1)
    {
      points.emplace_back(p);
    }
    if (Lx1.intersect(line, &p) && p.y() >= impl_->y0 && p.y() < impl_->y1)
    {
      points.emplace_back(p);
    }
    if (Ly1.intersect(line, &p) && p.x() <= impl_->x1 && p.x() > impl_->x0)
    {
      points.emplace_back(p);
    }

    if (points.size() >= 2)
    {
      //find the pair of points with the largest distance between them
      double distSqr{ -1.0 };
      int index1{ 0 }, index2{ 0 };
      for (int i = 0; i < static_cast<int>(points.size()); ++i)
      {
        const Point& q1{ points[i] };
        for (int j = i + 1; j < static_cast<int>(points.size()); ++j)
        {
          const Point& q2{ points[j] };
          const double dx{ q1.x() - q2.x() };
          const double dy{ q1.y() - q2.y() };
          const double dSqr{ dx * dx + dy * dy };
          if (dSqr > distSqr)
          {
            distSqr = dSqr;
            index1 = i;
            index2 = j;
          }
        }
      }

      linePlot.add(points[index1].x(), points[index1].y());
      linePlot.add(points[index2].x(), points[index2].y());
      return;
    }

    //ERROR: line is outside of the plot rectangle?
    //throw std::runtime_error{ "Plot::addLine Error" };
  }

  void Plot::addPoints(const Point* points, int numPts, int styleIndex)
  {
    signalsmith::plot::Line2D& linePlot{
      styleIndex < 0 ? impl_->plot.line() : impl_->plot.line(styleIndex) };
    for (int i = 0; i < numPts; ++i)
    {
      linePlot.marker(points[i].x(), points[i].y());
    }
  }

  void Plot::addPoints(const std::vector<Point>& points, int styleIndex)
  {
    addPoints(points.data(), static_cast<int>(points.size()), styleIndex);
  }

  void Plot::save(const char* filename_svg)
  {
    //NOTE: we write the SVG file contents to a buffer and later to file
    // instead of directly to file stream to avoid an error with the memory
    // leak detection code.
    std::string svg;
    {
      std::stringstream s{ std::ios_base::out };
      impl_->plot.write(s);
      svg = s.str();
    }
    if (!svg.empty())
    {
      FILE* fp{ std::fopen(filename_svg, "wb") };
      if (fp == nullptr)
      { //file open error
        return;
      }
      std::fwrite(svg.c_str(), sizeof(std::string::value_type), svg.size(), fp);
      std::fclose(fp);
    }
  }
}
