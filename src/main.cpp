#include "parsecomb/parsecomb.hpp"
#include "repl/repl.hpp"
#include "tokenizer/Token.hpp"
#include "tokenizer/Tokenizer.hpp"
#include <iostream>
#include <string>



////////////////////////////////////////////////////////////////////////////////
auto make_parser() -> Parser<Token>
{
    auto const bl  = TokenParser<Token>("(", Token::value_eq);
    auto const br  = TokenParser<Token>(")", Token::value_eq);

    return OneOrMore(Between(bl,br)(Any<Token>));
}



////////////////////////////////////////////////////////////////////////////////
int main()
{
    std::ios_base::sync_with_stdio(false);

    Tokenizer tokenizer { Tokenizer::Separators {
        .single       = "()a{}[].,;!?",
        .maybe_double = "=&|"
    }};

    auto const comp_token = [](Token const& l, Token const& r) {
        return l.value == r.value;
    };

    std::cout << "Parser<Token> REPL\n"
              << "Enter input (blank to quit):\n";

    repl(tokenizer, make_parser());
}
