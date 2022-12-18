https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder

set(CMAKE_FOLDER "test")

#support library
add_library(support STATIC
  Support.hpp
  Support.cpp
)
target_include_directories(support PUBLIC ${CMAKE_CURRENT_LIST_DIR})

set(MEMORY_CHECK "$ENV{MEMORY_CHECK}" CACHE BOOL "Enable memory checks")
if (MEMORY_CHECK)
  message(STATUS "Enable memory checks requested.")
  target_compile_definitions(support PUBLIC MEMORY_CHECK)
endif()

