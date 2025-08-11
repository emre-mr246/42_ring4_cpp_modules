/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:36:10 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 00:20:12 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
{
    this->_name = name;
    std::cout << "Zombie \"" << this->_name << "\" created!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie \"" << this->_name << "\" destroyed!" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
