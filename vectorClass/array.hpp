//
//  array.hpp
//  vectorClass
//
//  Created by xitowzys on 24.10.2020.
//

#ifndef array_hpp
#define array_hpp

#include <iostream>

class ArrayException {};

class Array
{
private:
    // Обычная вместимость
    const static int DEFAULT_CAPACITY = 10;

    // Хранилище элементов
    int* ptr;

    // Текущий размер
    int size;

    // Вместимость
    int capacity;

    // Увеличение предельного размера
    void increaseCapacity(int newCapacity);

public:
    // Конструктор
    explicit Array(int startCapacity = DEFAULT_CAPACITY);
    
    // Конструктор копирования
    Array(const Array& arr);

    // Деструктор
    ~Array();
    
    // Вставка элемента
    void insert(int elem);
    void insert(int elem, int index);

    //Удаление элемента
    void remove(int index);

    //
    Array& operator = (const Array& arr);

    // Чтение элементов массива
    int operator [](int index) const;
    // Запись элементов массива
    int& operator[] (int index);
    
    int getSize() const;
    
    // Вывод вектора
    friend std::ostream& operator <<(std::ostream& out,const Array& arr);
};

#endif /* array_hpp */
