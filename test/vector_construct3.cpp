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

TEST_CASE("Vector size and value constructor")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 10 };
    constexpr int val{ -1 };
    Vector<int> v1{ N, val };
    CHECK(v1.size() == N);
    const int* ptr{ v1.data() };
    CHECK(ptr != nullptr);
    for (int i = 0; i < N; ++i)
    {
      CHECK(ptr[i] == val);
    }
  }
  {
    constexpr int N{ 16 };
    constexpr float val{ 2.0f };
    Vector<float> v1{ N, val };
    CHECK(v1.size() == N);
    const float* ptr{ v1.data() };
    CHECK(ptr != nullptr);
    for (int i = 0; i < N; ++i)
    {
      CHECK(ptr[i] == val);
    }
  }
  {
    constexpr int N{ 24 };
    constexpr Item val{ 0xff };
    Vector<Item> v1{ N, val };
    CHECK(v1.size() == N);
    const Item* ptr{ v1.data() };
    CHECK(ptr != nullptr);
    for (int i = 0; i < N; ++i)
    {
      CHECK(ptr[i] == val);
    }
  }
  {
    constexpr int N{ 100 };
    for (int i = 0; i < N; ++i)
    {
      const int val1{ i + 1000 };
      Vector<int> v1{ i,val1 };
      CHECK(v1.size() == i);
      const int* ptr1{ v1.data() };
      CHECK(ptr1 != nullptr);
      for (int j = 0; j < i; ++j)
      {
        CHECK(ptr1[j] == val1);
      }

      const float val2{ i / 2.0f };
      Vector<float> v2{ i, val2 };
      CHECK(v2.size() == i);
      const float* ptr2{ v2.data() };
      CHECK(ptr2 != nullptr);
      for (int j = 0; j < i; ++j)
      {
        CHECK(ptr2[j] == val2);
      }

      const Item val3{ static_cast<uint32_t>(i * 2) };
      Vector<Item> v3{ i,val3 };
      CHECK(v3.size() == i);
      const Item* ptr3{ v3.data() };
      CHECK(ptr3 != nullptr);
      for (int j = 0; j < i; ++j)
      {
        CHECK(ptr3[j] == val3);
      }
    }
  }
}

