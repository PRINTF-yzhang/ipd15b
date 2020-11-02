cmake_minimum_required(VERSION 3.3)
project(ipd15b CXX)
include(.ipd/cmake/CMakeLists.txt)

add_cxx_test_program(wugraph_struct_test
        test/wugraph_struct_test.cxx
        src/wugraph_struct.cxx)

add_cxx_test_program(wugraph_class_test
        test/wugraph_class_test.cxx
        src/wugraph_class.cxx)

