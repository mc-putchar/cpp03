/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:20:55 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/12 22:20:55 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	_gateKeeperActive;
	public:
		// Constructors
		ScavTrap();
		ScavTrap(const ScavTrap & copy);
		ScavTrap(std::string name);
		ScavTrap(std::string name, int hp, int energy, int damage);
		
		// Destructor
		~ScavTrap();
		
		// Operators
		ScavTrap & operator=(const ScavTrap &assign);

		// Special capacity
		void	attack(std::string const & target);
		void	guardGate();
};

#endif
