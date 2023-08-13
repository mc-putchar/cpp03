/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 20:30:01 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/13 20:30:01 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
	public:
		// Constructors
		FragTrap();
		FragTrap(const FragTrap & copy);
		FragTrap(std::string name);
		FragTrap(std::string name, int hp, int energy, int damage);
		
		// Destructor
		~FragTrap();
		
		// Operators
		FragTrap & operator=(const FragTrap &assign);

		// Special capacity
		void	attack(std::string const & target);
		void	highFivesGuys(void);
};

#endif
