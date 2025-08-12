/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul            #+#    #+#              */
/*   Updated: 2025/08/12 19:03:34 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T> class Array
{
  private:
    T *_arr;
    unsigned int _size;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array &src);
    Array &operator=(const Array &src);
    ~Array();

    unsigned int size() const;
    void printArray() const;

    T &operator[](unsigned int i);
    T const &operator[](unsigned int i) const;

    class OutOfBoundsException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#include "Array.tpp"

#endif