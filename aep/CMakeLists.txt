project(aep)

set(MEP_HEADER_FILES
    inc/ast.hpp
    inc/evaluator.hpp
    inc/lexer.hpp
    inc/parser.hpp
)

set(MEP_SOURCE_FILES
    src/lexer.cpp
    src/parser.cpp
)

add_library(aep STATIC
    ${MEP_SOURCE_FILES}
    ${MEP_HEADER_FILES} # for IDE searching convienence
)
add_library(aeppoc::aep ALIAS aep)

target_include_directories(aep PUBLIC inc)

target_precompile_headers(aep
    PUBLIC
        <algorithm>
        <array>
        <cmath>
        <cassert>
        <format>
        <regex>
        <sstream>
        <stdexcept>
        <string>
        <string_view>
        <unordered_map>
        <vector>
)

if(MSVC)
  target_compile_options(aep PRIVATE /W4 /WX)
else()
  target_compile_options(aep PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
