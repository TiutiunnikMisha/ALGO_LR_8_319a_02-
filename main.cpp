#include <iostream>  // Підключаємо бібліотеку для вводу/виводу
#include <string>    // Підключаємо бібліотеку для роботи з рядками
#include "array_utils.h" // Підключаємо заголовочний файл для масивів
#include "matrix_utils.h" // Підключаємо заголовочний файл для матриць
using namespace std; // Використовуємо стандартний простір імен

int main() {
    string filename; // Змінна для збереження імені файлу
    int task; // Змінна для вибору завдання

    // Виводимо підказку та зчитуємо номер завдання
    cout << "Enter task number (1 - reverse array, 2 - row sums, 3 - sort characters): ";
    cin >> task;
    cin.ignore(); // Очищуємо буфер вводу

    // В залежності від номера завдання виконуємо відповідну дію
    switch (task) {
    case 1:
        // Завдання 1: реверсування масиву чисел
        cout << "Enter filename for input (array_in_28.txt): ";
        getline(cin, filename); // Зчитуємо ім'я файлу з клавіатури
        reverseArrayFromFile(filename, "array_out_28.txt"); // Викликаємо функцію реверсу
        break;
    case 2:
        // Завдання 2: обчислення сум рядків матриці
        cout << "Enter filename for input (matr_in_28.txt): ";
        getline(cin, filename);
        processMatrixFromFile(filename); // Обробляємо матрицю
        break;
    case 3:
        // Завдання 3: сортування символів методом вибору
        cout << "Enter filename for input (array_in_char_28.txt): ";
        getline(cin, filename);
        sortArrayFromFile(filename, "array_out_char_28.txt"); // Сортуємо символи
        break;
    default:
        // Якщо ввели неправильний номер завдання
        cout << "Wrong task number!" << endl;
    }

    return 0; // Завершення програми
}
