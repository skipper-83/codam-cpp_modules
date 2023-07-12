#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_nbAccounts;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	return;
}

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	Account::_nbAccounts--;
	return;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << ++this->_nbDeposits;
	std::cout << std::endl;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused";
		std::cout << std::endl;
		return false;
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";nb_withdrawals:" << ++this->_nbWithdrawals;
	Account::_totalNbWithdrawals++;
	std::cout << std::endl;
	return true;
}

void	Account::displayStatus() const
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

int	Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount()
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals () 
{
	return (Account::_totalNbWithdrawals);
}

// int	Account::checkAmount() const;
// {
// 	return(this->_amount);
// }

void	Account::_displayTimestamp()
{
	time_t	ttime = time(NULL);
	tm* cur_time = localtime(&ttime);

	std::cout << "[";
	std::cout << cur_time->tm_year + 1900;
	if (cur_time->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << cur_time->tm_mon + 1;
	if (cur_time->tm_mday < 10)
		std::cout << "0";
	std::cout << cur_time->tm_mday;
	std::cout << "_";
	if (cur_time->tm_hour < 10)
		std::cout << "0";
	std::cout << cur_time->tm_hour;
	if (cur_time->tm_min < 10)
		std::cout << "0";
	std::cout << cur_time->tm_min;
	if (cur_time->tm_sec < 10)
		std::cout << "0";
	std::cout << cur_time->tm_sec;
	std::cout << "]";
}