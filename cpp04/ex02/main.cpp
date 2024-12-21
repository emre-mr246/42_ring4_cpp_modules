#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *d = new Dog();
    d->makeSound();
    delete (d);
    std::cout << std::endl;

    const Animal *c = new Cat();
    c->makeSound();
    delete (c);
    std::cout << std::endl;

    return (0);
}