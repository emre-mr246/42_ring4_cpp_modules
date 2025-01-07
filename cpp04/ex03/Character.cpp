#include "Character.hpp"

Character::Character(void)
{
    this->_name = "Default";
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Default constructor called for Character." << std::endl;
}

Character::Character(std::string name)
{
    this->_name = name;
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Constructor called for Character." << std::endl;
}

Character::~Character()
{
    std::cout << "Destructor called for Character." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete (this->_inventory[i]);
    }
}

Character::Character(const Character &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
        {
            this->_inventory[i] = src._inventory[i]->clone();
            if (!this->_inventory[i])
                std::cerr << "Clone failed for inventory item " << i << std::endl;
        }
        else
            this->_inventory[i] = NULL;
    }
    std::cout << "Copy constructor called for Character." << std::endl;
}

Character &Character::operator=(const Character &src)
{
    if (this == &src)
        return (*this);
    for(int i = 0; i < 4; i++)
	{
        if (this->_inventory[i])
                delete (this->_inventory[i]);
        if (src._inventory[i])
        {
            this->_inventory[i] = (src._inventory[i])->clone();
            if (!this->_inventory[i])
                std::cerr << "Clone failed for inventory item " << i << std::endl;
        }
	}
    std::cout << "Copy assignment operator called for Character." << std::endl;
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
    {
        std::cout << this->_name << " attempted to equip an empty materia.\n";
        return ;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << this->_name << " successfully equipped " << m->getType() << " in slot " << i << "\n";
            return ;
        }
    }
    std::cout << this->_name << " can't equip more than 4 Materia.\n";
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << this->_name << " tried to unequip from an invalid slot " << idx << ".\n";
        return ;
    }
    if (!(this->_inventory)[idx])
    {
        std::cout << this->_name << " has no materia equipped at slot " << idx << ".\n";
        return ;
    }
    AMateria* ptr = (this->_inventory)[idx];
    std::cout << this->_name << " unequipped " << ptr->getType() << " from slot " << idx << ".\n";
    (this->_inventory)[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || !(this->_inventory)[idx])
    {
        std::cout << this->getName() << " tried to use a materia at an invalid or empty slot " << idx << ".\n";
        return ;
    }
    std::cout << this->getName() << " used " << (this->_inventory)[idx]->getType() << " materia on " << target.getName() << ".\n";
    (this->_inventory)[idx]->use(target);
}

void Character::printInventory() const
{
    int i;

    std::cout << "== " << this->getName() << "'s Inventory ==" << std::endl;
    i = 0;
    while(i < 4)
    {
        if (this->_inventory[i])
            std::cout << "[" << i << "] " << this->_inventory[i]->getType() << std::endl;
        i++;
    }
    std::cout << "===== END ==" << std::endl;
}
