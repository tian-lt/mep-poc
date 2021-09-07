#pragma once

#include <functional>
#include "parser.hpp"

bool handle_parser_error(
    const std::function<void(void)>& f,
    const std::function<bool(const aep::ParserError& e)>& h) {
    try
    {
        f();
    }
    catch(const aep::ParserError& ex){
        return h(ex);
    }
    return true;
};


