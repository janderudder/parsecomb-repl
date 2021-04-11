#include "repl/repl.hpp"
#include <iostream>
#include <string>



void repl(Tokenizer const& tokenize, Parser<Token> const& parser)
{
    auto const coutf = std::cout.flags();
    std::cout << std::boolalpha;

    std::string input;

    while (true)
    {
        std::getline(std::cin, input);

        if (input.empty()) {
            break;
        }

        auto const tokens = tokenize(input);

        auto const output = parser(tokens);

        std::cout
            << (output.is_success() ? "success":"fail")
            << ", remaining: " << output.size()
            << "\n";
    }

    std::cout.flags(coutf);
}
