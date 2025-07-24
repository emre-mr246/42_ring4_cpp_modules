#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat emre("Emre", 2);
    Bureaucrat Meeseeks;

    try
    {
        std::cout << Meeseeks << std::endl;
        std::cout << emre << std::endl;
        emre.incrementGrade();
        emre.decrementGrade();
        emre.incrementGrade();
        std::cout << emre << std::endl;
        emre.incrementGrade();
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
