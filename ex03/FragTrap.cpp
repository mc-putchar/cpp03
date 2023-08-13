/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:30:04 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/13 20:30:04 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default Constructor called of FragTrap" << std::endl;
}
FragTrap::FragTrap(const FragTrap & copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of FragTrap" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "Named Constructor called of FragTrap" << std::endl;
}
FragTrap::FragTrap(std::string name, int hp, int energy, int damage) \
	: ClapTrap(name, hp, energy, damage)
{
	std::cout << "Fields Constructor called of FragTrap" << std::endl;
}

// Destructor
FragTrap::~FragTrap() 
{
	std::cout << "Destructor called of FragTrap" << std::endl;
}

// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	_name = assign._name;
	_hp = assign._hp;
	_energy = assign._energy;
	_damage = assign._damage;
	std::cout << "Copy Assignment Constructor called of FragTrap" << std::endl;
	return *this;
}

// Functions
void FragTrap::attack(std::string const & target)
{
	if (this->hasHp() && this->hasEnergy())
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " \
					<< this->getDamage() << " point(s) of damage!" << std::endl;
		this->burnEnergy(1);
	}
	else
	{
		std::cout << "Can't do anything! :(" << std::endl;
	}
}

void FragTrap::highFivesGuys(void)
{
	if (this->hasHp() && this->hasEnergy())
	{
		this->burnEnergy(1);
		std::cout << "FragTrap " << this->getName() \
				<< ": High fives everyone! Show 'em up high!!!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->getName() \
				<< " can't high 5! Dead battery!" << std::endl;
	}
}
