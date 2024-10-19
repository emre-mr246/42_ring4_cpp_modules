/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:33:42 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 00:21:37 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    public:
        Zombie(const std::string &name);
        ~Zombie(void);
		void    announce( void );
    private:
        std::string	_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
