/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:59:05 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _capacity(0)
{
}

Span::Span(unsigned int N) : _capacity(N)
{
}

Span::Span(const Span &src)
{
    *this = src;
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        this->_capacity = src._capacity;
        this->_vec = src._vec;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (this->_vec.size() >= this->_capacity)
        throw CapacityExceededException();
    this->_vec.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end)
{
    if (this->_vec.size() + std::distance(begin, end) > this->_capacity)
        throw CapacityExceededException();
    this->_vec.insert(this->_vec.end(), begin, end);
}

int Span::shortestSpan() const
{
    std::vector<int> tmp(this->_vec);
    long shortest;
    long diff;
    unsigned int i;

    if (this->_vec.size() < 2)
        throw(NotEnoughNumbersException());
    std::sort(tmp.begin(), tmp.end());
    shortest = static_cast<long>(tmp[1]) - static_cast<long>(tmp[0]);
    if (shortest == 0)
        return (0);
    i = 2;
    while (i < tmp.size())
    {
        diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
        if (diff < shortest)
        {
            if (diff == 0)
                return (0);
            shortest = diff;
        }
        i++;
    }
    return (static_cast<int>(shortest));
}

int Span::longestSpan() const
{
    std::vector<int>::const_iterator itMin;
    std::vector<int>::const_iterator itMax;
    long diff;

    if (this->_vec.size() < 2)
        throw(NotEnoughNumbersException());
    itMin = std::min_element(this->_vec.begin(), this->_vec.end());
    itMax = std::max_element(this->_vec.begin(), this->_vec.end());
    diff = static_cast<long>(*itMax) - static_cast<long>(*itMin);
    return (static_cast<int>(diff));
}

const char *Span::CapacityExceededException::what() const throw()
{
    return ("Container capacity exceeded!");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("Not enough numbers to calculate span!");
}