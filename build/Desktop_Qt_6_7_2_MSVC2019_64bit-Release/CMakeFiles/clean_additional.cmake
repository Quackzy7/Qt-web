# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\myapp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\myapp_autogen.dir\\ParseCache.txt"
  "myapp_autogen"
  )
endif()
