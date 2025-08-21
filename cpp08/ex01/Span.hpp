/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:01:08 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Span
{
  private:
    unsigned int _capacity;
    std::vector<int> _vec;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin,
                   std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    class CapacityExceededException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class NotEnoughNumbersException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif