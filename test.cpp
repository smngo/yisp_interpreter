#include "environment.h"
#include "parser.h"
#include "evaluator.h"
#include <iostream>

void runTests() { 
    RuntimeEnv env;

    // Test for number literals
    auto expr1 = parse("42");
    auto result1 = evaluate(expr1, env);
    std::cout << "Test Result: " << result1->toString() << " (Expected: 42)\n";

    // Test for addition
    auto expr2 = parse("(+ 3 4)");
    auto result2 = evaluate(expr2, env);
    std::cout << "Test Result: " << result2->toString() << " (Expected: 7)\n";

    // Test for subtraction
    auto expr3 = parse("(- 10 4)");
    auto result3 = evaluate(expr3, env);
    std::cout << "Test Result: " << result3->toString() << " (Expected: 6)\n";

    // Test for multiplication
    auto expr4 = parse("(* 3 5)");
    auto result4 = evaluate(expr4, env);
    std::cout << "Test Result: " << result4->toString() << " (Expected: 15)\n";

    // Test for division
    auto expr5 = parse("(/ 20 4)");
    auto result5 = evaluate(expr5, env);
    std::cout << "Test Result: " << result5->toString() << " (Expected: 5)\n";

    // Test for equality
    auto expr6 = parse("(= 5 5)");
    auto result6 = evaluate(expr6, env);
    std::cout << "Test Result: " << result6->toString() << " (Expected: T)\n";

    // Test for inequality
    auto expr7 = parse("(= 5 6)");
    auto result7 = evaluate(expr7, env);
    std::cout << "Test Result: " << result7->toString() << " (Expected: NIL)\n";

    // Test for less than
    auto expr8 = parse("(< 3 5)");
    auto result8 = evaluate(expr8, env);
    std::cout << "Test Result: " << result8->toString() << " (Expected: T)\n";

    // Test for greater than
    auto expr9 = parse("(> 5 3)");
    auto result9 = evaluate(expr9, env);
    std::cout << "Test Result: " << result9->toString() << " (Expected: T)\n";

    // Test for QUOTE
    auto expr10 = parse("(QUOTE (1 2 3))");
    auto result10 = evaluate(expr10, env);
    std::cout << "Test Result: " << result10->toString() << " (Expected: (1 2 3))\n";

    // Test for DEFINE
    auto expr11 = parse("(DEFINE x 10)");
    evaluate(expr11, env);
    auto expr11_check = parse("x");
    auto result11_check = evaluate(expr11_check, env);
    std::cout << "Test Result: " << result11_check->toString() << " (Expected: 10)\n";

    // Test for CONS
    auto expr12 = parse("(CONS 1 (QUOTE (2 3)))");
    auto result12 = evaluate(expr12, env);
    std::cout << "Test Result: " << result12->toString() << " (Expected: (1 2 3))\n";

    // Test for CAR
    auto expr13 = parse("(CAR (QUOTE (1 2 3)))");
    auto result13 = evaluate(expr13, env);
    std::cout << "Test Result: " << result13->toString() << " (Expected: 1)\n";

    // Test for CDR
    auto expr14 = parse("(CDR (QUOTE (1 2 3)))");
    auto result14 = evaluate(expr14, env);
    std::cout << "Test Result: " << result14->toString() << " (Expected: (2 3))\n";

    // Test for conditional COND
    auto expr15 = parse("(COND ((= 5 5) 1) ((= 5 6) 2))");
    auto result15 = evaluate(expr15, env);
    std::cout << "Test Result: " << result15->toString() << " (Expected: 1)\n";
}

int main() {
    runTests();
    return 0;
}
