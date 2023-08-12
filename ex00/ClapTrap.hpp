/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:21:05 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/12 12:21:05 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_damage;

	public:
		// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap & copy);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hp, int energy, int damage);
		
		// Destructor
		~ClapTrap();
		
		// Operators
		ClapTrap & operator=(const ClapTrap &assign);
		
		// Getters / Setters
		std::string	getName() const;
		int			getHp() const;
		int			getEnergy() const;
		int			getDamage() const;
		void		burnEnergy(unsigned int amount);

		// Public member functions
		bool	hasHp() const;
		bool	hasEnergy() const;
		void	attack(const std::string & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &object);

#endif