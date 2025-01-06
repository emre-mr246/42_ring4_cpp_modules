#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal *meta = new Animal();
    // meta->makeSound();
    // delete (meta);
    // std::cout << std::endl;

    // Animal *d = new Dog();
    // d->makeSound();
    
    // delete (d);
    // std::cout << std::endl;

    // const Animal *c = new Cat();
    // c->makeSound();
    // delete (c);
    // std::cout << std::endl;

    // const WrongAnimal *w = new WrongCat();
    // w->makeSound();
    // delete (w);

    // BASIC IDEA TEST
    std::cout << std::endl << "=======================================" << std::endl << std::endl;

    Dog *dog = new Dog();

    std::cout << dog->getIdea(1) << std::endl;
    dog->newIdea(1, "kediler düşmandır");
    std::cout << dog->getIdea(2) << std::endl;
    std::cout << dog->getIdea(1) << std::endl;
    std::cout << dog->getIdea(124) << std::endl;
    std::cout << dog->getIdea(99) << std::endl;
    std::cout << dog->getIdea(-1) << std::endl;

    std::cout << std::endl << "== DEEP COPY TEST ==" << std::endl; 
    std::cout <<  "=======================================" << std::endl;

    // Dog *dog2(dog);
    Dog *dog3 = new Dog();

    dog3 = dog;

    // dog2->newIdea(1, "kediler dosttur");
    dog3->newIdea(1, "kediler köpektir");

    std::cout << dog->getIdea(1) << std::endl;
    // std::cout << dog2->getIdea(1) << std::endl;
    std::cout << dog3->getIdea(1) << std::endl;

    // // LEAK TEST
    // std::cout << std::endl << "=======================================" << std::endl << std::endl;
    
    // dog->newIdea(1, "kediler yeni bir fikirdir");
    // std::cout << dog->getIdea(1) << std::endl << std::endl;

    // delete(dog);
    // // delete(dog2);
    // delete(dog3);

    return (0);
}
