/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:17:39 by mcutura           #+#    #+#             */
/*   Updated: 2023/08/12 12:17:39 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#define CLAPTRAP_COUNT		5
#define NUMBER_OF_ROUNDS	42
#define REPAIR_DIVISOR		6

static inline int	ft_clamp(int x) {return (x < 0 ? CLAPTRAP_COUNT - 1 : x);}

int	main( void )
{
	static std::string const	CLAPTRAP_NAMES[] = {
		"CT_Marvin", "CT_Arthur_Dent", "CT_Trillian",
		"CT_Ford", "CT_Galactic_President_Zaphod_Beeblebrox"
	};
	ClapTrap *ClapTraps = new ClapTrap[CLAPTRAP_COUNT];

	// Use all the constructors
	for (int i = 0; i < CLAPTRAP_COUNT; i++) {
		ClapTraps[i] = ClapTrap(std::string(CLAPTRAP_NAMES[i]));
	}
	
	ScavTrap scavTrap(std::string("ST_Hama_Kavula"));
	FragTrap fragTrap(std::string("FT_Slartiblartfast"));

	DiamondTrap dmdTrap(std::string("DT_Heart_of_Gold"));

	dmdTrap.whoAmI();

	std::cout << "BEGIN FIGHT" << std::endl;
	// Roll the die
	int	rng, target, repair;
	for (int i = 1; i <= NUMBER_OF_ROUNDS; i++) {
		rng = ((i * i * 3 * i) + REPAIR_DIVISOR) % CLAPTRAP_COUNT; // "Random"
		std::cout << "TURN " << i << "  || RNGeesus: " << rng << std::endl;

		if (ClapTraps[rng].hasHp() && ClapTraps[rng].hasEnergy())
		{
			target = i & 1 ? (rng + 1) % CLAPTRAP_COUNT \
						: ft_clamp(rng - 1) % CLAPTRAP_COUNT;
			ClapTraps[rng].attack(ClapTraps[target].getName());
			ClapTraps[target].takeDamage(ClapTraps[rng].getDamage());
		}
		else std::cout << "ClapTrap " << ClapTraps[rng].getName() \
					<< " can't attack - dead battery." << std::endl;

		if (i & 1)
		{
			if (scavTrap.hasHp() && scavTrap.hasEnergy())
			{
				target = (i + i) * i % CLAPTRAP_COUNT;
				scavTrap.attack(ClapTraps[target].getName());
				ClapTraps[target].takeDamage(scavTrap.getDamage());
			}
			else std::cout << "ScavTrap " << scavTrap.getName() \
						<< " has dead battery!" << std::endl;
		}
		else if (i > NUMBER_OF_ROUNDS * 0.6)
		{
			scavTrap.guardGate();
		}

		if (!(i % 3))
		{
			if (fragTrap.hasHp() && fragTrap.hasEnergy())
			{
				target = i % CLAPTRAP_COUNT;
				fragTrap.attack(ClapTraps[target].getName());
				ClapTraps[target].takeDamage(fragTrap.getDamage());
			}
		}
		else if (i > NUMBER_OF_ROUNDS * 0.3)
			fragTrap.highFivesGuys();

		if (i % REPAIR_DIVISOR)
		{
			repair = ((rng + target) << REPAIR_DIVISOR) % CLAPTRAP_COUNT;
			ClapTraps[repair].beRepaired(ClapTraps[repair].getDamage());
		}
		else std::cout << "No repairs done this round." << std::endl;
	}

	delete [] ClapTraps;
	return 0;
}
