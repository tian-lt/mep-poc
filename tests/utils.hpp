#pragma once

#include <functional>
#include "parser.hpp"

bool handle_parser_error(
    const std::function<void(void)>& f,
    const std::function<bool(const mep::ParserError& e)>& h) {
    try
    {
        f();
    }
    catch(const mep::ParserError& ex){
        return h(ex);
    }
    return true;
};


