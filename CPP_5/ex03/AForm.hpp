#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iomanip>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(std::string name, int signGrade, int executeGrade);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class NotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    virtual int getExecuteGrade() const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif