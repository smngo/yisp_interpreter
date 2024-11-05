#include "evaluator.h"
#include "number.h"
#include "operation.h"

std::shared_ptr<ExpressionObj> Evaluator::evaluate(std::shared_ptr<ExpressionObj> expression, RuntimeEnv &env) {
    if (!expression) return nullptr;
    return expression->evaluate(env);
}
