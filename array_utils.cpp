#include "matrix_utils.h"
#include <fstream>  // Для роботи з файлами
#include <vector>   // Для використання динамічних масивів
#include <iostream>

// Функція для зчитування матриці з файлу і обчислення сум рядків
void processMatrixFromFile(const string& filename) {
    ifstream fin(filename); // Відкриваємо файл для читання
    ofstream fout(filename, ios::app); // Відкриваємо файл для дописування
    if (!fin.is_open() || !fout.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    int m, n;
    fin >> m >> n; // Зчитуємо кількість рядків і стовпців
    vector<vector<double>> matrix(m, vector<double>(n)); // Створюємо матрицю

    // Зчитуємо елементи матриці
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }

    fout << "\nRow sums:" << endl; // Заголовок для виводу сум
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j]; // Обчислюємо суму елементів рядка
        }
        fout << "Row " << i + 1 << ": " << sum << endl; // Записуємо суму
    }

    fin.close(); // Закриваємо вхідний файл
    fout.close(); // Закриваємо вихідний файл
}
