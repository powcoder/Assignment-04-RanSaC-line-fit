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

TEST_CASE("Vector insert element")
{
  Support::Support support;
  using namespace course;
  { //insert at beginning
    constexpr int N{ 10 };
    Vector<int> v1;
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i };
      v1.insert(0, newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ N - i - 1};
      CHECK(v1[i] == newVal);
    }
  }
  { //insert at beginning
    constexpr int N{ 16 };
    Vector<Item> v1;
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i) };
      v1.insert(0, newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(N - i - 1) };
      CHECK(v1[i] == newVal);
    }
  }
  { //insert at end
    constexpr int N{ 11 };
    Vector<int> v1;
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i + 100};
      v1.insert(i, newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i + 100 };
      CHECK(v1[i] == newVal);
    }
  }
  { //insert at end
    constexpr int N{ 17 };
    Vector<Item> v1;
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i + 10) };
      v1.insert(i, newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i + 10) };
      CHECK(v1[i] == newVal);
    }
  }
  { //insert at varying positions
    constexpr int N{ 500 };
    Vector<int> v1{ 500 };
    for (int j = 0; j < N; ++j)
    {
      //set element values
      const int n{ N + j };
      for (int i = 0; i < n; ++i)
      {
        v1[i] = i;
      }
      //insert one element
      v1.insert(j, -1);
      //verify elements before
      for (int i = 0; i < j; ++i)
      {
        CHECK(v1[i] == i);
      }
      //verify inserted element
      CHECK(v1[j] == -1);
      //verify elements afterwards
      for (int i = j + 1; i < n; ++i)
      {
        CHECK(v1[i] == i - 1);
      }
    }
  }
}
