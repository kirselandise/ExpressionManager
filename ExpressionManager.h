#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char c);
int getPrecedence(char op);
bool isBalanced(const string& expression);
string infixToPostfix(const string& infix);

#endif // EXPRESSION_MANAGER_H
