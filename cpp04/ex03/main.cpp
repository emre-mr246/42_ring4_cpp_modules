#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    std::cout << std::endl
              << "== BASIC TEST ==" << std::endl;
    std::cout << "=======================================" << std::endl;
    
    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *emre = new Character("Emre");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    // emre->equip(tmp);
    // tmp = src->createMateria("cure");
    // emre->equip(tmp);
    // ICharacter *bob = new Character("Yaratık");
    // std::cout << std::endl;
    // emre->use(0, *bob);
    // emre->use(1, *bob);
    // std::cout << std::endl;
    free(tmp);
    // std::cout << std::endl
    //           << "== DEEP COPY TEST ==" << std::endl;
    // std::cout << "=======================================" << std::endl;

    // delete (bob);
    delete (emre);
    delete (src);
    return (0);
}