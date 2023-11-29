#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << GRAY << "MateriaSource standard constructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		this->_knowledge[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << GRAY << "MateriaSource copy constructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		this->_knowledge[i] = nullptr;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << GRAY << "MateriaSource destructor called" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_knowledge[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << GRAY << "MateriaSource copy assignment operator called" << NO_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	std::cout << GRAY << "Assigning copy" << NO_COLOR << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_knowledge[i];
		this->_knowledge[i] = nullptr;
		if (rhs._knowledge[i])
			this->_knowledge[i] = rhs._knowledge[i]->clone();			
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *src)
{
	std::cout << "Learning Materia..." << std::endl;
	if (src == nullptr)
	{
		std::cout << "Invalid materia passed" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_knowledge[i] == nullptr)
		{
			std::cout << "Adding " << src->getType() << " to index " << i << std::endl;
			this->_knowledge[i] = src->clone();
			delete src;
			return ;
		}
	}
	std::cout << "Source is full and cannot learn new Materias" << std::endl;
	delete src;
	return ;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_knowledge[i] && this->_knowledge[i]->getType() == type)
		{
			std::cout << "Creating '" << type << "' " << std::endl; 
			return (this->_knowledge[i]->clone());
		}
	}
	std::cout << "Type '" << type <<"' not found, returning a nullptr" << std::endl;
	return nullptr;
}

// void MateriaSource::print_knowledge()
// {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (this->_knowledge[i])
// 			std::cout << i << ": " << this->_knowledge[i]->getType() << std::endl;
// 		else
// 			std::cout << i << ": nullptr" << std::endl;
// 	}
// }
