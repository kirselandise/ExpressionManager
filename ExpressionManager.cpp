#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include "ExpressionManager.h"

using namespace std; // Add the 'using namespace std' declaration

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else
        return 0; // for '(' and ')'
}

bool isBalanced(const string& expression) {
    stack<char> st;
    for (char c : expression) {
        if (c == '{' || c == '(' || c == '[') {
            st.push(c);
        }
        else if (c == '}' || c == ')' || c == ']') {
            if (st.empty() ||
                (c == '}' && st.top() != '{') ||
                (c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[')) {
                return false; // Unmatched closing parenthesis
            }
            st.pop();
        }
    }
    return st.empty(); // All parentheses are matched
}

string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> opStack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Pop '('
        }
        else if (isOperator(c)) {
            while (!opStack.empty() && getPrecedence(opStack.top()) >= getPrecedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    while (true) {
        cout << "Enter an infix expression (x to quit): ";
        getline(cin, infixExpression);

        if (infixExpression == "x") {
            break;
        }
        else {
            if (isBalanced(infixExpression)) {
                string postfixExpression = infixToPostfix(infixExpression);
                cout << "Postfix Expression: " << postfixExpression << endl;
            }
            else {
                cout << "Invalid expression. Unbalanced parentheses." << endl;
            }
        }
    }

    return 0;
}
