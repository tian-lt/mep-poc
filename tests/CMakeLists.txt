find_package(GTest CONFIG REQUIRED)
add_executable(meptest
    utils.hpp # for IDE searching convenience
    mock-parser.hpp # for IDE searching convenience
    common_evaluator_tests.cpp
    common_lexer_tests.cpp
    common_parser_tests.cpp
    decimal_lexer_tests.cpp
)

target_link_libraries(meptest PRIVATE GTest::gtest GTest::gtest_main meppoc::mep)
include(GoogleTest)
gtest_discover_tests(meptest WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
