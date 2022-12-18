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

TEST_CASE("Vector data pointer")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 20 };
    constexpr int val{ 200 };
    Vector<int> v1{ N,val };
    const Vector<int>& v1_const{ v1 };
    CHECK(v1.size() == N);
    CHECK(v1.data() != nullptr);
    CHECK(v1_const.data() != nullptr);
    CHECK(v1.data() == v1_const.data());
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i - 100 };
      CHECK(v1.data()[i] == val);
      CHECK(v1_const.data()[i] == val);
      v1.data()[i] = newVal;
    }
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i - 100 };
      CHECK(v1.data()[i] == newVal);
      CHECK(v1_const.data()[i] == newVal);
    }
  }
  {
    constexpr int N{ 19 };
    constexpr float val{ 4.6f };
    Vector<float> v1{ N,val };
    const Vector<float>& v1_const{ v1 };
    CHECK(v1.size() == N);
    CHECK(v1.data() != nullptr);
    CHECK(v1_const.data() != nullptr);
    CHECK(v1.data() == v1_const.data());
    for (int i = 0; i < N; ++i)
    {
      const float newVal{ i /100.f };
      CHECK(v1.data()[i] == val);
      CHECK(v1_const.data()[i] == val);
      v1.data()[i] = newVal;
    }
    for (int i = 0; i < N; ++i)
    {
      const float newVal{ i / 100.f };
      CHECK(v1.data()[i] == newVal);
      CHECK(v1_const.data()[i] == newVal);
    }
  }
  {
    constexpr int N{ 13 };
    constexpr Item val{ 13U };
    Vector<Item> v1{ N,val };
    const Vector<Item>& v1_const{ v1 };
    CHECK(v1.size() == N);
    CHECK(v1.data() != nullptr);
    CHECK(v1_const.data() != nullptr);
    CHECK(v1.data() == v1_const.data());
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i) };
      CHECK(v1.data()[i] == val);
      CHECK(v1_const.data()[i] == val);
      v1.data()[i] = newVal;
    }
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i) };
      CHECK(v1.data()[i] == newVal);
      CHECK(v1_const.data()[i] == newVal);
    }
  }
  {
    constexpr int N{ 100 };
    for (int j = 0; j < N; ++j)
    {
      {
        const int val{ j };
        Vector<int> v1{ j,val };
        const Vector<int>& v1_const{ v1 };
        CHECK(v1.size() == j);
        CHECK(v1.data() != nullptr);
        CHECK(v1_const.data() != nullptr);
        CHECK(v1.data() == v1_const.data());
        for (int i = 0; i < j; ++i)
        {
          const int newVal{ i - 5 };
          CHECK(v1.data()[i] == val);
          CHECK(v1_const.data()[i] == val);
          v1.data()[i] = newVal;
        }
        for (int i = 0; i < j; ++i)
        {
          const int newVal{ i - 5 };
          CHECK(v1.data()[i] == newVal);
          CHECK(v1_const.data()[i] == newVal);
        }
      }
      {
        const float val{ j * 0.1f };
        Vector<float> v1{ j,val };
        const Vector<float>& v1_const{ v1 };
        CHECK(v1.size() == j);
        CHECK(v1.data() != nullptr);
        CHECK(v1_const.data() != nullptr);
        CHECK(v1.data() == v1_const.data());
        for (int i = 0; i < j; ++i)
        {
          const float newVal{ i / 2.f };
          CHECK(v1.data()[i] == val);
          CHECK(v1_const.data()[i] == val);
          v1.data()[i] = newVal;
        }
        for (int i = 0; i < j; ++i)
        {
          const float newVal{ i / 2.f };
          CHECK(v1.data()[i] == newVal);
          CHECK(v1_const.data()[i] == newVal);
        }
      }
      {
        const Item val{ static_cast<uint32_t>(j) };
        Vector<Item> v1{ j,val };
        const Vector<Item>& v1_const{ v1 };
        CHECK(v1.size() == j);
        CHECK(v1.data() != nullptr);
        CHECK(v1_const.data() != nullptr);
        CHECK(v1.data() == v1_const.data());
        for (int i = 0; i < j; ++i)
        {
          const Item newVal{ static_cast<uint32_t>(i + 1) };
          CHECK(v1.data()[i] == val);
          CHECK(v1_const.data()[i] == val);
          v1.data()[i] = newVal;
        }
        for (int i = 0; i < j; ++i)
        {
          const Item newVal{ static_cast<uint32_t>(i + 1) };
          CHECK(v1.data()[i] == newVal);
          CHECK(v1_const.data()[i] == newVal);
        }
      }
    }
  }
}
