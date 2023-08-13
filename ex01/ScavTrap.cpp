/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:21:10 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/12 22:21:10 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default Constructor called of ScavTrap" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap & copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of ScavTrap" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_energy = 50;
	_damage = 20;
	_gateKeeperActive = false;
	std::cout << "Named Constructor called of ScavTrap" << std::endl;
}
ScavTrap::ScavTrap(std::string name, int hp, int energy, int damage) \
	: ClapTrap(name, hp, energy, damage)
{
	std::cout << "Fields Constructor called of ScavTrap" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() 
{
	std::cout << "Destructor called of ScavTrap" << std::endl;
}

// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	_name = assign._name;
	_hp = assign._hp;
	_energy = assign._energy;
	_damage = assign._damage;
	_gateKeeperActive = assign._gateKeeperActive;
	std::cout << "Copy Assignment Constructor called of ScavTrap" << std::endl;
	return *this;
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->hasHp() && this->hasEnergy())
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " \
					<< this->getDamage() << " point(s) of damage!" << std::endl;
		this->burnEnergy(1);
	}
	else
	{
		std::cout << "Can't do anything! :(" << std::endl;
	}
}

// Special capacity
void	ScavTrap::guardGate()
{
	if (this->hasHp() && this->hasEnergy())
	{
		this->_gateKeeperActive = true;
		this->burnEnergy(1);
		std::cout << "ScavTrap " << this->getName() \
				<< ": Gate keeper mode activated!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() \
				<< " can't activate Gate Keeper mode. Dead battery!" << std::endl;
	}
}
