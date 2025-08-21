/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:37:17 by emgul            #+#    #+#              */
/*   Updated: 2025/08/20 14:25:35 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src._target)
{
	*this = src;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	this->_target = src._target;
	setIsSigned(src.getIsSigned());
	return (*this);
}

void ShrubberyCreationForm::action() const
{
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());
	if (!file)
		throw ShrubberyCreationFailed();

	file << "              _{\\ _{\\{\\//}/}/}__" << std::endl;
	file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file << "          (_){/{\\//}{\\{\\/}/}{\\{\\)}/}/}(_)" << std::endl;
	file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
	file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file << "              (_)  \\.-'.-/" << std::endl;
	file << "          __...--- |'-.-'| --...__" << std::endl;
	file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
	file << " -\"    ' .  . '    |.'-._| '  . .  '   " << std::endl;
	file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	file << "          ' ..     |'-_.-|" << std::endl;
	file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	file << "              .'   |'- .-|   '." << std::endl;
	file << "  ..-'   ' .  '.   `-._.-'   .'  '  - ." << std::endl;
	file << "   .-' '        '-._______.-'     '  ." << std::endl;
	file << "        .      ~," << std::endl;
	file << "    .       .   |\\   .    ' '-." << std::endl;

	file.close();
	std::cout << "Shrubbery created for " << this->_target << "!" << std::endl;
}

const char *ShrubberyCreationForm::ShrubberyCreationFailed::what() const throw()
{
	return ("Shrubbery creation failed!");
}