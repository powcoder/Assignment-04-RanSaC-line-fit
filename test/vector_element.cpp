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

TEST_CASE("Vector element access")
{
  Support::Support support;
  using namespace course;
  {
    constexpr int N{ 8 };
    constexpr int val{ -5 };
    Vector<int> v1{ N,val };
    CHECK(v1.size() == N);
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i };
      CHECK(v1[i] == val);
      v1[i] = newVal;
      CHECK(v1[i] == newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const int newVal{ i };
      CHECK(v1[i] == newVal);
      const Vector<int>& v1_const{ v1 };
      CHECK(v1_const[i] == newVal);
    }
  }
  {
    constexpr int N{ 9 };
    constexpr float val{ -5.0f };
    Vector<float> v1{ N,val };
    CHECK(v1.size() == N);
    for (int i = 0; i < N; ++i)
    {
      const float newVal{ static_cast<float>(i) };
      CHECK(v1[i] == val);
      v1[i] = newVal;
      CHECK(v1[i] == newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const float newVal{ static_cast<float>(i) };
      CHECK(v1[i] == newVal);
      const Vector<float>& v1_const{ v1 };
      CHECK(v1_const[i] == newVal);
    }
  }
  {
    constexpr int N{ 10 };
    constexpr Item val{ 13U };
    Vector<Item> v1{ N,val };
    CHECK(v1.size() == N);
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i + 7) };
      CHECK(v1[i] == val);
      v1[i] = newVal;
      CHECK(v1[i] == newVal);
    }
    for (int i = 0; i < N; ++i)
    {
      const Item newVal{ static_cast<uint32_t>(i + 7) };
      CHECK(v1[i] == newVal);
      const Vector<Item>& v1_const{ v1 };
      CHECK(v1_const[i] == newVal);
    }
  }
  {
    constexpr int N{ 500 };
    for (int i = 0; i < N; ++i)
    {
      const int val1{ i - 25 };
      Vector<int> v1{ i,val1 };
      CHECK(v1.size() == i);
      for (int j = 0; j < i; ++j)
      {
        const int newVal{ i - 10 };
        CHECK(v1[j] == val1);
        v1[j] = newVal;
        CHECK(v1[j] == newVal);
      }
      for (int j = 0; j < i; ++j)
      {
        const int newVal{ i - 10 };
        CHECK(v1[j] == newVal);
        const Vector<int>& v1_const{ v1 };
        CHECK(v1_const[j] == newVal);
      }

      const float val2{ i * 5.0f };
      Vector<float> v2{ i, val2 };
      CHECK(v2.size() == i);
      for (int j = 0; j < i; ++j)
      {
        const float newVal{ i + 7.5f };
        CHECK(v2[j] == val2);
        v2[j] = newVal;
        CHECK(v2[j] == newVal);
      }
      for (int j = 0; j < i; ++j)
      {
        const float newVal{ i + 7.5f };
        CHECK(v2[j] == newVal);
        const Vector<float>& v2_const{ v2 };
        CHECK(v2_const[j] == newVal);
      }

      const Item val3{ static_cast<uint32_t>(i * i) };
      Vector<Item> v3{ i,val3 };
      CHECK(v3.size() == i);
      for (int j = 0; j < i; ++j)
      {
        const Item newVal{ static_cast<uint32_t>(i * 3) };
        CHECK(v3[j] == val3);
        v3[j] = newVal;
        CHECK(v3[j] == newVal);
      }
      for (int j = 0; j < i; ++j)
      {
        const Item newVal{ static_cast<uint32_t>(i * 3) };
        CHECK(v3[j] == newVal);
        const Vector<Item>& v3_const{ v3 };
        CHECK(v3_const[j] == newVal);
      }
    }
  }
}

