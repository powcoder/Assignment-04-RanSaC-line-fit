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

#include "Support.hpp"

#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <exception>
#include <atomic>
#include <mutex>

#ifdef MEMORY_CHECK
namespace
{
  template <typename T> struct Allocator
  {
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    Allocator() = default;
    template <class U> constexpr Allocator(const Allocator <U>&) noexcept {}
    T* allocate(std::size_t n) { return reinterpret_cast<T*>(std::malloc(n * sizeof(T))); }
    void deallocate(T* p, std::size_t) { std::free(p); }
  };
  class SupportImpl
  {
    //static members ---------------------------------------------------------
    static std::atomic_bool enabled_;
    //non-static members -----------------------------------------------------
    size_t total_;
    bool error_;
    std::mutex mutex_;
    using Key = void*;
    using Val = std::size_t;
    std::unordered_map<Key, Val,
      std::hash<Key>, std::equal_to<Key>,
      Allocator<std::pair<const Key, Val>>> map_;
    SupportImpl() : map_ {}, total_{ 0 }, error_{ false }, mutex_{}
    {
    }
    void add_(void* ptr, std::size_t count) {
      //ptr is never nullptr
      const std::lock_guard<std::mutex> lock{ mutex_ };
      map_[ptr] = count; total_ += count;
    }
    void remove_(void* ptr) {
      const std::lock_guard<std::mutex> lock{ mutex_ };
      auto it{ map_.find(ptr) };
      if (it != map_.end()) {
        map_.erase(it);
      }
      //else {
      //  if (ignoreUnknown_ == false)
      //  {
      //    printf("MemoryCheck: ERROR: ptr not found!\n");
      //    error_ = true;
      //  }
      //}
    }
    bool deinit_()
    {
      enabled_ = false;
      const std::lock_guard<std::mutex> lock{ mutex_ };
      bool error{ false };
      printf("MemoryCheck: %llu total allocated bytes\n",
        static_cast<unsigned long long>(total_));
      const size_t numLeaked{ map_.size() };
      if (numLeaked > 0) {
        error = true;
        printf("MemoryCheck: ERROR: %llu blocks leaked!\n",
          static_cast<unsigned long long>(numLeaked));
        for (const auto& it : map_) {
          printf(" - block size %llu bytes\n",
            static_cast<unsigned long long>(it.second));
        }
      }
      else {
        printf("MemoryCheck: No leaked blocks detected\n");
      }
      if (error_) {
        error = true;
        printf("MemoryCheck: ERROR: some deallocation error has occurred\n");
      }
      total_ = 0;
      error_ = false;
      map_.clear();
      fflush(stdout);
      return error;
    }
    static SupportImpl& getInstance_() {
      static SupportImpl impl;
      return impl;
    }
  public:
    static void init(bool enabled = true) {
      enabled_ = enabled;
    }
    static bool deinit() {
      return enabled_ && getInstance_().deinit_();
    }
    static void* allocate(std::size_t count) {
      if (void* ptr = std::malloc(std::max(count, std::size_t{ 1 }))) {
        if (enabled_) { getInstance_().add_(ptr, count); }
        return ptr;
      }
      throw std::bad_alloc{};
    }
    static void deallocate(void* ptr) {
      if (enabled_) { getInstance_().remove_(ptr); }
      std::free(ptr);
    }
  };

  std::atomic_bool SupportImpl::enabled_{ false };
}

namespace Support
{
  Support::Support(bool enabled)
  {
    SupportImpl::init(enabled);
  }

  Support::Support(int& argc, char* argv[])
  {
    int i{ 1 }, j{ 1 };
    while (i < argc)
    {
      if (strcmp(argv[i], "--check") == 0) {
        SupportImpl::init();
        --j;
      }
      if (j < i)
      {
        argv[j] = argv[i];
      }
      ++i; ++j;
    }
    argc = j;
  }

  Support::~Support()
  {
    if (SupportImpl::deinit())
    { //errors detected
      printf("abort\n");
      std::abort();
    }
  }
}

void* operator new(std::size_t count)
{
  return SupportImpl::allocate(count);
}

void* operator new[](std::size_t count)
{
  return SupportImpl::allocate(count);
}

void operator delete(void* ptr) noexcept
{
  return SupportImpl::deallocate(ptr);
}

void operator delete[](void* ptr) noexcept
{
  return SupportImpl::deallocate(ptr);
}
#else
namespace Support
{
  Support::Support(bool enabled)
  {
  }
  Support::Support(int& argc, char* argv[])
  {
  }
  Support::~Support()
  {
  }
}
#endif
