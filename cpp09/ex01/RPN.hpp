/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:01:08 by emgul            #+#    #+#              */
/*   Updated: 2025/08/26 16:31:00 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN
{
  private:
    RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);
    ~RPN();

    static size_t isValidNumber(const std::string &token);
    static size_t isValidOperator(const std::string &token);
    static long long performOperation(std::stack<long long> &stack, const std::string &op);
    static void pushNumber(std::stack<long long> &stack, const std::string &token);

  public:
    static long long calculate(const std::string &expression);
};
