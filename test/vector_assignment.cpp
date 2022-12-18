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

TEST_CASE("Vector assignment operator")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 60 };
    constexpr int value{ 116 };
    Vector<int> v1{ N,value };
    Vector<int> v2{ 2,3 };
    CHECK(v2 != v1);

    v2 = v1;
    CHECK(v2 == v1);

    v1.clear();
    v1.push_back(-1);
    v1.push_back(-2);
    CHECK(v1.size() == 2);
    CHECK(v1[0] == -1);
    CHECK(v1[1] == -2);

    CHECK(v2.size() == N);
    for (int i = 0; i < N; ++i)
    {
      CHECK(v2[1] == value);
    }
    CHECK(v2 != value);

    v1 = v2;
    CHECK(v2 == v1);
  }
  {
    constexpr int N{ 28 };
    constexpr Item value{ 1001 };
    Vector<Item> v1{ N,value };
    Vector<Item> v2{ N / 2 };
    CHECK(v2 != v1);

    v2 = v1;
    CHECK(v2 == v1);

    Vector<Item> v3{ N / 2, Item{ 2000 } };
    v1 = v3;
    CHECK(v3 == v1);

    for (int i = 0; i < N; ++i)
    {
      CHECK(v2[i] == value);
    }

    for (int i = 0; i < N / 2; ++i)
    {
      CHECK(v1[i] == Item{ 2000 });
    }

    v3.resize(10);
    v2 = v3;
    CHECK(v2 == v3);

    Vector<Item> v4;
    v1 = v4;
    CHECK(v1 == v4);
  }
}
