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

void Pause() {
  std::cout << "\nНажмите Enter для продолжения..." << std::flush;
  std::string temp;
  std::getline(std::cin, temp);
}

}  // namespace lab2