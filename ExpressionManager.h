#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char c); // Checks if the infix expression is using proper operators
int getPrecedence(char op); // Checks precedence of operators
bool isBalanced(const string& expression); // Checks if parentheses are balanced
string infixToPostfix(const string& infix); // Changes input to a postfix expression

#endif // EXPRESSION_MANAGER_H
