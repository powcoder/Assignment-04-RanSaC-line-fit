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

TEST_CASE("Vector comparison operator")
{
  Support::Support support;
  using namespace course;
  {
    Vector<int> v1;
    Vector<int> v2;
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);

    v1.push_back(1);
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v2.push_back(1);
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);

    v1.push_back(2);
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v2.push_back(3);
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v1.resize(1);
    v2.resize(1);
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);

    v1.clear();
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v2.clear();
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);
  }
  {
    Vector<double> v1;
    Vector<double> v2;
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);

    v1.push_back(1);
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v2.push_back(1);
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);

    v1.push_back(2);
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v2.push_back(3);
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v1.resize(1);
    v2.resize(1);
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);

    v1.clear();
    CHECK((v1 == v2) == false);
    CHECK((v1 != v2) == true);

    v2.clear();
    CHECK((v1 == v2) == true);
    CHECK((v1 != v2) == false);
  }
}
