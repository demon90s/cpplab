cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(PROJECT "gloabl_variables_test")

project(${PROJECT})

set(LIBS "")
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    # Linux
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # Windows
    #add_definitions(/wd"4996" /wd"4819" /wd"4129")
endif()

# choose c++ standard
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*)
source_group(TREE ${PROJECT_SOURCE_DIR}/src FILES ${SRC_FILES})

add_executable(${PROJECT} ${SRC_FILES})
target_link_libraries(${PROJECT} ${LIBS})
