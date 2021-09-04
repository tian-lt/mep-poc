#ifndef MEP_VISITOR_H
#define MEP_VISITOR_H

#include <functional>
#include <string>
#include "lexer.hpp"

namespace mep {
    // converters
    template<class _Tv>
    using add_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using sub_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using mul_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using div_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using factorial_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using percent_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using pow_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using positive_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using negative_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv>
    using function_f = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
    template<class _Tv, class _Tsrc>
    using number_f = std::function<_Tv(const _Tsrc& src)>;

    template<class _Tv, class _Tsrc, class _ConvF>
    _Tv eval_number(const _Tsrc& src, _ConvF&& convf) {
        return std::forward<_ConvF>(convf)(src);
    }

    template<class _Tv, class _ConvF>
    _Tv eval_number(const Token& src, _ConvF&& convf) {
        return std::forward<_ConvF>(convf)(src);
    }

    template<class _Tv, class _Tsrc, class _ConvF>
    _Tv eval_function(const ast::Function& func, _ConvF&& convf) {
        return std::forward<_ConvF>(convf)(func.identifier, func.);
    }


    // utility converters
    inline double token_to_double_converter(const Token& t) {
        return std::stod(std::get<std::string>(t.payload));
    }

} // namespace mep

#endif // !MEP_VISITOR_H
