/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 22:49:49 by emgul             #+#    #+#             */
/*   Updated: 2024/10/10 17:04:31 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->checkAmount();
    std::cout << ";created" << std::endl;
    Account::_nbAccounts++;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->checkAmount();
    std::cout << ";closed" << std::endl;
    Account::_nbAccounts--;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts()
              << ";total:" << Account::getTotalAmount();
    std::cout << ";deposits:" << Account::getNbDeposits()
              << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->checkAmount();
    std::cout << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit << ";amount:" << this->_amount + deposit
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount += deposit;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:";
    if (withdrawal > this->checkAmount())
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->checkAmount() - withdrawal
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    return (true);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void printTwoDigit(int number)
{
    if (number < 10)
    {
        std::cout << "0";
    }
    std::cout << number;
}

void Account::_displayTimestamp(void)
{
    std::time_t curr_time = std::time(NULL);
    std::tm *tm_local = std::localtime(&curr_time);
    std::cout << "[" << (tm_local->tm_year + 1900);
    printTwoDigit(tm_local->tm_mon + 1);
    printTwoDigit(tm_local->tm_mday);
    std::cout << "_";
    printTwoDigit(tm_local->tm_hour);
    printTwoDigit(tm_local->tm_min);
    printTwoDigit(tm_local->tm_sec);
    std::cout << "] ";
}
