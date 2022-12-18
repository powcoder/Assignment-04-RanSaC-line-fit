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

TEST_CASE("Vector resize")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 10 };
    Vector<int> v1;
    CHECK(v1.size() == 0);
    for (int i = 0; i < N; ++i)
    {
      v1.resize(i + 1);
      CHECK(v1.size() == i + 1);
      v1[i] = i;
    }
    for (int i = 0; i < N; ++i)
    {
      CHECK(v1[i] == i);
    }
    for (int i = 0; i < N; ++i)
    {
      v1.resize(N - i - 1);
      CHECK(v1.size() == N - i - 1);
      if (N - i - 1 > 0)
      {
        CHECK(v1[N - i - 2] == N - i - 2);
      }
    }
  }
  {
    constexpr int N{ 16 };
    Vector<float> v1;
    CHECK(v1.size() == 0);
    for (int i = 0; i < N; ++i)
    {
      v1.resize(i + 1);
      CHECK(v1.size() == i + 1);
      v1[i] = 2.0f * i;
    }
    for (int i = 0; i < N; ++i)
    {
      CHECK(v1[i] == 2.0f * i);
    }
    for (int i = 0; i < N; ++i)
    {
      v1.resize(N - i - 1);
      CHECK(v1.size() == N - i - 1);
      if (N - i - 1 > 0)
      {
        CHECK(v1[N - i - 2] == 2.0f * (N - i - 2));
      }
    }
  }
  {
    constexpr int N{ 25 };
    Vector<Item> v1;
    CHECK(v1.size() == 0);
    for (int i = 0; i < N; ++i)
    {
      v1.resize(i + 1);
      CHECK(v1.size() == i + 1);
      v1[i] = Item{ static_cast<uint32_t>(3 * i) };
    }
    for (int i = 0; i < N; ++i)
    {
      CHECK(v1[i] == Item{ static_cast<uint32_t>(3 * i) });
    }
    for (int i = 0; i < N; ++i)
    {
      v1.resize(N - i - 1);
      CHECK(v1.size() == N - i - 1);
      if (N - i - 1 > 0)
      {
        CHECK(v1[N - i - 2] == Item{ static_cast<uint32_t>(3 * (N - i - 2)) });
      }
    }
  }
  {
    constexpr int N{ 10009 };
    Vector<int> v1;
    CHECK(v1.size() == 0);
    for (int i = 0; i < N; ++i)
    {
      v1.resize(i + 1);
      CHECK(v1.size() == i + 1);
      v1[i] = i * 8;
    }
    for (int i = 0; i < N; ++i)
    {
      CHECK(v1[i] == i * 8);
    }
    for (int i = 0; i < N; ++i)
    {
      v1.resize(N - i - 1);
      CHECK(v1.size() == N - i - 1);
      if (N - i - 1 > 0)
      {
        CHECK(v1[N - i - 2] == (N - i - 2) * 8);
      }
    }
  }
}
