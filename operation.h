#ifndef OPERATION_H
#define OPERATION_H

#include <memory>
#include <string>
#include <stdexcept>
#include "expression.h"
#include "number.h"

class OperationObj : public ExpressionObj {
public:
    OperationObj(const std::string &op, std::shared_ptr<ExpressionObj> left, std::shared_ptr<ExpressionObj> right)
        : op(op), left(left), right(right) {}
    
    std::string toString() const override {
        return "(" + op + " " + left->toString() + " " + right->toString() + ")";
    }

    // Change return type to std::shared_ptr<ExpressionObj>
    std::shared_ptr<ExpressionObj> evaluate(RuntimeEnv &env) override {
        auto operand1 = std::dynamic_pointer_cast<NumberObj>(left->evaluate(env));
        auto operand2 = std::dynamic_pointer_cast<NumberObj>(right->evaluate(env));

        if (!operand1 || !operand2) {
            throw std::runtime_error("Operands must be numbers.");
        }

        if (op == "+") return std::make_shared<NumberObj>(operand1->getValue() + operand2->getValue());
        if (op == "-") return std::make_shared<NumberObj>(operand1->getValue() - operand2->getValue());
        if (op == "*") return std::make_shared<NumberObj>(operand1->getValue() * operand2->getValue());
        if (op == "/") {
            if (operand2->getValue() == 0) {
                throw std::runtime_error("Division by zero");
            }
            return std::make_shared<NumberObj>(operand1->getValue() / operand2->getValue());
        }

        throw std::runtime_error("Unknown operation: " + op);
    }

private:
    std::string op;
    std::shared_ptr<ExpressionObj> left, right;
};

#endif // OPERATION_H
