#include "Character.hpp"

AMateria **items_on_floor = nullptr;

Character::Character(void) : _name("generic character")
{
	std::cout << GRAY << "Character standard constructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
 }

Character::Character(std::string name) : _name(name)
{
	std::cout << GRAY << "Character string constructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
}

Character::Character(Character const &src)
{
	std::cout << GRAY << "Character copy constructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = nullptr;
	*this = src;
}

Character::~Character(void)
{
	std::cout << GRAY << "Character destructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

Character &Character::operator=(Character const &rhs)
{
	std::cout << GRAY << "Character copy assignment operator called" << NO_COLOR << std::endl;

	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = nullptr;
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
	}
	this->_name = rhs._name;
	return (*this);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (m == nullptr)
	{
		std::cout << "Cannot add nullptr materia!\n";
		return ;
	}
	for (int i = 0; i < sizeof(this->_inventory) / sizeof(AMateria *); i++)
	{
		if (this->_inventory[i] == m)
		{
			std::cout << "Materia instance already in inventory of " << this->_name << std::endl;
			return ;
		}
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			std::cout << "Added " << m->getType() << " to " << this->_name << " on index " << i << std::endl;
			return ;
		}
	}
	std::cout << "Inventory of " << this->_name << " is full!" << std::endl;
	return ;
}

void Character::unequip(int idx)
{
	int size = 0;
	if (idx < 0 || idx > 3)
	{
		std::cout << "Cannot unequip: wrong inventory index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == nullptr)
	{
		std::cout << "Cannot unequip: inventory slot already empty" << std::endl;
		return ;
	}
	if (items_on_floor)
	{
		for (int i = 0; items_on_floor[i] != nullptr; i++)
			size++;
	}
	AMateria **new_floor = new AMateria*[size + 2];
	for (int i = 0; i < size; i++)
		new_floor[i] = items_on_floor[i];
	new_floor[size] = this->_inventory[idx];
	new_floor[size + 1] = nullptr;
	std::cout << this->_name << " put " << this->_inventory[idx]->getType() << " on the floor" << std::endl;
	delete [] items_on_floor;
	items_on_floor = new_floor;
	this->_inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Wrong inventory index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == nullptr)
	{
		std::cout << this->_name << " has no Materia equipped on index " << idx << std::endl;
		return ;
	}
	std::cout << this->_name << " ";
	this->_inventory[idx]->use(target);
}
