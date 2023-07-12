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
	if (level_lut[level])
		((this->*complain_funcs[level_lut[level]]))();
}

Harl::Harl()
{
	this->level_lut.insert(std::make_pair("DEBUG", 1));
	this->level_lut.insert(std::make_pair("INFO", 2));
	this->level_lut.insert(std::make_pair("WARNING", 3));
	this->level_lut.insert(std::make_pair("ERROR", 4));

	this->complain_funcs[0] = NULL;
	this->complain_funcs[1] = &Harl::debug;
	this->complain_funcs[2] = &Harl::info;
	this->complain_funcs[3] = &Harl::warning;
	this->complain_funcs[4] = &Harl::error;
}

Harl::~Harl()
{

}