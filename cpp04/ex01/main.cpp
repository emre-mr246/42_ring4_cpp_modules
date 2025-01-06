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

    delete(dog);

    std::cout << std::endl << "== DEEP COPY TEST 1 ==" << std::endl; 
    std::cout <<  "=======================================" << std::endl;

    Dog dog_local1;
    Dog dog_local2;

    dog_local1.newIdea(1, "Ben muz yemek istiyorum.");
    dog_local2 = dog_local1;
    std::cout << dog_local1.getIdea(1) << std::endl; 
    dog_local2.newIdea(1, "Ben kek yemek istiyorum.");
    std::cout << dog_local1.getIdea(1) << std::endl; 
    std::cout << dog_local2.getIdea(1) << std::endl; 

    std::cout << std::endl << "== DEEP COPY TEST 2 ==" << std::endl; 
    std::cout <<  "=======================================" << std::endl;

    Dog *dog_copy = new Dog();
    Dog *dog_copy2 = new Dog(*dog_copy);

    dog_copy->newIdea(1, "Günde bir bardak su içmeliyiz.");
    dog_copy2->newIdea(1, "Günde iki bardak su içmeliyiz.");
    std::cout << dog_copy->getIdea(1) << std::endl; 
    std::cout << dog_copy2->getIdea(1) << std::endl; 

    delete (dog_copy);
    delete (dog_copy2);

    std::cout << std::endl << "== DEEP COPY TEST 3 ==" << std::endl; 
    std::cout <<  "=======================================" << std::endl;

    Dog dog_test;
    Dog dog_test2(dog_test);

    dog_test.newIdea(1, "Ben elma yemek istiyorum.");
    dog_test2 = dog_test;
    std::cout << dog_test.getIdea(1) << std::endl; 
    dog_test2.newIdea(1, "Ben armut yemek istiyorum.");
    std::cout << dog_test.getIdea(1) << std::endl; 
    std::cout << dog_test2.getIdea(1) << std::endl; 

    return (0);
}
