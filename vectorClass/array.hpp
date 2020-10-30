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
template <class Type>

class Array
{
private:
    // Обычная вместимость
    const static int DEFAULT_CAPACITY = 10;
    
    // Текущий размер
    int size;
    
    // Вместимость
    int capacity;
    
    // Увеличение предельного размера
    void increaseCapacity(int newCapacity);
    
    // Хранилище элементов
    Type* ptr;
    
public:
    
    // Конструктор
    explicit Array(int startCapacity = DEFAULT_CAPACITY);
    
    // Конструктор копирования
    Array<Type>(const Array<Type>& arr);
    
    // Деструктор
    ~Array();
    
    // Вставка элемента
    void insert(Type elem);
    void insert(Type elem, int index);
    
    // Вставка вектора в вектор
    void insert(const int index, const Array& other);
    
    //Удаление элемента
    void remove(int index);
    
    Array<Type>& operator = (const Array<Type>& arr);
    
    // Чтение элементов массива
    Type operator [](int index) const;
    
    // Запись элементов массива
    Type& operator[] (int index);
    
    // Получить размер вектора
    int getSize() const;
    
    // Вывод вектора
    friend std::ostream& operator <<(std::ostream& out,const Array<Type>& arr);
};

#endif /* array_hpp */
