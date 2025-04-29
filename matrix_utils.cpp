#include "array_utils.h"
#include <fstream>   // Для роботи з файлами
#include <vector>    // Для використання динамічних масивів
#include <algorithm> // Для функції swap
#include <iostream>

// Функція реверсу масиву дійсних чисел з файлу
void reverseArrayFromFile(const string& inputFilename, const string& outputFilename) {
    ifstream fin(inputFilename); // Відкриваємо файл для читання
    ofstream fout(outputFilename); // Відкриваємо файл для запису
    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    int n;
    fin >> n; // Зчитуємо розмір масиву
    vector<double> arr(n); // Створюємо вектор розміру n
    for (int i = 0; i < n; i++) {
        fin >> arr[i]; // Зчитуємо елементи масиву
    }

    fout << n << endl; // Записуємо кількість елементів у файл
    for (int i = n - 1; i >= 0; i--) {
        fout << arr[i] << " "; // Записуємо елементи у зворотному порядку
    }
    fout << endl; // Перенос рядка

    fin.close(); // Закриваємо вхідний файл
    fout.close(); // Закриваємо вихідний файл
}

// Функція сортування символів за спаданням методом вибору
void sortArrayFromFile(const string& inputFilename, const string& outputFilename) {
    ifstream fin(inputFilename); // Відкриваємо файл для читання
    ofstream fout(outputFilename); // Відкриваємо файл для запису
    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    int n;
    fin >> n; // Зчитуємо розмір масиву
    vector<char> arr(n); // Створюємо масив символів
    for (int i = 0; i < n; i++) {
        fin >> arr[i]; // Зчитуємо символи
    }

    // Реалізація сортування вибором (за спаданням)
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j; // Знаходимо індекс максимуму
            }
        }
        swap(arr[i], arr[maxIdx]); // Міняємо місцями
    }

    fout << n << endl; // Записуємо кількість елементів
    for (char c : arr) {
        fout << c << " "; // Записуємо відсортовані символи
    }
    fout << endl;

    fin.close(); // Закриваємо вхідний файл
    fout.close(); // Закриваємо вихідний файл
}
