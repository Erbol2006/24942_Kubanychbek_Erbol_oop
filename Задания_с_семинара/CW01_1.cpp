/**
 * @brief Здесь решение первого задания: 
 * Vector. (доделать) В работе с вектором заменить инициализацию итератора 
 * с v.begin() на v.end(), и добиться, чтобы содержимое вектора
 *  в точности повторяло результат, полученный на занятии 
 * (при использовании v.begin()).

 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Вспомогательная ф-ия для печати вектора строк 
void pv(const vector<string>& vec){
    for (auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    //инициализация вектора
    vector<string> v {"u", "y", "yy", "ttt", "string"};
    cout << v.size() << endl;
    pv(v);

    //добавляем два элемента 
    v.push_back("str"); //добавляет копию
    v.emplace_back("trs"); //конструирует на месте 
    pv(v);
    v.pop_back();
    pv(v);

    //Здесь изменили v.begin() на v.end() и корректируем смещение
    auto it = v.end(); //начинаем с конца
    advance(it, -2); //двигаемся назад на 2, попадаем на "string"

    cout <<"Элемент по итератору: " << *it << endl; //выведит string 

    //вставляем 3 копии 'jjjj' перед этим элементом
    v.insert(it, 3, "jjjj");
    pv(v); // u y yy ttt jjjj jjjj jjjj string str 
    return 0;
}

