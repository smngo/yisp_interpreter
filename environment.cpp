#include "environment.h"

void RuntimeEnv::define(const std::string& symbol, std::shared_ptr<ExpressionObj> value) {
    bindings[symbol] = value;
}

std::shared_ptr<ExpressionObj> RuntimeEnv::lookup(const std::string& symbol) const {
    auto it = bindings.find(symbol);
    if (it != bindings.end()) {
        return it->second;
    }
    throw std::runtime_error("Undefined variable: " + symbol);
}
