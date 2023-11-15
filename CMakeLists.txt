cmake_minimum_required(VERSION 3.26)
project(practice)

set(CMAKE_CXX_STANDARD 17)

add_executable(practice
    main.cpp
    src/LambdaPractice.cpp
    src/LengthOfLongestSubstring.cpp
    src/MinPathSum.cpp
    src/MergeTwoLists.cpp)