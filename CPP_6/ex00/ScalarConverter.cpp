#include "ScalarConverter.hpp"

typedef void (*convertFunc)(const std::string&);

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}


void convertChar(const std::string& literal);
void convertInt(const std::string& literal);
void convertFloat(const std::string& literal);
void convertDouble(const std::string& literal);
void convertHardcoded(const std::string& literal);
void convertInvalid(const std::string& literal);

void printing (char charValue, int intValue, float floatValue, double doubleValue, bool flag)
{
    std::cout << "-------------------------------------------" << std::endl;
    if (std::isprint(charValue))
        std::cout << "char: '" << charValue << "'" << std::endl;
    else if (flag)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    
    if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min() || doubleValue != doubleValue)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << intValue << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    if (doubleValue == std::numeric_limits<double>::infinity())
        std::cout << std::showpos;
    std::cout << "float: " << floatValue << "f" << std::endl;
    std::cout << "double: " << doubleValue << std::endl;
    std::cout << std::noshowpos;
    std::cout << "-------------------------------------------" << std::endl;
}

void convertChar(const std::string& literal)
{
    bool flag = false;
    if (!std::isprint(literal[0]))
        flag = true;
    char charValue = literal[0];
    int intValue = static_cast<int>(charValue);
    float floatValue = static_cast<float>(charValue);
    double doubleValue = static_cast<double>(charValue);
    printing(charValue, intValue, floatValue, doubleValue, flag);
}

void convertInt(const std::string& literal)
{
    bool flag = false;
    errno = 0;
    double d = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE)
    {
        convertInvalid(literal);
        return;
    }
    else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
    {
        convertDouble(literal);
        return;
    }
    if (d >= 0 && (d <= 31 || d == 127)) 
        flag = true;
    int intValue = static_cast<int>(d);
    char charValue = static_cast<char>(intValue);
    float floatValue = static_cast<float>(intValue);
    double doubleValue = static_cast<double>(intValue);
    printing(charValue, intValue, floatValue, doubleValue, flag);
}

void convertFloat(const std::string& literal)
{
    bool flag = false;
    errno = 0;
    double d = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE)
    {
        convertInvalid(literal);
        return;
    }
    if (d >= 0 && (d <= 31 || d == 127)) 
        flag = true;
    float floatValue = static_cast<float>(d);
    char charValue = static_cast<char>(floatValue);
    int intValue = static_cast<int>(floatValue);
    double doubleValue = static_cast<double>(floatValue);
    printing(charValue, intValue, floatValue, doubleValue, flag);
}

void convertDouble(const std::string& literal)
{
    bool flag = false;
    errno = 0;
    double d = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE)
    {
        convertInvalid(literal);
        return;
    }
    if (d >= 0 && (d <= 31 || d == 127)) 
        flag = true;
    double doubleValue = d;
    char charValue = static_cast<char>(doubleValue);
    int intValue = static_cast<int>(doubleValue);
    float floatValue = static_cast<float>(doubleValue);
    printing(charValue, intValue, floatValue, doubleValue,flag);
}

void convertHardcoded(const std::string& literal)
{
    if (literal == "+inff" || literal == "nanf" || literal == "-inff")
        convertFloat(literal);
    else if (literal == "+inf" || literal == "-inf" || literal == "nan")
        convertDouble(literal);
}
void convertInvalid(const std::string& literal)
{
    literal.empty();
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}


void ScalarConverter::convert(const std::string& literal)
{
    int type = init;
    if (literal.empty())
        type = invalid;
    else if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
        type = hardcoded;
    else if (literal.length() == 1 && !std::isdigit(literal[0]))
        type = chara;
    else if (literal.find('.') != std::string::npos)
    {
        size_t count = 0;

        for (size_t i = 0; i < literal.length(); ++i) {
            if (literal[i] == '.') {
                count++;
                }
        }
        if (count > 1) {
            type = invalid;
        }
        else if (literal[literal.length() - 1] == 'f')
        {
            count = 0;

            for (size_t i = 0; i < literal.length(); ++i) {
                if (literal[i] == 'f') {
                    count++;
                    }
            }
            if (count > 1) {
                type = invalid;
            }
            type = floating;
        }
        else
        {
            type = doubl;
        }
    }
    else 
    {
    for (size_t i = 0; i < literal.length(); ++i)
    {
        if (!std::isdigit(literal[i]) && !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
            type = invalid;
    }
    if (type != invalid)
        type = integer;
    }
    if (type == init)
        type = invalid;
    convertFunc convertFunctions[] = {convertChar, convertInt, convertFloat, convertDouble, convertHardcoded, convertInvalid};
    convertFunctions[type](literal);
    return;
}


