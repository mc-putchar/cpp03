/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:57:26 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/13 20:57:26 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "Default Constructor called of DiamondTrap" << std::endl;
}
// DiamondTrap::DiamondTrap(const DiamondTrap & copy) : ClapTrap(copy)
// {
// 	*this = copy;
// 	std::cout << "Copy Constructor called of DiamondTrap" << std::endl;
// }
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_name = name;
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "Named Constructor called of DiamondTrap" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name, int hp, int energy, int damage) \
	: ClapTrap(name, hp, energy, damage)
{
	std::cout << "Fields Constructor called of DiamondTrap" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() 
{
	std::cout << "Destructor called of DiamondTrap" << std::endl;
}

// Operators
DiamondTrap & DiamondTrap::operator=(const DiamondTrap &assign)
{
	_name = assign._name;
	_hp = assign._hp;
	_energy = assign._energy;
	_damage = assign._damage;
	std::cout << "Copy Assignment Constructor called of DiamondTrap" << std::endl;
	return *this;
}

// Special capacity
void DiamondTrap::whoAmI(void)
{
	std::cout << "Who am I? I am " << this->_name \
		<< ". But also deep inside a ClapTrap named: " \
		<< this->ClapTrap::_name << std::endl;
}
