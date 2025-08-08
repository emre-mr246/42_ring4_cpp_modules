/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:23 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:38:23 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <stdexcept>
#include <cstdio>

Base* generate(void)
{
    FILE* urandom;
    int random;
    unsigned char buf;

    urandom = fopen("/dev/urandom", "rb");
    if (!urandom)
        throw std::runtime_error("Failed to open /dev/urandom");
    if (fread(&buf, 1, 1, urandom) != 1)
    {
        fclose(urandom);
        throw std::runtime_error("Failed to read from /dev/urandom");
    }
    fclose(urandom);
    random = buf % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception &e) {}

    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    return (0);
}
