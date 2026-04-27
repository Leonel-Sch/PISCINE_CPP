#include "BitcoinExchange.hpp"

BitcoinExchange ::BitcoinExchange() {}

BitcoinExchange ::BitcoinExchange(const std::string& dbPath) {
  loadDatabase(dbPath);
}

BitcoinExchange ::BitcoinExchange(const BitcoinExchange& other) {
  _data = other._data;
}

BitcoinExchange& BitcoinExchange ::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    _data = other._data;
  }
  return *this;
}

BitcoinExchange ::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const {

  if (date.empty())
    return false;

  if (date.size() != 10)
    return false;

  if (date[4] != '-' && date[7] != '-')
    return false;

  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7)
      i++;
    if (!(isdigit(date[i])))
      return false;
  }

  bool bissextile = false;
  int year  = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day   = std::atoi(date.substr(8, 2).c_str());

  if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
        return false;

  if (year %4 == 0) {
    bissextile = true;
    if (year % 100 == 0 && year % 400 != 0)
      bissextile = false;
  }

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;

  if (month == 2) {
        if (bissextile && day > 29)
            return false;
        if (!bissextile && day > 28)
            return false;
  }

  return true;
}

bool BitcoinExchange::isValidValue(const std::string& value, float& val) const {
  if (value.empty()) {
        std::cerr << "Error: bad input => " << value << std::endl;
        return false;
    }

    char* endptr;
    double temp = std::strtod(value.c_str(), &endptr);

    if (*endptr != '\0' && *endptr != '\n' && *endptr != '\r') {
        std::cerr << "Error: bad input => " << value << std::endl << std::flush;
        return false;
    }

    if (temp < 0) {
        std::cerr << "Error: not a positive number." << std::endl << std::flush;
        return false;
    }

    if (temp > 1000.0) {
        std::cerr << "Error: too large a number." << std::endl << std::flush;
        return false;
    }

    val = static_cast<float>(temp);
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& dbPath) {
  std::ifstream file(dbPath.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: cannot open file");
  }

  std::string line;
  std::getline(file, line);

  size_t pos;

  while (std::getline(file, line)) {
    pos = line.find(',');
    if (pos != std::string::npos) {
      std::string date = line.substr(0, pos);
      float value = static_cast<float>(std::atof(line.substr(pos + 1).c_str()));
      _data[date] = value;
    }
  }
  file.close();
}

void BitcoinExchange::processInput(const std::string& inputPath) {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: cannot open file");
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        size_t delim = line.find('|');
        if (delim == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateStr = line.substr(0, delim);
        std::string valStr = line.substr(delim + 1);

        dateStr.erase(dateStr.find_last_not_of(" \t") + 1);
        dateStr.erase(0, dateStr.find_first_not_of(" \t"));
        
        valStr.erase(valStr.find_last_not_of(" \t") + 1);
        valStr.erase(0, valStr.find_first_not_of(" \t"));

        if (!isValidDate(dateStr)) {
            if (dateStr.empty()) {
              std::cerr << "Error: empty or full of space" << std::endl << std::flush;
              continue;
            }
            std::cerr << "Error: bad input => " << dateStr << std::endl << std::flush;
            continue;
        }

        float value;
        if (!isValidValue(valStr, value)) {
            continue;
        }

        std::map<std::string, float>::const_iterator it = _data.lower_bound(dateStr);

        if (it == _data.end() || it->first != dateStr) {
            if (it == _data.begin()) {
                std::cerr << "Error: Date is too early, no data available." << std::endl << std::flush;
                continue;
            }
            --it;
        }
        std::cout << dateStr << " => " << value << " = " << (value * it->second) << std::endl << std::flush;
    }
    
    file.close();
}