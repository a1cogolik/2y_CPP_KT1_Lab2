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
  std::vector<int> input;
  while (true) {
    std::cout << "Введите четное количество целых чисел через пробел:\n";
    if (ReadInts(input) && !input.empty() && input.size() % 2 == 0) break;
    std::cout << "[Ошибка] Нужно четное количество целых чисел. Попробуйте "
                 "снова.\n\n";
  }

  std::deque<int> D(input.begin(), input.end());
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
  std::vector<int> inputD;
  while (true) {
    std::cout << "Введите элементы дека D (не менее 5 чисел):\n";
    if (ReadInts(inputD) && inputD.size() >= 5) break;
    std::cout << "[Ошибка] Нужно ввести не менее 5 целых чисел.\n\n";
  }
  std::deque<int> D(inputD.begin(), inputD.end());

  std::vector<int> inputL;
  while (true) {
    std::cout << "Введите элементы списка L (не менее 5 чисел):\n";
    if (ReadInts(inputL) && inputL.size() >= 5) break;
    std::cout << "[Ошибка] Нужно ввести не менее 5 целых чисел.\n\n";
  }
  std::list<int> L(inputL.begin(), inputL.end());

  auto it = std::prev(L.end(), 5);
  L.insert(it, D.rbegin(), D.rbegin() + 5);

  std::cout << "Результат (список L): ";
  std::copy(L.begin(), L.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

void RunTask03_3() {
  std::vector<int> inputL;
  while (true) {
    std::cout << "Введите элементы списка L (нечетное количество чисел):\n";
    if (ReadInts(inputL) && !inputL.empty() && inputL.size() % 2 != 0) break;
    std::cout << "[Ошибка] Нужно нечетное количество целых чисел.\n\n";
  }
  std::list<int> L(inputL.begin(), inputL.end());

  std::vector<int> inputV;
  while (true) {
    std::cout << "Введите элементы вектора V (целые числа):\n";
    if (ReadInts(inputV)) break;
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n\n";
  }
  std::vector<int> V(inputV.begin(), inputV.end());

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
  std::vector<int> inputL;
  while (true) {
    std::cout << "Введите элементы списка L (целые числа):\n";
    if (ReadInts(inputL)) break;
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n\n";
  }
  std::list<int> L(inputL.begin(), inputL.end());

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
  std::vector<int> inputL;
  while (true) {
    std::cout << "Введите элементы списка L (четное количество чисел):\n";
    if (ReadInts(inputL) && !inputL.empty() && inputL.size() % 2 == 0) break;
    std::cout << "[Ошибка] Нужно четное количество целых чисел.\n\n";
  }
  std::list<int> L(inputL.begin(), inputL.end());

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
  std::vector<std::string> words;
  while (true) {
    std::cout << "Введите английские слова через пробел:\n";
    if (ReadEnglishWords(words) && !words.empty()) break;
    std::cout << "[Ошибка] Используйте только английские буквы (A-Z, a-z).\n\n";
  }
  std::deque<std::string> D(words.begin(), words.end());

  std::sort(D.begin(), D.end());
  std::cout << "\nПосле сортировки по алфавиту (std::sort):\n";
  for (const auto& w : D) std::cout << w << "\n";

  std::stable_sort(D.begin(), D.end(),
                   [](const std::string& a, const std::string& b) {
                     return a.length() < b.length();
                   });

  std::cout << "\nПосле стабильной сортировки по длине (std::stable_sort):\n";
  for (const auto& w : D) std::cout << w << "\n";
}

void RunTask08_2() {
  std::vector<std::string> words;
  while (true) {
    std::cout << "Введите английские слова через пробел (не менее 2 слов):\n";
    if (ReadEnglishWords(words) && words.size() >= 2) break;
    std::cout
        << "[Ошибка] Нужно минимум 2 английских слова (только A-Z, a-z).\n\n";
  }
  std::list<std::string> L(words.begin(), words.end());
  std::deque<std::string> D;

  std::adjacent_difference(
      L.begin(), L.end(), std::back_inserter(D),
      [](const std::string& current_word, const std::string& prev_word) {
        return std::string(1, prev_word[0]) + current_word.back();
      });
  D.erase(D.begin());

  std::cout << "Результат (дек D):\n";
  for (const auto& str : D) std::cout << str << " ";
  std::cout << "\n";
}

void RunTask09_1() {
  std::vector<int> inputV0;
  while (true) {
    std::cout << "Введите элементы вектора V0 (эталон, целые числа):\n";
    if (ReadInts(inputV0)) break;
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n\n";
  }
  std::set<int> setV0(inputV0.begin(), inputV0.end());

  int n = 0;
  while (true) {
    n = ReadInt("Введите количество векторов N (> 0): ");
    if (n > 0) break;
    std::cout << "[Ошибка] N должно быть больше нуля.\n";
  }

  int count = 0;
  for (int i = 1; i <= n; ++i) {
    std::vector<int> inputVi;
    while (true) {
      std::cout << "Введите элементы вектора V" << i << ":\n";
      if (ReadInts(inputVi)) break;
      std::cout << "[Ошибка] В строке есть нечисловые символы.\n\n";
    }
    std::set<int> setVi(inputVi.begin(), inputVi.end());

    if (std::includes(setVi.begin(), setVi.end(), setV0.begin(), setV0.end())) {
      ++count;
    }
  }

  std::cout << "\nКоличество векторов, содержащих все элементы V0: " << count
            << "\n";
}

void RunTask10_1() {
  std::vector<int> V;
  while (true) {
    std::cout << "Введите элементы вектора V (целые числа):\n";
    if (ReadInts(V)) break;
    std::cout << "[Ошибка] В строке есть нечисловые символы.\n\n";
  }

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