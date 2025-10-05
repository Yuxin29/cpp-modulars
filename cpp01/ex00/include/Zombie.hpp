/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuwu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:49:45 by yuwu              #+#    #+#             */
/*   Updated: 2025/10/05 16:49:48 by yuwu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

// You have to determine in what case it’s better to allocate the zombies on the stack or heap.
// Zombies must be destroyed when you don’t need them anymore. 
// The destructor must print a message with the name of the zombie for debugging purposes.
class Zombie
{
private:
    std::string name;
    
public:
    Zombie(std::string name);	//constructer funcion
	~Zombie();			        //deconstructer

    void announce(void);
    Zombie* newZombie( std::string name ); // It creates a zombie, name it, and return it so you can use it outside of the functionscope.
    void randomChump( std::string name );   //It creates a zombie, name it, and the zombie announces itself.
}

// class Account 
// {
// public:

// 	typedef Account		t;

// 	static int	getNbAccounts( void );  //totoal number of accounts
// 	static int	getTotalAmount( void );
// 	static int	getNbDeposits( void );
// 	static int	getNbWithdrawals( void );
// 	static void	displayAccountsInfos( void );

// 	Account( int initial_deposit );	//constructer funcion
// 	~Account( void );				//deconstructer function: print exit status and informations

// 	void	makeDeposit( int deposit );
// 	bool	makeWithdrawal( int withdrawal );
// 	int		checkAmount( void ) const;
// 	void	displayStatus( void ) const;

// private:

// 	//information of all accounts: class level
// 	static int	_nbAccounts;
// 	static int	_totalAmount;
// 	static int	_totalNbDeposits;
// 	static int	_totalNbWithdrawals;

// 	//class level 
// 	static void	_displayTimestamp( void );

// 	//informaiton of one accoutn: object level
// 	int				_accountIndex;
// 	int				_amount;
// 	int				_nbDeposits;
// 	int				_nbWithdrawals;

// 	Account( void );
// };


#endif
