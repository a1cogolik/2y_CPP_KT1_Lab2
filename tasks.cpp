#include "tasks.h"

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "io.h"

namespace lab2 {

void RunTask01_4() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите четное количество целых чисел через пробел:\n";
    std::getline(std::cin, line);
    iss.str(line);
    iss.clear();

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0 && count % 2 == 0) break;
    std::cout << "[Ошибка] Нужно четное количество целых чисел.\n";
  }

  iss.clear();
  iss.str(line);
  std::deque<int> D{std::istream_iterator<int>(iss),
                    std::istream_iterator<int>()};

  int half_size = D.size() / 2;
  std::cout << "Результат:\n";
  std::cout << "Первая половина (обратно): ";
  std::copy(D.rbegin() + half_size, D.rend(),
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\nВторая половина (обратно): ";
  std::copy(D.rbegin(), D.rbegin() + half_size,
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

void RunTask02_5() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите элементы дека D (не менее 5 чисел):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count >= 5) {
      break;
    }
    std::cout << "[Ошибка] Нужно ввести не менее 5 целых чисел.\n";
  }

  iss.clear();
  iss.str(line);
  std::deque<int> D((std::istream_iterator<int>(iss)),
                    std::istream_iterator<int>());

  while (true) {
    std::cout << "Введите элементы списка L (не менее 5 чисел):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count >= 5) {
      break;
    }
    std::cout << "[Ошибка] Нужно ввести не менее 5 целых чисел.\n";
  }

  iss.clear();
  iss.str(line);
  std::list<int> L((std::istream_iterator<int>(iss)),
                   std::istream_iterator<int>());

  auto it = std::prev(L.end(), 5);
  L.insert(it, D.rbegin(), D.rbegin() + 5);

  std::cout << "Результат (список L): ";
  std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

void RunTask03_3() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите элементы списка L (нечетное количество чисел):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0 && count % 2 != 0) {
      break;
    }
    std::cout << "[Ошибка] Нужно нечетное количество целых чисел.\n";
  }

  iss.clear();
  iss.str(line);
  std::list<int> L((std::istream_iterator<int>(iss)),
                   std::istream_iterator<int>());

  while (true) {
    std::cout << "Введите элементы вектора V (целые числа):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0) {
      break;
    }
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n";
  }

  iss.clear();
  iss.str(line);
  std::vector<int> V((std::istream_iterator<int>(iss)),
                     std::istream_iterator<int>());

  auto it = L.begin();
  std::advance(it, L.size() / 2);
  V.push_back(*it);
  L.erase(it);

  std::cout << "Результат (список L): ";
  std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\nРезультат (вектор V): ";
  std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

void RunTask04_6() {
  std::string filename;
  std::cout << "Введите имя файла для записи (например, out.txt): ";
  std::getline(std::cin, filename);

  std::ofstream out(filename);
  if (!out) {
    std::cout << "Ошибка: не удалось открыть файл " << filename << "\n";
    return;
  }

  std::cout << "Введите набор символов (например: a b c 1 2):\n";
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  std::transform(std::istream_iterator<char>(iss),
                 std::istream_iterator<char>(),
                 std::ostream_iterator<int>(out, " "),
                 [](char c) { return static_cast<int>(c) * 2; });

  std::cout << "Данные записаны в файл " << filename << "\n";
}

void RunTask05_4() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите элементы списка L (целые числа):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0) {
      break;
    }
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n";
  }

  iss.clear();
  iss.str(line);
  std::list<int> L((std::istream_iterator<int>(iss)),
                   std::istream_iterator<int>());

  auto is_negative = [](int x) { return x < 0; };
  auto first_neg = std::find_if(L.begin(), L.end(), is_negative);

  if (first_neg == L.end()) {
    std::cout << "Список не изменен (нет отрицательных).\n";
  } else {
    auto second_neg = std::find_if(std::next(first_neg), L.end(), is_negative);
    if (second_neg == L.end()) {
      L.erase(std::next(first_neg), L.end());
      std::cout << "Удалены все элементы после единственного отрицательного.\n";
    } else {
      L.erase(std::next(first_neg), second_neg);
      std::cout << "Удалены элементы между первым и вторым отрицательным.\n";
    }
  }

  std::cout << "Результат: ";
  std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

void RunTask06_13() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите элементы списка L (четное количество чисел):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0 && count % 2 == 0) {
      break;
    }
    std::cout << "[Ошибка] Нужно четное количество целых чисел.\n";
  }

  iss.clear();
  iss.str(line);
  std::list<int> L((std::istream_iterator<int>(iss)),
                   std::istream_iterator<int>());

  auto mid = L.begin();
  std::advance(mid, L.size() / 2);

  auto is_not_positive = [](int x) { return x <= 0; };

  std::remove_copy_if(mid, L.end(), std::inserter(L, L.begin()),
                      is_not_positive);

  std::cout << "Результат (список L): ";
  std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

void RunTask07_10() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите английские слова через пробел:\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    std::string word;
    bool valid = true;
    int count = 0;

    while (iss >> word) {
      ++count;
      for (char c : word) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
          valid = false;
          break;
        }
      }
      if (!valid) break;
    }

    if (iss.eof() && valid && count > 0) {
      break;
    }
    std::cout << "[Ошибка] Используйте только английские буквы (A-Z, a-z).\n";
  }

  iss.clear();
  iss.str(line);
  std::deque<std::string> D((std::istream_iterator<std::string>(iss)),
                            std::istream_iterator<std::string>());

  std::sort(D.begin(), D.end());
  std::cout << "\nПосле сортировки по алфавиту (std::sort):\n";
  for (const auto& w : D) {
    std::cout << w << "\n";
  }

  std::stable_sort(D.begin(), D.end(),
                   [](const std::string& a, const std::string& b) {
                     return a.length() < b.length();
                   });
  std::cout << "\nПосле стабильной сортировки по длине (std::stable_sort):\n";
  for (const auto& w : D) {
    std::cout << w << "\n";
  }
}

void RunTask08_2() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите английские слова через пробел (не менее 2 слов):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    std::string word;
    bool valid = true;
    int count = 0;

    while (iss >> word) {
      ++count;
      for (char c : word) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
          valid = false;
          break;
        }
      }
      if (!valid) {
        break;
      }
    }

    if (iss.eof() && valid && count >= 2) {
      break;
    }
    std::cout
        << "[Ошибка] Нужно минимум 2 английских слова (только A-Z, a-z).\n";
  }

  iss.clear();
  iss.str(line);
  std::list<std::string> L((std::istream_iterator<std::string>(iss)),
                           std::istream_iterator<std::string>());

  std::deque<std::string> D;
  std::adjacent_difference(
      L.begin(), L.end(), std::back_inserter(D),
      [](const std::string& current_word, const std::string& prev_word) {
        return std::string(1, prev_word[0]) + current_word.back();
      });
  D.erase(D.begin());

  std::cout << "Результат (дек D):\n";
  for (const auto& str : D) {
    std::cout << str << " ";
  }
  std::cout << "\n";
}

void RunTask09_1() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите элементы вектора V0 (эталон, целые числа):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0) {
      break;
    }
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n";
  }

  iss.clear();
  iss.str(line);
  std::vector<int> V0((std::istream_iterator<int>(iss)),
                      std::istream_iterator<int>());

  std::set<int> setV0(V0.begin(), V0.end());

  int n = 0;
  while (true) {
    n = ReadInt("Введите количество векторов N (> 0): ");
    if (n > 0) {
      break;
    }
    std::cout << "[Ошибка] N должно быть больше нуля.\n";
  }

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    std::string vi_line;
    std::istringstream vi_iss;

    while (true) {
      std::cout << "Введите элементы вектора V" << i << ":\n";
      std::getline(std::cin, vi_line);
      vi_iss.clear();
      vi_iss.str(vi_line);

      int value = 0;
      int vi_count = 0;
      while (vi_iss >> value) {
        ++vi_count;
      }

      if (vi_iss.eof() && vi_count > 0) {
        break;
      }
      std::cout << "[Ошибка] В строке есть нечисловые символы.\n";
    }

    vi_iss.clear();
    vi_iss.str(vi_line);
    std::vector<int> Vi((std::istream_iterator<int>(vi_iss)),
                        std::istream_iterator<int>());

    std::set<int> setVi(Vi.begin(), Vi.end());

    if (std::includes(setVi.begin(), setVi.end(), setV0.begin(), setV0.end())) {
      ++count;
    }
  }

  std::cout << "\nКоличество векторов, содержащих все элементы V0: " << count
            << "\n";
}

void RunTask10_1() {
  std::string line;
  std::istringstream iss;

  while (true) {
    std::cout << "Введите элементы вектора V (целые числа):\n";
    std::getline(std::cin, line);
    iss.clear();
    iss.str(line);

    int value = 0;
    int count = 0;
    while (iss >> value) {
      ++count;
    }

    if (iss.eof() && count > 0) {
      break;
    }
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n";
  }

  iss.clear();
  iss.str(line);
  std::vector<int> V((std::istream_iterator<int>(iss)),
                     std::istream_iterator<int>());

  std::map<int, int> M;

  for (std::vector<int>::const_iterator it = V.begin(); it != V.end(); ++it) {
    ++M[*it];
  }

  std::cout << "Результат (элемент и количество):\n";

  for (std::map<int, int>::const_iterator it = M.begin(); it != M.end(); ++it) {
    std::cout << it->first << " " << it->second << "\n";
  }
}

}  // namespace lab2