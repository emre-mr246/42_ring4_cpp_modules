/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:42:21 by emgul             #+#    #+#             */
/*   Updated: 2024/10/20 01:04:25 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Address Info:" << std::endl;

    std::cout << "Address of the string:        " << &string << std::endl;
    std::cout << "Address held by stringPTR:    " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:    " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "String Value:" << std::endl;
    std::cout << "Value of the string:           " << string << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return (0);
}
