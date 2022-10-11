cmake_minimum_required(VERSION 3.16.3)
project(data_structure)

set(CMAKE_CXX_STANDARD 14)

# Google Sanitizer (Only WSL)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer -g3")

add_executable(main main.cpp)
add_executable(demo demo.cpp)
add_executable(BankAndVIP BankAndVIP.cpp)

file(GLOB_RECURSE my_c_list RELATIVE ${CMAKE_SOURCE_DIR} "src/*")

foreach(file_path ${my_c_list})
    string( REPLACE ".cpp" "" new_name ${file_path} )
    get_filename_component(filename ${new_name} NAME)
    add_executable( ${filename} ${file_path} )
endforeach()