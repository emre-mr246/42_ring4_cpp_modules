#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "Default constructor called for MateriaSource." << std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
	}
    std::cout << "Destructor called for MateriaSource." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src): IMateriaSource(src)
{
    *this = src;
    std::cout << "Copy constructor called for MateriaSource." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete (this->_inventory[i]);
		if (src._inventory[i])
			this->_inventory[i] = (src._inventory[i])->clone();
	}
    std::cout << "Copy assignment operator called for MateriaSource." << std::endl;
    return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for (int i = 0; i < 4; ++i)
    {
        if ((this->_inventory)[i] == NULL)
        {
            (this->_inventory)[i] = materia;
            std::cout << "Materia " << materia->getType() << " learned.\n";
            return ;
        }
    }
    std::cout << "Can't learn more than 4 Materia.\n";
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] && this->_inventory[i]->getType() == type)
        {
            std::cout << "Materia " << type << " created.\n";
            return (this->_inventory[i]->clone());
        }
    }
    std::cout << type << " materia does not exist.\n";
    return (NULL);
}

void MateriaSource::materiaList()
{
    int i;

    std::cout << "== Inventory ==" << std::endl;
    i = 0;
    while(i < 3)
    {
        if (this->_inventory[i])
            std::cout << "[" << i << "] " << this->_inventory[i]->getType() << std::endl;
        i++;
    }
}
