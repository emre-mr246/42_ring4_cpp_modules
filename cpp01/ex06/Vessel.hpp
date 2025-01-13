/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vessel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:19 by emgul             #+#    #+#             */
/*   Updated: 2025/01/13 10:13:20 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VESSEL_HPP
# define VESSEL_HPP

# include <iostream>

class	Vessel
{
	public:
		Vessel(void);
		~Vessel(void);
		void	complain(std::string level);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
