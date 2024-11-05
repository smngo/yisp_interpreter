#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>
#include "expression.h" // Ensure ExpressionObj and its derived classes are included

class RuntimeEnv {
public:
    void define(const std::string& symbol, std::shared_ptr<ExpressionObj> value);
    std::shared_ptr<ExpressionObj> lookup(const std::string& symbol) const;

private:
    std::unordered_map<std::string, std::shared_ptr<ExpressionObj>> bindings;
};

#endif
