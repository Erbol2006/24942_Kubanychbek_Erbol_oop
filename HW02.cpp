//Эрбол 24942
//Задание 1:
//создать высшую функцию, одним из параметров которой, 
//является указатель на функцию. Назначение высшей 
//функции - подсчет количества элементов в векторе, 
//удовлетворяющих определённому в callback функции 
//(принимаемой по указателю на функцию) условию.
/*
#include <iostream>
#include <vector>

//высшая функция: принимает вектор и указатель на функцию-предикат
template <typename T>
int count_if(const std::vector<T>& vec, bool (*predicate)(const T&)) {
    int count = 0;
    for (const auto& elem : vec) {
        if (predicate(elem)) {
            ++count;
        }
    }
    return count;
}

//примеры функций-предикатов
bool is_even(const int& x) {
    return x % 2 == 0;
}

bool is_positive(const double& x) {
    return x > 0.0;
}

bool is_long_string(const std::string& s) {
    return s.length() > 5;
}

int main() {
    //пример с int
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Чётных чисел: " << count_if(numbers, is_even) << std::endl; // 5

    //пример с double
    std::vector<double> values = {-2.5, -1.0, 0.0, 1.5, 3.14, -0.5};
    std::cout << "Положительных чисел: " << count_if(values, is_positive) << std::endl; // 2

    //пример со строками
    std::vector<std::string> words = {"cat", "elephant", "dog", "butterfly", "ant"};
    std::cout << "Слов длиннее 5 символов: " << count_if(words, is_long_string) << std::endl; // 2

    return 0;
}
*/
//-------------------------------------------------------------------------------------------
//2 задание 
// 3 задание 
//продемонстрировать работу высшей функции со всеми callback функциями и сравнить результат работы с std::count_if из <algorithm>.

/*
#include <iostream>
#include <vector>

//высшая функция: принимает вектор и указатель на функцию-предикат
template <typename T>
int count_if(const std::vector<T>& vec, bool (*predicate)(const T&)) {
    int count = 0;
    for (const auto& elem : vec) {
        if (predicate(elem)) {
            ++count;
        }
    }
    return count;
}
//1. проверка явл-ся ли число простым 
bool is_prime(const int& x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

//2. проверка начинается ли строка с заглавной буквы
bool starts_with_uppercase(const std::string& s) {
    if (s.empty()) return false;
    return std::isupper(static_cast<unsigned char>(s[0]));
}

//3. Проверка, попадает ли число в заданный диапазон 
bool in_range_10_to_20(const int& x) {
    return x >= 10 && x <= 20;
}

//примеры функций-предикатов
bool is_even(const int& x) {
    return x % 2 == 0;
}

bool is_positive(const double& x) {
    return x > 0.0;
}

bool is_long_string(const std::string& s) {
    return s.length() > 5;
}

int main() {
    //пример с int
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Чётных чисел: " << count_if(numbers, is_even) << std::endl; // 5

    //пример с double
    std::vector<double> values = {-2.5, -1.0, 0.0, 1.5, 3.14, -0.5};
    std::cout << "Положительных чисел: " << count_if(values, is_positive) << std::endl; // 2

    //пример со строками
    std::vector<std::string> words = {"cat", "elephant", "dog", "butterfly", "ant"};
    std::cout << "Слов длиннее 5 символов: " << count_if(words, is_long_string) << std::endl; // 2

    // Пример с простыми числами
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 17, 19, 20};
    std::cout << "Простых чисел: " << count_if(nums, is_prime) << std::endl; // 7

    // Пример со строками, начинающимися с заглавной буквы
    std::vector<std::string> words2 = {"Apple", "banana", "Cherry", "date", "Elderberry"};
    std::cout << "Слов с заглавной буквы: " << count_if(words2, starts_with_uppercase) << std::endl; // 3

    // Пример с числами в диапазоне [10, 20]
    std::vector<int> mixed = {5, 10, 15, 20, 25, 30};
    std::cout << "Чисел от 10 до 20: " << count_if(mixed, in_range_10_to_20) << std::endl; // 3
    return 0;
}
*/
//-----------------------------------------------------------------------
