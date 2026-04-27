#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string>

class BitcoinExchange {
 private:
  std::map<std::string, float> _data;

  bool isValidDate(const std::string& date) const;
  bool isValidValue(const std::string& value, float& val) const;
  void loadDatabase(const std::string& dbPath);

 public:
  BitcoinExchange();
  BitcoinExchange(const std::string& dbPath);
  BitcoinExchange(const BitcoinExchange& other);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  void processInput(const std::string& inputPath);
};

#endif