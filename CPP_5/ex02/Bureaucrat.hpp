#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <string>
# include <iomanip>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
public:
    
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    class GradeTooHighException: public std::exception {
		const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
		const char *what() const throw();
	};

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(AForm &form) const;

    void executeForm(AForm const & form) const;

private:
    const std::string _name;
    int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif