#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Bureaucrat emre("Emre", 1);
    Intern intern;

    try
    {
        AForm *form = intern.makeForm("robotomy request", "Emre");
        form->beSigned(emre);
        form->executeForm(emre);
        delete form;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
