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

#pragma once

#include <iostream>

// This file contains a template of a Vector class. This class represents an
// array with elements of type `T` where `T` is a template argument. Students
// must complete its implementation.
//
// The following operations must be implemented:
//
// Constructing by default:
//
//      course::Vector<int> v1;                 //creates an empty vector
//
// Constructing of given size:
//
//      course::Vector<int> v1{ 10 };           //creates a vector of size 10
//
// Constructing of given size and initialize elements:
//
//      course::Vector<int> v1{ 10, 5 };        //creates a vector of size 10
//                                              // and sets all its elements
//                                              // to the value 5
//
// In these instructions `int` is used just as an example, all operations
// must equally work with any type:
//
//      course::Vector<double> v1;              //creates an empty vector
//      course::Vector<double> v2{ 10 };        //creates a vector of size 10
//      course::Vector<double> v3{ 10, 0.5 };   //creates a vector of size 10
//                                              // and sets all its elements
//                                              // to the value 0.5
//
// Vector size:
//
//      course::Vector<int> v1;
//      int size1{ v1.size };                   // size1 = 0
//      course::Vector<int> v2{ 10 };
//      int size2{ v2.size };                   // size2 = 10
//
// Vector capacity:
//
//      course::Vector<int> v1;
//      int cap1{ v1.capacity() };              // cap1 >= 0
//      course::Vector<int> v2{ 10 };
//      int cap2{ v2.capacity() };              // cap2 >= 10
//
// Element access:
//
//      course::Vector<int> v1{ 10, 5 };
//      int element3{ v1[3] };                  // element3 = 5
//      v1[0] = 1;                              // sets the first array element
//                                              // to value 1
//
// To correctly implement element access `const` and `non-const` versions of
// operator[] must be included, for instance:
//
//      T& operator[](int index) { ... }
//      const T& operator[](int index) const { ... }
//
// Pointer to array beginning:
//
//      course::Vector<int> v1{ 10, 5 };
//      int* ptr{ v1.data() };                  // ptr points to 1st element
//      int element0{ ptr[0] };                 // element0 = 5
//      ptr[3] = 3;                             // v1[3] = 3
//
// Again, `const` and `non-const` versions of `data()` should be included
//
//      T* data() { ... }
//      const T* data() const { ... }
//
// Append element:
//
//      course::Vector<int> v1;                 // v1 is empty
//      v1.push_back(5);                        // v1 is { 5 }
//      v1.push_back(6);                        // v1 is { 5,6 }
//      v1.push_back(7);                        // v1 is { 5,6,7 }
//      int size1{ v1.size() };                 // size1 = 3
//
// Insert element:
//
//      course::Vector<int> v1;                 // v1 is empty
//      v1.insert(0, 5);                        // v1 is { 5 }
//      v1.insert(0, 6);                        // v1 is { 6,5 }
//      v1.insert(1, 7);                        // v1 is { 6,7,5 }
//
// Expand capacity:
//
//      course::Vector<int> v1;                 // v1 is empty
//      v1.reserve(10);
//      int c1{ v1.capacity() };                // c1 = 10
//      v1.reserve(5);
//      int c2{ v1.capacity() };                // c2 = 10
//      v1.reserve(12);
//      int c3{ v1.capacity() };                // c3 = 12
//
// Expand size:
//
//      course::Vector<int> v1;                 // v1 is empty
//      v1.resize(3);
//      int s1{ v1.size() };                    // s1 = 3
//      v1.resize(5);
//      int s2{ v1.size() };                    // s2 = 5
//      v1.resize(7);
//      int s3{ v1.size() };                    // s3 = 7
//
// Clear vector contents:
//
//      course::Vector<int> v1;                 // v1 is empty
//      v1.resize(20);
//      int s1{ v1.size() };                    // s1 = 20
//      v1.clear();
//      int s2{ v1.size() };                    // s1 = 0
//
// Copies, assignment, and comparison must be supported as well:
//
//      course::Vector<int> v1;                 // v1 is empty
//      v1.push_back(1);                        // v1 is { 1 }
//      v1.push_back(2);                        // v1 is { 1,2 }
//      course::Vector<int> v2;
//      bool b1{ v1 == v2 };                    // b1 = false
//      v2 = v1;                                // v2 is { 1,2 }
//      bool b2{ v1 == v2 };                    // b2 = true
//      course::Vector<int> v3{ v1 };           // v3 is { 1,2 }
//      v1.clear();
//      bool b3{ v1 != v3 };                    // b3 = true
//
namespace course
{
  template <typename T>
  class Vector
  {
  public:
    Vector(int size = 0, const T& value = T{})
    {
      //TODO: write your code here...
    }

    int size() const
    {
      //TODO: write your code here...
    }

    T* data()
    {
      //TODO: write your code here...
    }

    const T* data() const
    {
      //TODO: write your code here...
    }

    void push_back(const T& item)
    {
      //TODO: write your code here...
    }

    T& operator[](int index)
    {
      //TODO: write your code here...
    }

    const T& operator[](int index) const
    {
      //TODO: write your code here...
    }

  };
}