https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder

set(CMAKE_FOLDER "prob1")

add_library(probLib1
  Line.hpp
  Line.cpp
  Point.hpp
  Point.cpp
  Plot.hpp
  Plot.cpp
  LineLsq.hpp
  LineLsq.cpp
  LineRansac.hpp
  LineRansac.cpp
  Vector.hpp
 )
target_link_libraries(probLib1 PUBLIC support)

add_executable(linefit_ransac linefit_ransac.cpp)
target_link_libraries(linefit_ransac PRIVATE probLib1)

