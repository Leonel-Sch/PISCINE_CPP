#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form taxForm("Tax Form", 45, 30);

        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);

        john.incrementGrade(); //  grade 49
        john.incrementGrade(); //  grade 48
        john.incrementGrade(); //  grade 47
        john.incrementGrade(); //  grade 46
        john.incrementGrade(); //  grade 45

        john.signForm(taxForm);

        std::cout << taxForm << std::endl;

        john.signForm(taxForm);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}