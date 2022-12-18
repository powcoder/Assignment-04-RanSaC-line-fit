https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
#!/bin/sh

BUILD_DIR="build"
GENERATOR=""

if [[ $OSTYPE == "darwin"* ]]; then
  #Mac OSX
  GENERATOR="-G Xcode"
fi

cmake $GENERATOR -S . -B $BUILD_DIR&&cmake --build $BUILD_DIR --config Release 

