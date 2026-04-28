#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 5);
        ShrubberyCreationForm shrubberyForm("Leo");
        RobotomyRequestForm robotomyForm("Alice");
        PresidentialPardonForm pardonForm("Charlie");

        bob.signForm(shrubberyForm);
        bob.executeForm(shrubberyForm);

        bob.signForm(robotomyForm);
        bob.executeForm(robotomyForm);

        bob.signForm(pardonForm);
        bob.executeForm(pardonForm);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}