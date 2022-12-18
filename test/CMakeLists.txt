https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder

set(CMAKE_FOLDER "test")

set(BUILD_TESTS $ENV{BUILD_TESTS} CACHE BOOL "Enable tests")
if (BUILD_TESTS)
  message(STATUS "Build tests requested.")

  # Vector default constructor 
  add_executable(vector_construct1 EXCLUDE_FROM_ALL vector_construct1.cpp)
  target_link_libraries(vector_construct1 probLib1)

  # Vector size constructor
  add_executable(vector_construct2 EXCLUDE_FROM_ALL vector_construct2.cpp)
  target_link_libraries(vector_construct2 probLib1) 

  # Vector size and value constructor
  add_executable(vector_construct3 EXCLUDE_FROM_ALL vector_construct3.cpp)
  target_link_libraries(vector_construct3 probLib1)

  # Vector capacity
  add_executable(vector_capacity EXCLUDE_FROM_ALL vector_capacity.cpp)
  target_link_libraries(vector_capacity probLib1)

  # Vector element access
  add_executable(vector_element EXCLUDE_FROM_ALL vector_element.cpp)
  target_link_libraries(vector_element probLib1)  

  # Vector data pointer
  add_executable(vector_pointer EXCLUDE_FROM_ALL vector_pointer.cpp)
  target_link_libraries(vector_pointer probLib1)

  # Vector append element
  add_executable(vector_append EXCLUDE_FROM_ALL vector_append.cpp)
  target_link_libraries(vector_append probLib1)

  # Vector insert element
  add_executable(vector_insert EXCLUDE_FROM_ALL vector_insert.cpp)
  target_link_libraries(vector_insert probLib1)

  # Vector clear
  add_executable(vector_clear EXCLUDE_FROM_ALL vector_clear.cpp)
  target_link_libraries(vector_clear probLib1)

  # Vector reserve
  add_executable(vector_reserve EXCLUDE_FROM_ALL vector_reserve.cpp)
  target_link_libraries(vector_reserve probLib1)

  # Vector resize
  add_executable(vector_resize EXCLUDE_FROM_ALL vector_resize.cpp)
  target_link_libraries(vector_resize probLib1)  

  # Vector comparison operator
  add_executable(vector_compare EXCLUDE_FROM_ALL vector_compare.cpp)
  target_link_libraries(vector_compare probLib1)

  # Vector copy operations
  add_executable(vector_copy EXCLUDE_FROM_ALL vector_copy.cpp)
  target_link_libraries(vector_copy probLib1)

  # Vector assignment operator
  add_executable(vector_assignment EXCLUDE_FROM_ALL vector_assignment.cpp)
  target_link_libraries(vector_assignment probLib1)

  # LineRansac class 
  add_executable(line_ransac EXCLUDE_FROM_ALL line_ransac.cpp)
  target_link_libraries(line_ransac probLib1)

endif()  
