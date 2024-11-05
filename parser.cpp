#include "parser.h"
#include "number.h"
#include "operation.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

// Assuming Tokenizer is a class that reads the input and provides tokens one by one
class Tokenizer {
public:
    Tokenizer(const std::string& input) : input(input), pos(0) {}

    std::string nextToken() {
        skipWhitespace();
        if (pos >= input.length()) return ""; // End of input

        char current = input[pos];

        // Handle parentheses
        if (current == '(' || current == ')') {
            return std::string(1, current++);
        }

        std::string token;
        while (pos < input.length() && !isspace(input[pos]) && input[pos] != '(' && input[pos] != ')') {
            token += input[pos++];
        }
        return token;
    }

private:
    std::string input;
    size_t pos;

    void skipWhitespace() {
        while (pos < input.length() && isspace(input[pos])) {
            pos++;
        }
    }
};

// Function to parse a complete expression
std::shared_ptr<ExpressionObj> parseExpression(Tokenizer& tokenizer);

// Function to parse a number
std::shared_ptr<ExpressionObj> parseNumber(const std::string& token) {
    try {
        return std::make_shared<NumberObj>(std::stoi(token)); // Convert string to integer
    } catch (const std::invalid_argument& e) {
        throw std::runtime_error("Invalid number: " + token);
    }
}

// Function to parse an operation
std::shared_ptr<ExpressionObj> parseOperation(Tokenizer& tokenizer) {
    std::string operatorToken = tokenizer.nextToken();
    if (operatorToken == "") {
        throw std::runtime_error("Expected operator, got end of input");
    }

    auto operand1 = parseExpression(tokenizer);
    auto operand2 = parseExpression(tokenizer);

    return std::make_shared<OperationObj>(operatorToken, operand1, operand2);
}

// Main parsing function
std::shared_ptr<ExpressionObj> parseExpression(Tokenizer& tokenizer) {
    std::string token = tokenizer.nextToken();
    
    if (token == "(") {
        auto operation = parseOperation(tokenizer);
        tokenizer.nextToken(); // Consume the closing ")"
        return operation;
    } else if (isdigit(token[0])) {
        return parseNumber(token);
    }

    throw std::runtime_error("Unexpected token: " + token);
}

// Wrapper function to parse input
std::shared_ptr<ExpressionObj> parse(const std::string& input) {
    Tokenizer tokenizer(input);
    return parseExpression(tokenizer);
}
