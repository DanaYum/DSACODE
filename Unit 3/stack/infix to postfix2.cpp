#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operators;
    std::string postfix;

    for (char c : infix) {
        if (c == ' ')
            continue;

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  // Pop '('
        } else {  // Operator
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    std::string infix_expression;

    // Take input from the console
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infix_expression);

    // Convert infix expression to postfix and print the result
    std::string postfix_expression = infixToPostfix(infix_expression);
    std::cout << "Postfix expression: " << postfix_expression << "\n";

    return 0;
}
