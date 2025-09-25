#include <iostream>
#include <string> 
#include <vector> 

using namespace std;

/**
 * @brief переставляет символы строки согласно индексам
 * Функция задает новую строку, в которой каждый символ исходной строки 
 * размещается на позиции, указанной в соответствующем элементе
 * массива индексов
 */
string rearString(const string& str, const vector<int>& idx){
    //получаем длинну исходной строки 
    int n = str.length();
    //создаем результирующую строку той же длины, заполненную пробелами
    string result(n, ' ');

    //проходии по каждому символу исх строки 
    for (int i = 0; i < n; i++){
        //помещаем символ str[i] на позицию idx[i]в результирующей строке
        result[idx[i]] = str[i];
    }
    return result;
}

/**
 * @brief демонстрация функции rearString
 */
void demonstrate(const string& str, const vector<int>& idx){
    //выводим исходную стркоу 
    cout << "Исходная строка: \"" << str << "\"" << endl;

    //выводим массив индексов 
    cout << "Массив индексов: ";
    for (int i : idx) {
        cout << i << " ";
    }
    cout << endl;

    //вызываем функцию перестановки и получаем рез
    string result = rearString(str, idx);
    //выводим полученную строку
    cout << "Результат:     \"" << result << "\"" << endl;

    //ну и добавим разделитель между примерами для лучшей читаемости
    cout << "---" << endl;
}


/**
 * @brief Основная функция программы
 */
int main() {
    //заголовок дем-ии
    cout << "Демонстрация работы программы:" << endl;
    cout << "=============================" << endl << endl;

    //пример 1: короткая строка
    demonstrate("abc", {2, 0, 1});

    //пример 2: реверс строки 
     demonstrate("hello", {4, 3, 2, 1, 0});
     
     //пример 3: рандомная перестановка
     demonstrate("program", {2, 5, 0, 6, 1, 4, 3});

     return 0;
}
//g++ -o program HW00.cpp
//./program