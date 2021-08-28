project(mep)

set(MEP_HEADER_FILES
    inc/lexer.hpp
    inc/parser.hpp
    inc/visitor.hpp
)

set(MEP_SOURCE_FILES
    src/lexer.cpp
    src/parser.cpp
)

add_library(mep STATIC
    ${MEP_SOURCE_FILES}
    ${MEP_HEADER_FILES} # for IDE searching convienence
)
add_library(meppoc::mep ALIAS mep)

target_include_directories(mep PUBLIC inc)

target_precompile_headers(mep
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
