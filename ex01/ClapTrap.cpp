/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:20:59 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/12 12:20:59 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	_name = "noname";
	std::cout << "Default Constructor called of ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & copy)
{
	*this = copy;
	std::cout << "Copy Constructor called of ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_hp = 10;
	_energy = 10;
	_damage = 0;
	std::cout << "Named Constructor called of ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int energy, int damage) : \
	_name(name), _hp(hp), _energy(energy), _damage(damage)
{
	std::cout << "Fields Constructor called of ClapTrap" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called of ClapTrap" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap & assign)
{
	_name = assign.getName();
	_hp = assign.getHp();
	_energy = assign.getEnergy();
	_damage = assign.getDamage();
	std::cout << "Copy Assignment Constructor called of ClapTrap" << std::endl;
	return *this;
}


// Getters / Setters
std::string	ClapTrap::getName() const
{
	return _name;
}
int	ClapTrap::getHp() const
{
	return _hp;
}
int	ClapTrap::getEnergy() const
{
	return _energy;
}
int	ClapTrap::getDamage() const
{
	return _damage;
}
void	ClapTrap::burnEnergy(unsigned int amount)
{
	this->_energy -= amount;
}

// Public member functions
bool	ClapTrap::hasHp() const
{
	return (this->getHp() > 0);
}
bool	ClapTrap::hasEnergy() const
{
	return (this->getEnergy() > 0);
}

void	ClapTrap::attack(const std::string & target)
{
	if (this->hasHp() && this->hasEnergy())
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " \
					<< this->getDamage() << " point(s) of damage!" << std::endl;
		this->burnEnergy(1);
	}
	else
	{
		std::cout << "Can't do anything! :(" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->getName() << " took " << amount \
			<< " point(s) of damage! HP: " << this->getHp() << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hasHp() && this->hasEnergy())
	{
		this->_hp += amount;
		this->burnEnergy(1);
		std::cout << "ClapTrap " << this->getName() << " repaired " << amount \
				<< " point(s) of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() \
			<< " can't be repaired! Dead battery or no structural integrity" \
			<< std::endl;
	}
}

// Output operator
std::ostream &operator<<(std::ostream &out, ClapTrap const &object)
{
	out << object.getName();
	return (out);
}
