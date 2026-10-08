cmake_minimum_required(VERSION 4.3)
project(IntroToJavaProgrammingC C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

function(add_problem chapter name)
    set(dir ${chapter}/${name})

    add_library(${name} STATIC ${dir}/${name}.c)
    target_include_directories(${name} PUBLIC ${dir})

    add_executable(${name}_main ${dir}/main.c)
    target_link_libraries(${name}_main PRIVATE ${name})

    add_executable(${name}_test ${dir}/${name}_test.c)
    target_link_libraries(${name}_test PRIVATE ${name})

    add_test(NAME ${name} COMMAND ${name}_test)
endfunction()

add_problem(chapter03 problem3_28)
add_problem(chapter03 problem3_29)
add_problem(chapter03 problem3_30)
add_problem(chapter03 problem3_31)