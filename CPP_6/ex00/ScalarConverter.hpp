#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <cerrno>

typedef enum e_type
{
    chara,
    integer,
    floating,
    doubl,
    hardcoded,
    invalid,
    init
}   t_type;

class ScalarConverter
{
public:
    static void convert(const std::string& literal);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
};






#endif