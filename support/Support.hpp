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

#include <new>

namespace Support
{
  class Support
  {
  public:
    Support(bool enabled = true);
    Support(int& argc, char* argv[]);
    ~Support();
  };
}

#ifdef MEMORY_CHECK
void* operator new(std::size_t count);
void* operator new[](std::size_t count);
void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;
#endif

