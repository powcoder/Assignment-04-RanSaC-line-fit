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

#include "../prob1/Vector.hpp"

#include <Support.hpp>

namespace
{
  class Item {};
}

TEST_CASE("Vector size constructor")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 10 };
    Vector<int> v1{ N };
    CHECK(v1.size() == N);
  }
  {
    constexpr int N{ 11 };
    Vector<float> v1{ N };
    CHECK(v1.size() == N);
  }
  {
    constexpr int N{ 30 };
    Vector<Item> v1{ N };
    CHECK(v1.size() == N);
  }
  {
    constexpr int N{ 100 };
    for (int i = 0; i < N; ++i)
    {
      Vector<int> v1{ i };
      CHECK(v1.size() == i);
      Vector<float> v2{ i };
      CHECK(v2.size() == i);
      Vector<Item> v3{ i };
      CHECK(v3.size() == i);
    }
  }
}
