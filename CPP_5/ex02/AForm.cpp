#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(std::string name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form: Not signed";
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    if (_isSigned)
        throw std::runtime_error("Form: is already signed");
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}
