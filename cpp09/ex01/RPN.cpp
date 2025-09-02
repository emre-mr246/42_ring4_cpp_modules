/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:59:05 by emgul            #+#    #+#              */
/*   Updated: 2025/08/26 16:31:00 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src)
{
    (void)src;
}

RPN &RPN::operator=(const RPN &src)
{
    (void)src;
    return (*this);
}

size_t RPN::isValidNumber(const std::string &token)
{
    size_t start = 0;
    size_t i = 0;

    if (token.empty())
        return (0);
    if (token[0] == '+' || token[0] == '-')
    {
        if (token.length() == 1)
            return (0);
        start = 1;
    }
    i = start;
    while (i < token.length())
    {
        if (!std::isdigit(token[i]))
            return (0);
        i++;
    }
    return (1);
}

size_t RPN::isValidOperator(const std::string &token)
{
    if (token.length() != 1)
        return (0);
    if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        return (1);
    return (0);
}

void RPN::pushNumber(std::stack<long long> &stack, const std::string &token)
{
    long long number = 0;
    bool isNegative = false;
    size_t start = 0;
    size_t i = 0;

    if (!isValidNumber(token))
        throw(std::runtime_error("Error: invalid number format"));
    if (token[0] == '-')
    {
        isNegative = true;
        start = 1;
    }
    else if (token[0] == '+')
    {
        isNegative = false;
        start = 1;
    }
    i = start;
    while (i < token.length())
    {
        number = number * 10 + (token[i] - '0');
        i++;
    }
    if (isNegative)
        number = -number;
    stack.push(number);
}

long long RPN::performOperation(std::stack<long long> &stack, const std::string &op)
{
    long long firstOperand;
    long long secondOperand;
    long long result;

    if (stack.size() < 2)
        throw(std::runtime_error("Error: insufficient operands for operation"));
    secondOperand = stack.top();
    stack.pop();
    firstOperand = stack.top();
    stack.pop();
    std::cout << firstOperand << " " << op << " " << secondOperand << " = ";
    if (op == "+")
        result = firstOperand + secondOperand;
    else if (op == "-")
        result = firstOperand - secondOperand;
    else if (op == "*")
        result = firstOperand * secondOperand;
    else if (op == "/")
    {
        if (secondOperand == 0)
            throw(std::runtime_error("Error: division by zero"));
        result = firstOperand / secondOperand;
    }
    else
        throw(std::runtime_error("Error: unknown operator"));
    stack.push(result);
    return (result);
}

long long RPN::calculate(const std::string &expression)
{
    std::stack<long long> stack;
    std::istringstream iss(expression);
    std::string token;

    if (expression.empty())
        throw(std::runtime_error("Error: empty expression"));
    while (iss >> token)
    {
        if (isValidNumber(token))
            pushNumber(stack, token);
        else if (isValidOperator(token))
            performOperation(stack, token);
        else
            throw(std::runtime_error("Error: invalid token"));
    }
    if (stack.empty())
        throw(std::runtime_error("Error: no result"));
    if (stack.size() != 1)
        throw(std::runtime_error("Error: too many operands"));
    return (stack.top());
}
