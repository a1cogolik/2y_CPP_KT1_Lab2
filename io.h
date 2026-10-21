#ifndef LAB2_IO_IO_H_
#define LAB2_IO_IO_H_

#include <string>
#include <vector>

namespace lab2 {

// Читает целое число с защитой от некорректного ввода
int ReadInt(const std::string& prompt);

// Читает строку чисел через пробел. Возвращает false, если есть нечисловой
// мусор.
bool ReadInts(std::vector<int>& out);

// Читает строку и проверяет, что все слова состоят только из английских
// букв
bool ReadEnglishWords(std::vector<std::string>& out);

// Ожидание нажатия Enter
void Pause();

}  // namespace lab2

#endif  // LAB2_IO_IO_H_