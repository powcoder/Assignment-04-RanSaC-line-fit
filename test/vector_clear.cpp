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

TEST_CASE("Vector clear")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 10 };
    constexpr int value{ 100 };
    Vector<int> v1{ N,value };
    CHECK(v1.size() == N);
    int capacity{ v1.capacity() };
    v1.clear();
    CHECK(v1.size() == 0);
    CHECK(v1.capacity() == capacity);
    for (int i = 0; i < N; ++i)
    {
      v1.push_back(i);
      v1.push_back(2 * i);
    }
    CHECK(v1.size() == 2 * N);
    capacity = v1.capacity();
    v1.clear();
    CHECK(v1.size() == 0);
    CHECK(v1.capacity() == capacity);
  }
  {
    constexpr int N{ 160 };
    const Item value{ 9U };
    Vector<Item> v1{ N, value };
    CHECK(v1.size() == N);
    int capacity{ v1.capacity() };
    v1.clear();
    CHECK(v1.size() == 0);
    CHECK(v1.capacity() == capacity);
    for (int i = 0; i < N; ++i)
    {
      v1.push_back(Item{ static_cast<uint32_t>(i) });
      v1.push_back(Item{ static_cast<uint32_t>(i + 1) });
    }
    CHECK(v1.size() == 2 * N);
    capacity = v1.capacity();
    v1.clear();
    CHECK(v1.size() == 0);
    CHECK(v1.capacity() == capacity);
  }
}
