//
//  array.cpp
//  vectorClass
//
//  Created by xitowzys on 24.10.2020.
//

#include "array.hpp"

// Конструктор
Array::Array(int startCapacity)
{
    if (startCapacity <= 0)
        this->capacity = this->DEFAULT_CAPACITY;
    else
        this->capacity = startCapacity;

    this->ptr = new int[this->capacity];

    this->size = 0;
}

// Конструктор копирования
Array::Array(const Array& arr)
{
    this->ptr = new int(arr.capacity);

    this->size = arr.size;

    this->capacity = arr.capacity;

    for(int i = 0; i < this->size; i++)
        this->ptr[i] = arr.ptr[i];
}

// Деструктор
Array::~Array()
{
    delete[] this->ptr;

    this->ptr = nullptr;
}

// Вставка элемента
void Array::insert(int elem)
{
    insert(elem, this->size);
}

void Array::insert(int elem, int index)
{
    if (index > this->size || index < 0)
        throw ArrayException();

    if (this->size == this->capacity)
        this->increaseCapacity(this->size + 1);

    for(int i = this->size - 1; i >= index; i--)
        this->ptr[i + 1] = this->ptr[i];

    this->size++;

    this->ptr[index] = elem;
}

//Удаление элемента
void Array::remove(int index) {
    if (index < 0 || index >= size)
        throw ArrayException();
    
    for (int j = index; j < size - 1; j++)
        ptr[j] = ptr[j + 1];
    
    ptr[size-1]=0;
    size--;
}


Array& Array::operator = (const Array& arr)
{
    if (this == &arr)
        return *this;

    if (this->capacity != arr.capacity)
    {
        delete[] this->ptr;
        this->ptr = new int[arr.capacity];
        this->capacity = arr.capacity;
    }

    this->size = arr.size;

    for(int i = 0; i < this->size; i++)
        this->ptr[i] = arr.ptr[i];

    return *this;
}

int& Array::operator[] (int index)
{
    if (index == size)
        size++;
    
    if (this->size == this->capacity)
        this->increaseCapacity(this->size + 1);
    
    if (index > this->size || index < 0)
        throw ArrayException();
    else
        return this->ptr[index];
}

int Array::getSize() const
{
    return size;
}

// Вывод вектора
std::ostream& operator << (std::ostream& out, const Array& arr)
{
    out << "Размер вектора: " << arr.size << std::endl;
    
    for (int i = 0; i < arr.size; i++)
        out << arr.ptr[i] << std::endl;
    
    return out;
}

void Array::increaseCapacity(int newCapacity)
{
    this->capacity = newCapacity < this->capacity*2 ? this->capacity*2 : newCapacity;

    int* newPtr = new int[this->capacity];

    for(int i = 0; i < size; i++)
        newPtr[i] = this->ptr[i];

    delete[] this->ptr;

    this->ptr = newPtr;
}
