/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:09:39 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:09:40 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
    std::cout << std::endl << "== BASIC TEST ==" << std::endl;
    std::cout << "=======================================" << std::endl;

    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character *emre = new Character("Emre");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    emre->equip(tmp);
    tmp = src->createMateria("cure");
    emre->equip(tmp);
    Character *bob = new Character("Cicin Büyücüsü Bob");
    std::cout << std::endl;
    emre->use(0, *bob);
    emre->use(1, *bob);

    std::cout << std::endl << "== DEEP COPY TEST ==" << std::endl;
    std::cout << "=======================================" << std::endl;

    delete (bob);
    bob = new Character(*emre);

    emre->printInventory();
    bob->printInventory();

    emre->unequip();

    emre->printInventory();
    bob->printInventory();

    delete (emre);
    delete (src);
    delete (bob);
    return (0);
}
