#include <iostream>

#include "io.h"
#include "tasks.h"

namespace {

void PrintMenu() {
  std::cout << "\n--- Лабораторная работа №2 ---\n";
  std::cout << "1. Задание 1.4\n";
  std::cout << "2. Задание 2.5\n";
  std::cout << "3. Задание 3.3\n";
  std::cout << "4. Задание 4.6\n";
  std::cout << "5. Задание 5.4\n";
  std::cout << "6. Задание 6.13\n";
  std::cout << "7. Задание 7.10\n";
  std::cout << "8. Задание 8.2\n";
  std::cout << "9. Задание 9.1\n";
  std::cout << "10. Задание 10.1\n";
  std::cout << "0. Выход\n";
  std::cout << "Выбор: ";
}

void RunTask(int choice) {
  switch (choice) {
    case 1:
      lab2::RunTask01_4();
      break;
    case 2:
      lab2::RunTask02_5();
      break;
    case 3:
      lab2::RunTask03_3();
      break;
    case 4:
      lab2::RunTask04_6();
      break;
    case 5:
      lab2::RunTask05_4();
      break;
    case 6:
      lab2::RunTask06_13();
      break;
    case 7:
      lab2::RunTask07_10();
      break;
    case 8:
      lab2::RunTask08_2();
      break;
    case 9:
      lab2::RunTask09_1();
      break;
    case 10:
      lab2::RunTask10_1();
      break;
    case 0:
      std::cout << "Выход...\n";
      break;
    default:
      std::cout << "Такого пункта нет.\n";
      break;
  }
}

}  // namespace

int main() {
  setlocale(LC_ALL, "RU");
  while (true) {
    PrintMenu();
    int choice = lab2::ReadInt("");
    if (choice == 0) break;
    RunTask(choice);
    lab2::Pause();
  }
  return 0;
}