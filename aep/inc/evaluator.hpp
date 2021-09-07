#ifndef AEP_EVALUATOR_H
#define AEP_EVALUATOR_H

#include <functional>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include "lexer.hpp"

namespace aep {
    struct EvaluationError : public std::runtime_error {
        EvaluationError() noexcept : std::runtime_error("failed to evaluate an ast node.") {}
        explicit EvaluationError(const std::string& msg) noexcept : std::runtime_error(msg) {}
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
        struct number_t {
            constexpr number_t(std::function<_Tv(const Token& tok)> f) : invoke(f) {}
            const std::function<_Tv(const Token& tok)> invoke;
        };
        struct positive_t {
            constexpr positive_t(std::function<_Tv(const _Tv& operand)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& operand)> invoke;
        };
        struct negative_t {
            constexpr negative_t(std::function<_Tv(const _Tv& operand)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& operand)> invoke;
        };
        struct add_t{
            constexpr add_t(std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> invoke;
        };
        struct sub_t{
            constexpr sub_t(std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> invoke;
        };
        struct mul_t{
            constexpr mul_t(std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> invoke;
        };
        struct div_t{
            constexpr div_t(std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& lhs, const _Tv& rhs)> invoke;
        };
        struct pow_t {
            constexpr pow_t(std::function<_Tv(const _Tv& base, const _Tv& exponent)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& base, const _Tv& exponent)> invoke;
        };
        struct percent_t {
            constexpr percent_t(std::function<_Tv(const _Tv& operand)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& operand)> invoke;
        };
        struct factorial_t {
            constexpr factorial_t(std::function<_Tv(const _Tv& operand)> f) : invoke(f) {}
            const std::function<_Tv(const _Tv& operand)> invoke;
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
        typename RequiredIntTypes<_Tv>::add_t,
        typename RequiredIntTypes<_Tv>::sub_t,
        typename RequiredIntTypes<_Tv>::mul_t,
        typename RequiredIntTypes<_Tv>::div_t,
        typename RequiredIntTypes<_Tv>::pow_t,
        typename RequiredIntTypes<_Tv>::percent_t,
        typename RequiredIntTypes<_Tv>::factorial_t,
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
        _Tv eval_addition(const ast::Addition& addition) const;
        _Tv eval_subtraction(const ast::Subtraction& subtraction) const;
        _Tv eval_continued_addition_or_subtraction(const _Tv& lhs, const ast::ContinuedAdditionOrSubtraction& rhs) const;
        _Tv eval_term(const ast::Term& term) const;
        _Tv eval_multiplication(const ast::Multiplication& multiplication) const;
        _Tv eval_division(const ast::Division& division) const;
        _Tv eval_multiplication_sign_omitted(const ast::MultiplicationSignOmitted& mso) const;
        _Tv eval_continued_multiplication_or_division(const _Tv& lhs, const ast::ContinuedMultiplicationOrDivision& rhs) const;
        _Tv eval_factor(const ast::Factor& factor) const;
        _Tv eval_postfix_unary_expression(const ast::PostfixUnaryExpression& postfix_unary_expression) const;
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
        if (expression.addition.has_value()) {
            return eval_addition(*expression.addition.value());
        }
        else if (expression.subtraction.has_value()) {
            return eval_subtraction(*expression.subtraction.value());
        }
        else if (expression.term.has_value()) {
            return eval_term(*expression.term.value());
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_addition(const ast::Addition& addition) const {
        auto result = _ints.interprets<RequiredIntTypes<_Tv>::add_t>().invoke(
            eval_term(*addition.lhs),
            eval_term(*addition.rhs));
        if (!addition.continued->is_empty) {
            return eval_continued_addition_or_subtraction(result, *addition.continued);
        }
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_subtraction(const ast::Subtraction& subtraction) const {
        auto result = _ints.interprets<RequiredIntTypes<_Tv>::sub_t>().invoke(
            eval_term(*subtraction.lhs),
            eval_term(*subtraction.rhs));
        if (!subtraction.continued->is_empty) {
            return eval_continued_addition_or_subtraction(result, *subtraction.continued);
        }
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_continued_addition_or_subtraction(const _Tv& lhs, const ast::ContinuedAdditionOrSubtraction& rhs) const {
        auto result = lhs;
        const ast::ContinuedAdditionOrSubtraction* next = &rhs;
        while (next && !next->is_empty) {
            if (next->add_continued.has_value()) {
                result = _ints.interprets<RequiredIntTypes<_Tv>::add_t>().invoke(
                    result,
                    eval_term(*std::get<std::unique_ptr<ast::Term>>(rhs.add_continued.value())));
                next = std::get<std::unique_ptr<ast::ContinuedAdditionOrSubtraction>>(next->add_continued.value()).get();
            }
            else if (next->sub_continued.has_value()) {
                result = _ints.interprets<RequiredIntTypes<_Tv>::sub_t>().invoke(
                    result,
                    eval_term(*std::get<std::unique_ptr<ast::Term>>(rhs.sub_continued.value())));
                next = std::get<std::unique_ptr<ast::ContinuedAdditionOrSubtraction>>(next->sub_continued.value()).get();
            }
            else {
                throw EvaluationError();
            }
        }
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_term(const ast::Term& term) const {
        if (term.factor.has_value()) {
            return eval_factor(*term.factor.value());
        }
        else if (term.multiplication.has_value()) {
            return eval_multiplication(*term.multiplication.value());
        }
        else if (term.division.has_value()) {
            return eval_division(*term.division.value());
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_multiplication(const ast::Multiplication& multiplication) const {
        if (multiplication.lhs.has_value() && multiplication.rhs.has_value() && multiplication.continued.has_value()) {
            auto result = _ints.interprets<RequiredIntTypes<_Tv>::mul_t>().invoke(
                eval_factor(*multiplication.lhs.value()),
                eval_factor(*multiplication.rhs.value()));
            return eval_continued_multiplication_or_division(result, *multiplication.continued.value());
        }
        else if (multiplication.omitted.has_value()) {
            return eval_multiplication_sign_omitted(*multiplication.omitted.value());
        }
        throw EvaluationError();
    }

    template<class _Tv>
    _Tv Evaluator<_Tv>::eval_multiplication_sign_omitted(const ast::MultiplicationSignOmitted& mso) const{
        if (mso.factor_parenthesized.has_value()) {
            auto lhs = eval_factor(*std::get<std::unique_ptr<ast::Factor>>(mso.factor_parenthesized.value()));
            auto rhs = eval_parenthesized(*std::get<std::unique_ptr<ast::Parenthesized>>(mso.factor_parenthesized.value()));
            auto result = _ints.interprets<RequiredIntTypes<_Tv>::mul_t>().invoke(lhs, rhs);
            return eval_continued_multiplication_or_division(result, *std::get<std::unique_ptr<ast::ContinuedMultiplicationOrDivision>>(mso.factor_parenthesized.value()));
        }
        else if (mso.factor_function.has_value()) {
            auto lhs = eval_factor(*std::get<std::unique_ptr<ast::Factor>>(mso.factor_function.value()));
            auto rhs = eval_function(*std::get<std::unique_ptr<ast::Function>>(mso.factor_function.value()));
            auto result = _ints.interprets<RequiredIntTypes<_Tv>::mul_t>().invoke(lhs, rhs);
            return eval_continued_multiplication_or_division(result, *std::get<std::unique_ptr<ast::ContinuedMultiplicationOrDivision>>(mso.factor_parenthesized.value()));
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_division(const ast::Division& division) const {
        _Tv result = _ints.interprets<RequiredIntTypes<_Tv>::div_t>().invoke(
            eval_factor(*division.lhs),
            eval_factor(*division.rhs));
        result = eval_continued_multiplication_or_division(result, *division.continued);
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_continued_multiplication_or_division(const _Tv& lhs, const ast::ContinuedMultiplicationOrDivision& rhs) const {
        _Tv result = lhs;
        const ast::ContinuedMultiplicationOrDivision* next = &rhs;
        while (!next->is_empty) {
            if(next->mul_continued.has_value()){
                auto rhs = eval_factor(*std::get<std::unique_ptr<ast::Factor>>(next->mul_continued.value()));
                result = _ints.interprets<RequiredIntTypes<_Tv>::mul_t>().invoke(result, rhs);
                next = std::get<std::unique_ptr<ast::ContinuedMultiplicationOrDivision>>(next->mul_continued.value()).get();
            }
            else if (next->div_continued.has_value()) {
                auto rhs = eval_factor(*std::get<std::unique_ptr<ast::Factor>>(next->div_continued.value()));
                result = _ints.interprets<RequiredIntTypes<_Tv>::div_t>().invoke(result, rhs);
                next = std::get<std::unique_ptr<ast::ContinuedMultiplicationOrDivision>>(next->div_continued.value()).get();
            }
            else if (next->mo_continued.has_value()) {
                if (next->mo_continued.value()->parenthesized_continued.has_value()) { // parenthesized continued
                    auto rhs = eval_parenthesized(*std::get<std::unique_ptr<ast::Parenthesized>>(next->mo_continued.value()->parenthesized_continued.value()));
                    result = _ints.interprets<RequiredIntTypes<_Tv>::mul_t>().invoke(result, rhs);
                    next = std::get<std::unique_ptr<ast::ContinuedMultiplicationOrDivision>>(next->mo_continued.value()->parenthesized_continued.value()).get();
                }
                else { // function continued
                    auto rhs = eval_function(*std::get<std::unique_ptr<ast::Function>>(next->mo_continued.value()->function_continued.value()));
                    result = _ints.interprets<RequiredIntTypes<_Tv>::mul_t>().invoke(result, rhs);
                    next = std::get<std::unique_ptr<ast::ContinuedMultiplicationOrDivision>>(next->mo_continued.value()->function_continued.value()).get();
                }
            }
        }
        return result;
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_factor(const ast::Factor& factor) const {
        if (factor.atom.has_value()) {
            return eval_atom(*factor.atom.value());
        }
        else if (factor.exponentiation.has_value()) {
            return eval_exponentiation(*factor.exponentiation.value());
        }
        else if (factor.postfix_unary_expression.has_value()) {
            return eval_postfix_unary_expression(*factor.postfix_unary_expression.value());
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_postfix_unary_expression(const ast::PostfixUnaryExpression& postfix_unary_expression) const {
        if (postfix_unary_expression.atom_operator.has_value()) {
            auto operand = eval_atom(*(std::get<std::unique_ptr<ast::Atom>>(postfix_unary_expression.atom_operator.value())));
            if (std::get<Token>(postfix_unary_expression.atom_operator.value()).token_type == TokenType::Percent) {
                return _ints.interprets<RequiredIntTypes<_Tv>::percent_t>().invoke(operand);
            }
            else if (std::get<Token>(postfix_unary_expression.atom_operator.value()).token_type == TokenType::Factorial) {
                return _ints.interprets<RequiredIntTypes<_Tv>::factorial_t>().invoke(operand);
            }
            throw EvaluationError();
        }
        if (postfix_unary_expression.power.has_value()) {
            auto exp = eval_exponentiation(*(std::get<std::unique_ptr<ast::Exponentiation>>(postfix_unary_expression.power.value())));
            if (std::get<Token>(postfix_unary_expression.power.value()).token_type == TokenType::Percent) {
                return _ints.interprets<RequiredIntTypes<_Tv>::percent_t>().invoke(exp);
            }
            else if(std::get<Token>(postfix_unary_expression.power.value()).token_type == TokenType::Factorial){
                return _ints.interprets<RequiredIntTypes<_Tv>::factorial_t>().invoke(exp);
            }
        }
        throw EvaluationError();
    }

    template<class _Tv>
    inline _Tv Evaluator<_Tv>::eval_atom(const ast::Atom& atom) const{
        if (atom.number.has_value()) {
            return eval_number(atom.number.value());
        }
        else if (atom.parenthesized.has_value()) {
            return eval_parenthesized(*atom.parenthesized.value());
        }
        else if (atom.function.has_value()) {
            return eval_function(*atom.function.value());
        }
        else if (atom.prefix_unary_expression.has_value()) {
            return eval_prefix_unary_expression(*atom.prefix_unary_expression.value());
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
                vexpr = eval_expression(*(next->expression));
                result.emplace_back(std::move(vexpr));
                next = next->continued.get();
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
} // namespace aep

#endif // !AEP_EVALUATOR_H
