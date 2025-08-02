/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:26 by emgul             #+#    #+#             */
/*   Updated: 2025/07/28 12:44:13 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#pragma once

#include <iostream>

class Data
{
	public:
        Data(void);
        ~Data();
        Data(const Data &src);
        Data &operator=(const Data &src);
        
        std::string intraLogin;
        std::string moduleName;
        int grade;
};

#endif
