#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "expression.h"

class RuntimeEnv; // Forward declaration

class Evaluator {
public:
    std::shared_ptr<ExpressionObj> evaluate(std::shared_ptr<ExpressionObj> expression, RuntimeEnv &env);
};

#endif // EVALUATOR_H
