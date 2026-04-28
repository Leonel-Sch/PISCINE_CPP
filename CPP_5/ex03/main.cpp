#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat worker("Worker", 140);
        Intern intern;

        AForm* shrub = intern.makeForm("shrubbery creation", "backyard");
        AForm* robo = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Morty");
        AForm* unknown = intern.makeForm("unknown form", "nobody");
        (void)unknown;

        worker.signForm(*shrub);
        boss.signForm(*robo);
        boss.signForm(*pardon);

        worker.executeForm(*shrub);
        boss.executeForm(*shrub);
        boss.executeForm(*robo);
        boss.executeForm(*pardon);

        delete shrub;
        delete robo;
        delete pardon;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}