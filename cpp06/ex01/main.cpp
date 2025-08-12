/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:38:23 by emgul            #+#    #+#              */
/*   Updated: 2025/08/12 19:03:43 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data;
    Data *deserializedData;
    uintptr_t raw;

    data = new Data();
    data->intraLogin = "emgul";
    data->moduleName = "CPP 06";
    data->grade = 100;

    raw = Serializer::serialize(data);
    std::cout << "Serialized data to uintptr_t: " << raw << std::endl;
    deserializedData = Serializer::deserialize(raw);

    std::cout << "Intra Login: " << deserializedData->intraLogin << std::endl;
    std::cout << "Module Name: " << deserializedData->moduleName << std::endl;
    std::cout << "Grade: " << deserializedData->grade << std::endl;

    delete (data);
    return (0);
}
