#pragma once
#include "parsecomb/Parser.hpp"
#include "tokenizer/Token.hpp"
#include "tokenizer/Tokenizer.hpp"


void repl(Tokenizer const& tokenize, Parser<Token> const& parser);
