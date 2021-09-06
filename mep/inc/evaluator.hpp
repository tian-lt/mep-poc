#ifndef MEP_VISITOR_H
#define MEP_VISITOR_H

#include <functional>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
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

    struct EvaluationError : public std::runtime_error{
        EvaluationError() noexcept : std::runtime_error("failed to evaluate an ast node.") {}
        explicit EvaluationError(const std::string& msg) noexcept : std::runtime_error(msg){}
        EvaluationError(const EvaluationError&) = delete;
        EvaluationError(EvaluationError&&) = default;
    };
    
    template<class... _IntTs>
    class Interpreter {
    public:
        Interpreter() {};
        constexpr explicit Interpreter(_IntTs&&... ts)
            : _ints(std::forward<_IntTs>(ts)...)
        {}
        Interpreter(const Interpreter&) = default;
        Interpreter(Interpreter&&) noexcept = default;
    public:
        template<class _IntT>
        void assign(_IntT&& intf) {
            std::get<_IntT>(_ints) = std::forward<_IntT>(intf);
        }
        template<class _IntT>
        const _IntT& interprets() const {
            return std::get<_IntT>(_ints);
        }
    private:
        std::tuple<_IntTs...> _ints;
    };

    template<class _Tv>
    struct RequiredIntTypes {
        struct number_t{
            constexpr number_t(std::function<_Tv(const Token& tok)> f) : invoke(f) {}
            const std::function<_Tv(const Token& tok)> invoke;
        };
        struct positive_t{
            constexpr positive_t(std::function<_Tv(const _Tv& operand)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& operand)> invoke;
        };
        struct negative_t{
            constexpr negative_t(std::function<_Tv(const _Tv& operand)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& operand)> invoke;
        };
        //using factorial_t = std::function<_Tv(const _Tv& operand)>;
        //using percent_t = std::function<_Tv(const _Tv& operand)>;
        //using add_t = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
        //using sub_t = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
        //using mul_t = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
        //using div_t = std::function<_Tv(const _Tv& lhs, const _Tv& rhs)>;
        //using pow_t = std::function<_Tv(const _Tv& base, const _Tv& exponent)>;
        struct pow_t {
            constexpr pow_t(std::function<_Tv(const _Tv& base, const _Tv& exponent)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& base, const _Tv& exponent)> invoke;
        };
        struct func_t {
            constexpr func_t(std::function<_Tv(const std::string& identifier, const std::vector<_Tv>& params)> f) : invoke(f) {}
            const std::function<_Tv(const std::string& identifier, const std::vector<_Tv>& params)> invoke;
        };
    };

    template<class _Tv>
    using required_int_t = Interpreter<
        typename RequiredIntTypes<_Tv>::number_t,
        typename RequiredIntTypes<_Tv>::positive_t,
        typename RequiredIntTypes<_Tv>::negative_t,
        typename RequiredIntTypes<_Tv>::pow_t,
        typename RequiredIntTypes<_Tv>::func_t
    >;

    template<class _Tv>
    using function_call_t = std::function<_Tv(const std::vector<_Tv>&)>;

    template<class _Tv>
    class Evaluator {
    public:
        Evaluator(const required_int_t<_Tv>& ints)
            : _ints(ints) {}
        Evaluator(required_int_t<_Tv>&& ints)
            : _ints(std::move(ints)) {}
        _Tv eval_expression(const ast::Expression& expression) const;
        _Tv eval_atom(const ast::Atom& atom) const;
        _Tv eval_exponentiation(const ast::Exponentiation& exponentiation) const;
        _Tv eval_parenthesized(const ast::Parenthesized& parenthesized) const;
        _Tv eval_prefix_unary_expression(const ast::PrefixUnaryExpression& prefix_unary_expression) const;
        _Tv eval_function(const ast::Function& func) const;
        _Tv eval_number(const Token& tok) const;
        std::vector<_Tv> eval_paramlist(const ast::ParameterList& plist) const;
    private:
        required_int_t<_Tv> _ints;
    };

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_expression(const ast::Expression& expression) const {
        throw 0;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_atom(const ast::Atom& atom) const{
        if (atom.number.has_value()) {
            return eval_number(atom.number.value());
        }
        else if (atom.parenthesized.has_value()) {
            return eval_parenthesized(*(atom.parenthesized.value()));
        }
        else if (atom.function.has_value()) {
            return eval_function(*(atom.function.value()));
        }
        else if (atom.prefix_unary_expression.has_value()) {
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_exponentiation(const ast::Exponentiation& exponentiation) const {
        _Tv result = _ints.interprets<RequiredIntTypes<_Tv>::pow_t>().invoke(
            eval_atom(*exponentiation.base),
            eval_atom(*exponentiation.exponent));
        ast::ContinuedExponentiation* next = exponentiation.continued.get();
        while (!next->is_empty) {
            result = _ints.interprets<RequiredIntTypes<_Tv>::pow_t>().invoke(
                result,
                eval_atom(*next->exponent));
        }
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_parenthesized(const ast::Parenthesized& parenthesized) const {
        return eval_expression(*(parenthesized.expression));
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_prefix_unary_expression(const ast::PrefixUnaryExpression& prefix_unary_expression) const {
        if (prefix_unary_expression.minus_atom.has_value()) {
            auto atom = eval_atom(*(prefix_unary_expression.minus_atom.value()));
            return _ints.interprets<RequiredIntTypes<_Tv>::negative_t>().invoke(atom);
        }
        else if (prefix_unary_expression.plus_atom.has_value()) {
            auto atom = eval_atom(*(prefix_unary_expression.plus_atom.value()));
            return _ints.interprets<RequiredIntTypes<_Tv>::positive_t>().invoke(atom);
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_function(const ast::Function& function) const {
        auto params = eval_paramlist(*(function.paramlist));
        auto funcname = std::get<std::string>(function.identifier.payload);
        return _ints.interprets<RequiredIntTypes<_Tv>::func_t>().invoke(funcname, params);
    }

    template<class _Tv>
    inline std::vector<_Tv> Evaluator<_Tv>::eval_paramlist(const ast::ParameterList& params) const {
        std::vector<_Tv> result;
        ast::ContinuedParameterList* next = nullptr;
        if (!params.is_empty) {
            auto vexpr = eval_expression(*(params.expression));
            result.emplace_back(std::move(vexpr));
            next = params.continued.get();
            while (!next->is_empty) {
                vexpr = eval_expression(*(params.expression));
                result.emplace_back(std::move(vexpr));
                next = params.continued.get();
            }
        }
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_number(const Token& tok) const {
        return _ints.interprets<RequiredIntTypes<_Tv>::number_t>().invoke(tok);
    }

    // utility converters
    inline double token_to_double_converter(const Token& t) {
        return std::stod(std::get<std::string>(t.payload));
    }
} // namespace mep

#endif // !MEP_VISITOR_H
