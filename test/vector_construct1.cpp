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
  class Item {};
}

TEST_CASE("Vector default constructor")
{
  Support::Support support;
  using namespace course;
  {
    Vector<int> v1;
    CHECK(v1.size() == 0);
  }
  {
    Vector<float> v1;
    CHECK(v1.size() == 0);
  }
  {
    Vector<Item> v1;
    CHECK(v1.size() == 0);
  }
}
