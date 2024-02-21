#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <climits>
#include <cctype>

class RPN
{
public:
    RPN();
    RPN(const RPN &obj);
    RPN& operator=(const RPN &obj);
    ~RPN();
    static int postfixEval(std::string postfix);
    static int operation(int a, int b, char op);
    static bool isOperator(char ch);
    static int scanNum(char ch);
};

#endif
