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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../prob1/LineRansac.hpp"

#include <vector>
#include <random>
#include <algorithm>

#include <Support.hpp>

#ifndef M_PI
# define M_PI           3.14159265358979323846  /* pi */
#endif

using mt19937 = std::mersenne_twister_engine<
  std::uint32_t, 32, 624, 397, 31,
  0x9908b0df, 11,
  0xffffffff, 7,
  0x9d2c5680, 15,
  0xefc60000, 18, 1812433253>;

TEST_CASE("LineRansac:errors")
{
  Support::Support support;
  using namespace course;
  {
    Vector<Point> points{ 2, Point{1, 2} };
    LineRansac ransac;
    CHECK(ransac.solve(points, 0, 1.0) == false);
    CHECK(ransac.solve(points, -1, 1.0) == false);
    CHECK(ransac.solve(points, 1, -1.0) == false);
    CHECK(ransac.solve(points, 1, 1.0) == false);
  }
}

TEST_CASE("LineRansac:noiseless")
{
  Support::Support support;
  using namespace course;
  auto Approx = [](double x) { return doctest::Approx(x); };
  auto TestLineRansac = [&Approx](
    const Point& p1, const Point& p2,
    int numPts, int numIter, double distThreshold)
  {
    Vector<Point> points;
    points.reserve(numPts);
    Point v{ (p2 - p1) / (numPts - 1) };
    for (int i = 0; i < numPts; ++i)
    {
      points.push_back(p1 + v * i);
    }
    LineRansac ransac;
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.line().signeDistance(p1) == Approx(0));
    CHECK(ransac.line().signeDistance(p2) == Approx(0));
    CHECK(ransac.rmse() == Approx(0));

    const Vector<int>& inliers{ ransac.inliers() };
    CHECK(inliers.size() == numPts);

    std::vector<int> inliersStd(inliers.size());
    for (int i = 0; i < inliers.size(); ++i)
    {
      inliersStd[i] = inliers[i];
    }
    std::sort(inliersStd.begin(), inliersStd.end());
    for (int i = 0; i < inliers.size(); ++i)
    {
      CHECK(inliersStd[i] == i);
    }
  };

  constexpr double angleStep{ 20 };
  constexpr double RAD{ M_PI / 360.0 };
  for (double angle = 0.0; angle < 361.0; angle += angleStep)
  {
    const double phi1{ angle * RAD };
    const double phi2{ phi1 + 180.0 * RAD };
    Point p1{ std::cos(phi1), std::sin(phi1) };
    Point p2{ std::cos(phi2), std::sin(phi2) };

    TestLineRansac(p1, p2, 2, 1, 1e-3);
    TestLineRansac(p1, p2, 10, 2, 1e-3);
    TestLineRansac(p1, p2, 1000, 100, 1e-3);
  }
}

TEST_CASE("LineRansac:noiseless2")
{
  Support::Support support;
  mt19937 gen{ 114999053 };
  using namespace course;
  auto Approx = [](double x) { return doctest::Approx(x); };
  auto TestLineRansac = [&Approx, &gen](
    const Point& p1, const Point& p2,
    int numPts, int numIter, double distThreshold)
  {
    Vector<Point> points;
    points.reserve(numPts);
    Point v{ (p2 - p1) / (numPts - 1) };
    for (int i = 0; i < numPts; ++i)
    {
      points.push_back(p1 + v * i);
    }
    const int numOutliers{ std::max(numPts / 5, 1) };
    v = Point{ p2 - p1 };
    Point vn{ -v.y(), v.x() };
    Point origin{ p1 + vn };
    v = v / (numOutliers - 1);
    for (int i = 0; i < numOutliers; ++i)
    {
      points.push_back(origin - v * i);
    }

    LineRansac ransac;
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.line().signeDistance(p1) == Approx(0));
    CHECK(ransac.line().signeDistance(p2) == Approx(0));
    CHECK(ransac.rmse() == Approx(0));

    Vector<int> inliers{ ransac.inliers() };
    CHECK(inliers.size() == numPts);

    std::sort(inliers.data(), inliers.data() + inliers.size());
    for (int i = 0; i < inliers.size(); ++i)
    {
      CHECK(inliers[i] == i);
    }

    std::shuffle(points.data(), points.data() + points.size(), gen);
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.line().signeDistance(p1) == Approx(0));
    CHECK(ransac.line().signeDistance(p2) == Approx(0));
    CHECK(ransac.rmse() == Approx(0));
  };

  constexpr double angleStep{ 25 };
  constexpr double RAD{ M_PI / 180.0 };
  for (double angle = 0.0; angle < 361.0; angle += angleStep)
  {
    const double phi1{ angle * RAD };
    const double phi2{ phi1 + 180.0 * RAD };
    Point p1{ std::cos(phi1), std::sin(phi1) };
    Point p2{ std::cos(phi2), std::sin(phi2) };

    TestLineRansac(p1, p2, 50, 25, 1e-3);
    TestLineRansac(p1, p2, 100, 50, 1e-1);

    Point v{ (p2 - p1) * 2.0 };
    TestLineRansac(p1 - v, p2 + v, 1000, 500, 1.0);
  }
}

TEST_CASE("LineRansac:noisy")
{
  Support::Support support;
  mt19937 gen{ 0xd30052e };

  using namespace course;
  auto Approx = [](double x) { return doctest::Approx(x); };
  auto TestLineRansac = [&Approx, &gen](
    const Point& p1, const Point& p2,
    int numPts, int numIter, double distThreshold, double std)
  {
    std::uniform_real_distribution<> uniform(-1.0, 2.0);
    std::normal_distribution<> gaussian{ 0.0, std };
    Vector<Point> points;
    points.reserve(numPts);
    Point v{ (p2 - p1) };
    Point n{ -v.y(), v.x() };
    n = n / std::sqrt(n.x() * n.x() + n.y() * n.y());
    for (int i = 0; i < numPts; ++i)
    {
      double lambda{ uniform(gen) };
      double noise{ gaussian(gen) };
      points.push_back(p1 + v * lambda + n * noise);
    }

    constexpr double highThreshold{ 1.3 };

    LineRansac ransac;
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.rmse() <= highThreshold * std);
    CHECK(ransac.inliers().size() == numPts);

    Vector<int> inliers{ ransac.inliers() };
    std::sort(inliers.data(), inliers.data() + inliers.size());
    for (int i = 0; i < inliers.size(); ++i)
    {
      CHECK(inliers[i] == i);
    }

    std::shuffle(points.data(), points.data() + points.size(), gen);
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.rmse() <= highThreshold * std);
    CHECK(ransac.inliers().size() == numPts);
  };

  constexpr double angleStep{ 30 };
  constexpr double RAD{ M_PI / 360.0 };
  for (double angle = 0.0; angle < 361.0; angle += angleStep)
  {
    const double phi1{ angle * RAD };
    const double phi2{ phi1 + 180.0 * RAD };
    Point p1{ std::cos(phi1), std::sin(phi1) };
    Point p2{ std::cos(phi2), std::sin(phi2) };

    TestLineRansac(p1, p2, 20, 15, 1e-3, 1e-4);
    TestLineRansac(p1, p2, 30, 20, 1e-2, 1e-3);
    TestLineRansac(p1, p2, 100, 50, 1e-1, 1e-2);
  }
}

TEST_CASE("LineRansac:noisy2")
{
  Support::Support support;
  mt19937 gen{ 0xd30052e };

  using namespace course;
  auto Approx = [](double x) { return doctest::Approx(x); };
  auto TestLineRansac = [&Approx, &gen](
    const Point& p1, const Point& p2,
    int numPts, int numIter, double distThreshold, double std)
  {
    std::uniform_real_distribution<> uniform(-1.0, 2.0);
    std::normal_distribution<> gaussian{ 0.0, std };
    Vector<Point> points;
    points.reserve(numPts);
    Point v{ (p2 - p1) };
    Point n{ -v.y(), v.x() };
    n = n / std::sqrt(n.x() * n.x() + n.y() * n.y());
    for (int i = 0; i < numPts; ++i)
    {
      double lambda{ uniform(gen) };
      double noise{ gaussian(gen) };
      points.push_back(p1 + v * lambda + n * noise);
    }
    const int numOutliers{ std::max(numPts / 5, 1) };
    v = Point{ p2 - p1 };
    Point vn{ -v.y(), v.x() };
    Point origin{ p1 + vn };
    v = v / (numOutliers - 1);
    for (int i = 0; i < numOutliers; ++i)
    {
      points.push_back(origin - v * i);
    }

    constexpr double highThreshold{ 1.3 };

    LineRansac ransac;
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.rmse() <= highThreshold * std);
    CHECK(ransac.inliers().size() == numPts);

    Vector<int> inliers{ ransac.inliers() };
    std::sort(inliers.data(), inliers.data() + inliers.size());
    for (int i = 0; i < inliers.size(); ++i)
    {
      CHECK(inliers[i] == i);
    }

    std::shuffle(points.data(), points.data() + points.size(), gen);
    CHECK(ransac.solve(points, numIter, distThreshold) == true);
    CHECK(ransac.rmse() <= highThreshold * std);
    CHECK(ransac.inliers().size() == numPts);
  };

  constexpr double angleStep{ 35 };
  constexpr double RAD{ M_PI / 360.0 };
  for (double angle = 0.0; angle < 361.0; angle += angleStep)
  {
    const double phi1{ angle * RAD };
    const double phi2{ phi1 + 180.0 * RAD };
    Point p1{ std::cos(phi1), std::sin(phi1) };
    Point p2{ std::cos(phi2), std::sin(phi2) };

    TestLineRansac(p1, p2, 50, 25, 1e-3, 1e-5);
    TestLineRansac(p1, p2, 100, 50, 1e-1, 1e-3);

    Point v{ (p2 - p1) * 2.0 };
    TestLineRansac(p1 - v, p2 + v, 1000, 500, 1.0, 1e-2);
  }
}
