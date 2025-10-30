#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    if (_isSigned)
        throw std::runtime_error("Form: is already signed");
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}
