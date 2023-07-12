#include "Harl.hpp"


void	Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}

void	Harl::debug()
{

	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	return;
}

void	Harl::error()
{

	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return;
}

void	Harl::complain(std::string level)
{
	switch (level_lut[level])
	{
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
			std::cout << std::endl;
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
			std::cout << std::endl;
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
			std::cout << std::endl;
		case 4:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

Harl::Harl()
{
	this->level_lut.insert(std::make_pair("DEBUG", 1));
	this->level_lut.insert(std::make_pair("INFO", 2));
	this->level_lut.insert(std::make_pair("WARNING", 3));
	this->level_lut.insert(std::make_pair("ERROR", 4));

}

Harl::~Harl()
{

}