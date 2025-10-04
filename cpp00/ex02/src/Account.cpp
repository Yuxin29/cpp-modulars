/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <yuwu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:11:36 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/04 18:23:52 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>

//private static attibute must be defined outside the class oncce
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//constructor
// example print
// [19920104_091532] index:4;amount:1234;created
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    //time stamp
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

//deconstructore
// example print 
// [19920104_091532] index:3;amount:430;closed
Account::~Account(void)
{
    //time stamp
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

//***********************object level***********************

// [19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
void	Account::makeDeposit(int deposit)
{
    //time stamp
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit" << deposit;
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// [19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
bool	Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        std::cout << "not enough deposit to withdraw." << std::endl;
        return false;
    }
    //time stamp
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal" << withdrawal;
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals -= 1;
    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount(void) const
{
    return _amount;
}

//[19920104_091532] index:1;amount:785;deposits:1;withdrawals:1
void	Account::displayStatus(void) const
{
	//time stap;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawal" << _nbWithdrawals << std::endl;
}

//***********************class level***********************
int	Account::getNbAccounts(void)
{
    return _nbAccounts;
}

 int	Account::getTotalAmount(void)
{
    return _totalAmount;
}

 int	Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

 int	Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
 void	Account::displayAccountsInfos(void)
{   
     //time stamp
    std::cout << "accounts:" << _nbAccounts << "total:" << _totalAmount << "deposits:"<< _totalNbDeposits << "withdrawals:" << _totalNbWithdrawals << std::endl;
}