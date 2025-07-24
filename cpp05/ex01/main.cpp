#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat emre("Emre", 42);

    try
    {
        Form form("Sales Agreement for 42 ID Card Lanyards", 42, 42);
        std::cout << form << std::endl;
        std::cout << emre << std::endl;
        form.beSigned(emre);
        form.executeForm(emre);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
