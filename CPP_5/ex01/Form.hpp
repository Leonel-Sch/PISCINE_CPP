#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iomanip>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
public:
    Form();
    Form(std::string name, int signGrade, int executeGrade);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif