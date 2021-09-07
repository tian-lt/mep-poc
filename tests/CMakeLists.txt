find_package(GTest CONFIG REQUIRED)
add_executable(aeptest
    utils.hpp # for IDE searching convenience
    mock-parser.hpp # for IDE searching convenience
    common_evaluator_tests.cpp
    common_lexer_tests.cpp
    common_parser_tests.cpp
    decimal_lexer_tests.cpp
    evaluator_insane_tests.cpp
)

target_link_libraries(aeptest PRIVATE GTest::gtest GTest::gtest_main aeppoc::aep)
include(GoogleTest)
gtest_discover_tests(aeptest WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
