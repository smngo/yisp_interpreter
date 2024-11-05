#include "environment.h"
#include "parser.h"
#include "evaluator.h"
#include <iostream>

int main() {
    RuntimeEnv env;
    std::string input;

    std::cout << "Welcome to Yisp! Enter Lisp expressions or 'exit' to quit.\n";
    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, input);
        
        if (input == "exit") break;
        
        try {
            auto parsedExpr = parse(input);
            auto result = evaluate(parsedExpr, env);
            std::cout << "=> " << result->toString() << "\n";
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }
    return 0;
}
