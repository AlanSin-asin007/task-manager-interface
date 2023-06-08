# <<<<<<< HEAD
# CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# ADD_SUBDIRECTORY(googletest)

# ADD_EXECUTABLE(test
#     Test/test.cpp
#     Test/DBManagerTests.cpp
#     src/DBManager.cpp
#     src/Person.cpp
#     src/Task.cpp
    
    
# )

# TARGET_LINK_LIBRARIES(test gtest)
# TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

cmake_minimum_required(VERSION 3.2)
project(cs100FinalProject)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")


add_subdirectory(googletest)

add_executable(test 
    #test/test.cpp
    Test/DBManagerTests.cpp
    src/DBManager.cpp
    src/DateSorter.cpp
    src/TaskSorter.cpp
    src/Person.cpp
    src/Task.cpp
)

target_link_libraries(test gtest gmock)
target_compile_definitions(test PRIVATE gtest_disable_pthreads=ON)

