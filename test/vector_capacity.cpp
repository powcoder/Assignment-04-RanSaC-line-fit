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
  class Item
  {
  public:
    uint32_t id;
    bool operator==(const Item& other) const
    {
      return id == other.id;
    }
  };
}

TEST_CASE("Vector capacity")
{
  Support::Support support;
  using namespace course;
  {
    Vector<int> v1;
    CHECK(v1.capacity() >= 0);
  }
  {
    Vector<float> v1;
    CHECK(v1.capacity() >= 0);
  }
  {
    Vector<Item> v1;
    CHECK(v1.capacity() >= 0);
  }
  {
    constexpr int N{ 100 };
    for (int i = 0; i < N; ++i)
    {
      const int val1{ i - 25 };
      Vector<int> v1{ i,val1 };
      CHECK(v1.size() == i);
      CHECK(v1.capacity() >= i);

      const float val2{ i * 3.0f };
      Vector<float> v2{ i, val2 };
      CHECK(v2.size() == i);
      CHECK(v2.capacity() >= i);

      const Item val3{ static_cast<uint32_t>(i * i) };
      Vector<Item> v3{ i,val3 };
      CHECK(v3.size() == i);
      CHECK(v3.capacity() >= i);
    }
  }
}

