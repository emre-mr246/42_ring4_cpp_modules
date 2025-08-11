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
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

Base *generate(void)
{
    FILE *urandom;
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

void identify(Base *p)
{
    if (!p)
    {
        std::cout << "Error: cannot identify null pointer!" << std::endl;
        return;
    }
    if (dynamic_cast<A *>(p))
        std::cout << "Type(*): A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type(*): B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Type(*): C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "Type(&): A" << std::endl;
        return;
    } catch (std::exception &e)
    {
    }

    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "Type(&): B" << std::endl;
        return;
    } catch (std::exception &e)
    {
    }

    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "Type(&): C" << std::endl;
        return;
    } catch (std::exception &e)
    {
    }
}

int main()
{
    Base *base;

    base = generate();
    identify(base);
    identify(*base);
    identify(NULL);
    delete (base);
    return (0);
}
