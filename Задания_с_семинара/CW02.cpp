//1 пункт
//(с. 7) Добавить функции печати вектора pv для vector<int> и vector<double>.
/*
#include<iostream>
#include <vector> // добавил
using namespace std; //добавил

void pv(const vector<int>& v);//добавил
void pv(const vector<double>& v); //добавил

int sum(int, int);
int sum(int*, int*);
int sum(const int*, const int*);

int main(){
    int x = 4;
    int y = 6;
    cout << sum(x, y) << endl; // 10

    int* xx = &x;
    int *yy = &y;
    cout << sum(xx, yy) << endl; // Simple pointer 11

    const int* a = &x;
    const int* b = &y;
    cout << sum(a, b) << endl; // Const pointer 110

     //пример испол-я pv
    vector<int> vi = {1, 2, 3, 4, 5};
    vector<double> vd = {1.1, 2.2, 3.3};
    
    cout << "Целочисленный вектор: ";
    pv(vi);

    cout << "Вещественный вектор: ";
    pv(vd);

    return 0; 
}

int sum(int x, int y){
    return x + y;
}

int sum(int* x, int* y){
    cout << "Simple pointer ";
    return *x + *y + 1;
}
int sum(const int* x, const int* y){
    cout << "Const pointer ";
    return *x + *y + 100;
}

//определение функий pv
void pv(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void pv(const vector<double>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}
*/


/*
//____________________________________________________________________________
// 2 задание:
//(с. 9)Изменить функцию печати pv на универсальную с параметрами типа auto.
#include<iostream>

//шаблон для значений
template<typename T> 
T sum(const T& x, const T& y){
    return x + y;
}

//шаблон для указателей 
template<typename T> 
auto sum(const T* x, const T* y) -> decltype(*x + *y){
    std::cout << "Pointer ";
    return *x + *y;
}

int main() {
    int x = 4;
    int y = 6;
    std::cout << sum(x, y) << std::endl; // 10

    int* xx = &x;
    int* yy = &y;
    std::cout << sum(xx, yy) << std::endl; // Pointer 10

    const int* a = &x;
    const int* b = &y;
    std::cout << sum(a, b) << std::endl; // Pointer 10

    return 0;
}
*/
//------------------------------------------------------------
/*
// 3 задание: 
//Сделать функцию печати вектора pv шаблонной.
#include<iostream>
#include <vector> 
#include <string> 

//шаблонная функия суммирования 
template <typename T1, typename T2>
T1 Sum(const T1& x, const T2& y) {
   return (x + y);
}

//ШАблонная фун-я печати вектопа
template <typename T> 
void pv(const std::vector<T>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "J" << std::endl;
}

int main(){
   int x = 4;
   int y = 6;
   double z = 9.5;
   std::cout << "Param int: " << Sum<int>(x, y) << std::endl; // 10
   std::cout << "Two param <int, double>: " << Sum<int, double>(x, z) << std::endl; // 13
   std::cout << "Two param <double, int>: " << Sum<double, int>(z, y) << std::endl; // 15.5
   std::cout << "Param double: " << Sum<double>(z, y) << std::endl; // 15.5
   std::cout << "Param int: " << Sum<int>(z, y) << std::endl; // 15
   std::cout << "Param deduced: " << Sum(x, y) << std::endl; // 10
   std::cout << "Param int and double: " << Sum(x, z) << std::endl; // 13
   std::cout << "Param double and int: " << Sum(z, y) << std::endl; // 15.5
   std::cout << "Param defined: " << Sum<double>(x, z) << std::endl; // 13.5
   std::cout << "Param defined: " << Sum<std::string, std::string>("a", "bcd") << std::endl; // abcd
   // std::cout << "Param defined: " << Sum<std::string, int>("a", x) << std::endl; // Ошибка!

   //тесты pv - печать векторов разных типов 
   std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<double> v2 = {1.1, 2.2, 3.3};
    std::vector<std::string> v3 = {"hello", "world", "!"};

    std::cout << "Vector int: ";
    pv(v1); // [1, 2, 3, 4]

    std::cout << "Vector double: ";
    pv(v2); // [1.1, 2.2, 3.3]

    std::cout << "Vector string: ";
    pv(v3); // [hello, world, !]

    return 0;
}
*/

//----------------------------------------------------------------------
// задание 4: 
//Сделать функцию operat шаблонной.
//Продемонстрировать корректную работу с типом отличным от double (int).
#include <iostream>
#include <cmath>

//функции для double
double sum_d(const double& x, const double& y) { return x + y; }
double power_d(const double& x, const double& y) { return std::pow(x, y); }

//фун-и для int
int sum_i(const int& x, const int& y) { return x + y; }
int multiply_i(const int& x, const int& y) { return x * y; }
int power_i(const int& x, const int& y) { return static_cast<int>(std::pow(x, y)); }

//универсальный multiply (уже есть)
template <typename T>
T multiply(const T& x, const T& y) { return x * y; }

//шаблонная operat
template <typename T>
T operat(T (*f)(const T&, const T&), const T& x, const T& y) {
    return f(x, y);
}

int main() {
    // Работа с double
    double x = 1.2, y = 2.0;
    constexpr int n_d = 3;
    double (*farr_d[n_d])(const double&, const double&) = {sum_d, multiply<double>, power_d};

    std::cout << "=== double operations ===" << std::endl;
    for (int i = 0; i < n_d; ++i) {
        std::cout << operat(farr_d[i], x, y) << std::endl;
    }

    // Работа с int
    int a = 3, b = 4;
    constexpr int n_i = 3;
    int (*farr_i[n_i])(const int&, const int&) = {sum_i, multiply_i, power_i};

    std::cout << "\n=== int operations ===" << std::endl;
    for (int i = 0; i < n_i; ++i) {
        std::cout << operat(farr_i[i], a, b) << std::endl;
    }

    return 0;
}