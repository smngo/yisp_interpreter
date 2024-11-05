#ifndef NUMBER_H
#define NUMBER_H

#include <memory>
#include <string>
#include <iostream>

class NumberObj {
public:
    NumberObj(int value) : value(value) {}

    int getValue() const {
        return value;
    }

    std::shared_ptr<NumberObj> add(const NumberObj& other) const {
        return std::make_shared<NumberObj>(value + other.getValue());
    }

    std::shared_ptr<NumberObj> subtract(const NumberObj& other) const {
        return std::make_shared<NumberObj>(value - other.getValue());
    }

    std::shared_ptr<NumberObj> multiply(const NumberObj& other) const {
        return std::make_shared<NumberObj>(value * other.getValue());
    }

    std::shared_ptr<NumberObj> divide(const NumberObj& other) const {
        if (other.getValue() == 0) {
            throw std::runtime_error("Division by zero");
        }
        return std::make_shared<NumberObj>(value / other.getValue());
    }

    std::string toString() const {
        return std::to_string(value);
    }

private:
    int value;
};

#endif // NUMBER_H
