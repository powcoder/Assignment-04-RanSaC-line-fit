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
    bool operator!=(const Item& other) const
    {
      return !operator==(other);
    }
  };
}

TEST_CASE("Vector copy constructor")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 90 };
    constexpr int value{ 95 };
    Vector<int> v1{ N,value };
    Vector<int> v2{ v1 };
    CHECK(v2 == v1);

    for (int i = 0; i < N; ++i)
    {
      v1[i] = -i;
    }
    CHECK(v2 != v1);

    Vector<int> v3{ v1 };
    CHECK(v3 == v1);
    CHECK(v3 != v2);
  }
  {
    constexpr int N{ 10 };
    constexpr Item value{ 15 };
    Vector<Item> v1{ N,value };
    Vector<Item> v2{ v1 };
    CHECK(v2 == v1);

    for (int i = 0; i < N; ++i)
    {
      v1[i] = Item{ 2U * i};
    }
    CHECK(v2 != v1);

    Vector<Item> v3{ v1 };
    CHECK(v3 == v1);
    CHECK(v3 != v2);

    v2.clear();
    Vector<Item> v4{ v2 };
    Vector<Item> v5;
    CHECK(v4 == v2);
    CHECK(v4 == v5);
  }
}
