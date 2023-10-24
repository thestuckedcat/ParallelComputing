cmake_minimum_required(VERSION 3.0)

project(TimeIt)

enable_testing()

add_executable(TimeIt TimeIt.cpp)

add_test(
    NAME blur_short_commit WORKING_DIRECTORY 
    ${CMAKE_BINARY_DIRECTORY}
    COMMAND
    ${CMAKE_CURRENT_SOURCE_DIR}/blur_short.ctest
)


add_test(
    NAME blur_long WORKING_DIRECTORY
    ${CMAKE_BINARY_DIRECTORY}
    COMMAND
    ${CMAKE_CURRENT_SOURCE_DIR}/blur_long.ctest
)

add_custom_target(
    commit_tests
    COMMAND
    ctest -R commit DEPENDS <myapp>
)

add_custom_target(
    distclean
    COMMAND
    rm -rf CMakeCache.txt CmakeFiles
    CTestTestfile.cmake Makefile Testing
    cmake_install.cmake
)