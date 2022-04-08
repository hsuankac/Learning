# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\qr6ci-14-assign_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\qr6ci-14-assign_autogen.dir\\ParseCache.txt"
  "qr6ci-14-assign_autogen"
  )
endif()
