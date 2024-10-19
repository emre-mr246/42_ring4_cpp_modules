/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:26:26 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 00:40:25 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        void	setName(std::string name);
		void    announce( void );
    private:
        std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
