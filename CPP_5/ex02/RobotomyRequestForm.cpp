#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("default") {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getIsSigned()) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Bzzzzzz... Vrrrrrr... *drilling noises*" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << target << " failed." << std::endl;
    }
}