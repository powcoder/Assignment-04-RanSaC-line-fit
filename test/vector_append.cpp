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

TEST_CASE("Vector append element")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 10 };
    constexpr int val{ 10 };
    Vector<int> v1{ N,val };
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ 2 * i };
      v1.push_back(newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ 2 * i };
      CHECK(v1[i] == val);
      CHECK(v1[N + i] == newVal);
    }
  }
  {
    constexpr int N{ 12 };
    constexpr float val{ 12.f };
    Vector<float> v1{ N,val };
    for (int i = 0; i < N; ++i)
    {
      const float newVal{ 3.f * i };
      v1.push_back(newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const float newVal{ 3.f * i };
      CHECK(v1[i] == val);
      CHECK(v1[N + i] == newVal);
    }
  }
  {
    constexpr int N{ 15 };
    constexpr Item val{ 15U };
    Vector<Item> v1{ N,val };
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(4 * i) };
      v1.push_back(newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(4 * i) };
      CHECK(v1[i] == val);
      CHECK(v1[N + i] == newVal);
    }
  }
  {
    constexpr int N{ 250 };
    constexpr int val{ 250 };
    Vector<int> v1{ N,val };
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ 100 * i };
      v1.push_back(newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ 100 * i };
      CHECK(v1[i] == val);
      CHECK(v1[N + i] == newVal);
    }
  }
}
