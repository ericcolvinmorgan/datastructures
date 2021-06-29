project(DataStructures)

# All sources that also need to be tested in unit tests go into a static library
file(GLOB_RECURSE DS_SRC ${PROJECT_SOURCE_DIR} *.cpp)
add_library(data_structures_lib STATIC ${DS_SRC})
target_include_directories(data_structures_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})