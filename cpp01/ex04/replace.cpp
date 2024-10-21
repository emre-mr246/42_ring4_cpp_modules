/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:28 by emgul             #+#    #+#             */
/*   Updated: 2024/10/21 18:10:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>

std::ifstream openFile(std::string filename)
{
	std::ifstream file(filename);
    if (!file.is_open()) 
	{
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(-1);
    }
	return (file);
}

int replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file(filename);
	std::ofstream outfile("result.txt");
	std::string line;
	size_t ptr;
	
	while (std::getline(file, line))
	{
		ptr = line.find(s1);
		if (ptr != std::string::npos)
		{
			line.erase(ptr, s1.length());
			line.insert(ptr, s2);
			outfile << line;
		}
		outfile << std::endl;
	}
}
