#ifndef PARSER_H
#define PARSER_H

#include <memory>
#include <string>
#include "expression.h"

std::shared_ptr<ExpressionObj> parse(const std::string &input);

#endif // PARSER_H
