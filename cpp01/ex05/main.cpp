/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:36 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:13:37 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vessel.hpp"

int	main(void)
{
	Vessel ves;

	ves.complain("DEBUG");
	ves.complain("INFO");
	ves.complain("WARNING");
	ves.complain("ERROR");
	return (0);
}
