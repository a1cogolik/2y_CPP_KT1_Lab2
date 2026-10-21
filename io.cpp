#include "io.h"

#include <iostream>
#include <limits>
#include <sstream>

namespace lab2 {

int ReadInt(const std::string& prompt) {
  int value = 0;
  std::cout << prompt;
  while (!(std::cin >> value)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка. Введите целое число: ";
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return value;
}

bool ReadInts(std::vector<int>& out) {
  out.clear();
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);
  int value = 0;
  while (iss >> value) {
    out.push_back(value);
  }
  return iss.eof();  // true, только если дошли до конца без ошибок
}

bool ReadEnglishWords(std::vector<std::string>& out) {
  out.clear();
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);
  std::string word;

  while (iss >> word) {
    for (char c : word) {
      // Проверяем, что символ находится в диапазоне английских букв
      if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
        return false;
      }
    }
    out.push_back(word);
  }
  return true;
}

void Pause() {
  std::cout << "\nНажмите Enter для продолжения..." << std::flush;
  std::string temp;
  std::getline(std::cin, temp);
}

}  // namespace lab2