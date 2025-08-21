/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:52:28 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:36 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

std::string extractFileName(const std::string &fullFileName)
{
	std::size_t dotPosition = fullFileName.find_last_of('.');

	if (dotPosition == std::string::npos)
	{
		return (fullFileName);
	}
	return (fullFileName.substr(0, dotPosition));
}

void processLines(std::ifstream &file, std::string s1, std::string s2,
                  std::ofstream &outfile)
{
	std::string line;
	size_t ptr;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		ptr = line.find(s1);
		while (ptr != std::string::npos)
		{
			line.erase(ptr, s1.length());
			line.insert(ptr, s2);
			ptr = line.find(s1, ptr + s2.length());
		}
		if (!firstLine)
			outfile << std::endl;
		outfile << line;
		firstLine = false;
	}
}

int replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file;
	std::ofstream outfile;
	std::string outfileName;

	file.open(filename.c_str());
	outfileName = extractFileName(filename);
	outfile.open((outfileName + ".replace").c_str());
	if (!file.is_open() || !outfile.is_open())
	{
		std::cerr << "Error opening files!" << std::endl;
		return (-1);
	}
	processLines(file, s1, s2, outfile);
	file.close();
	outfile.close();
	return (1);
}
