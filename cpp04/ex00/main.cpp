#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
 const Animal* meta = new Animal();
 const Animal* j = new Dog();
 const Animal* i = new Cat();
 i->makeSound();
 j->makeSound();
 meta->makeSound();

 return 0;
}