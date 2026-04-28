#include "Intern.hpp"

static AForm* createShrubbery(const std::string &target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string &target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string &target) { return new PresidentialPardonForm(target); }

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[3])(const std::string &target) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}