#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <memory>

class RuntimeEnv; // Forward declaration

class ExpressionObj {
public:
    virtual ~ExpressionObj() = default; // Virtual destructor
    virtual std::shared_ptr<ExpressionObj> evaluate(RuntimeEnv& env) = 0; // Pure virtual function
};

#endif // EXPRESSION_H
