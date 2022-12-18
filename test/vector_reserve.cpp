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

TEST_CASE("Vector reserve")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 100 };
    constexpr int value{ 100 };
    Vector<int> v1;
    v1.reserve(N);
    CHECK(v1.capacity() == N);
    CHECK(v1.size() == 0);
    for (int i = 0; i < N; ++i)
    {
      v1.push_back(i);
    }
    CHECK(v1.capacity() == N);
    CHECK(v1.size() == N);
    v1.reserve(N / 2);
    CHECK(v1.capacity() == N);
    CHECK(v1.size() == N);
    v1.reserve(2 * N);
    CHECK(v1.capacity() == 2 * N);
    CHECK(v1.size() == N);
    for (int i = 0; i < N; ++i)
    {
      v1.push_back(i);
    }
    CHECK(v1.capacity() == 2 * N);
    CHECK(v1.size() == 2 * N);
  }
  {
    constexpr int N{ 70 };
    const Item value{ 99U };
    Vector<Item> v1;
    v1.reserve(N);
    CHECK(v1.capacity() == N);
    CHECK(v1.size() == 0);
    for (int i = 0; i < N; ++i)
    {
      v1.push_back(Item{ static_cast<uint32_t>(i + 9) });
    }
    CHECK(v1.capacity() == N);
    CHECK(v1.size() == N);
    v1.reserve(N / 2);
    CHECK(v1.capacity() == N);
    CHECK(v1.size() == N);
    v1.reserve(2 * N);
    CHECK(v1.capacity() == 2 * N);
    CHECK(v1.size() == N);
    for (int i = 0; i < N; ++i)
    {
      v1.push_back(Item{ static_cast<uint32_t>(i + 90) });
    }
    CHECK(v1.capacity() == 2 * N);
    CHECK(v1.size() == 2 * N);
  }
}
