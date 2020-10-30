//
//  array.cpp
//  vectorClass
//
//  Created by xitowzys on 24.10.2020.
//

#include "array.hpp"

// Конструктор
template <class Type>
Array<Type>::Array(int startCapacity)
{
    if (startCapacity <= 0)
        this->capacity = this->DEFAULT_CAPACITY;
    else
        this->capacity = startCapacity;
    
    this->ptr = new Type[this->capacity];
    
    this->size = 0;
}

// Конструктор копирования
template <class Type>
Array<Type>::Array(const Array<Type>& arr)
{
    this->ptr = new Type(arr.capacity);
    
    this->size = arr.size;
    
    this->capacity = arr.capacity;
    
    for(int i = 0; i < this->size; i++)
    this->ptr[i] = arr.ptr[i];
}

// Деструктор
template <class Type>
Array<Type>::~Array()
{
    delete[] this->ptr;
    
    this->ptr = nullptr;
}

// Вставка элемента
template <class Type>
void Array<Type>::insert(Type elem)
{
    insert(elem, this->size);
}

template <class Type>
void Array<Type>::insert(Type elem, int index)
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

// Вставка вектора в вектор
template<class Type>
void Array<Type>::insert(const int index, const Array<Type>& other) {
    if (index < 0 || index > this->size)
        throw ArrayException();
    if ((this->size + other.size) == this->capacity)
        this->increaseCapacity(this->size + other.size + 1);
    
    for (int i = this->size + other.size - 1; i >= index + other.size; i--)
    ptr[i] = ptr[i - other.size];
    
    for (int i = other.size - 1; i >= 0; i--)
    ptr[index + i] = other.ptr[i];
    
    this->size += other.size;
}

//Удаление элемента
template <class Type>
void Array<Type>::remove(int index) {
    if (index < 0 || index >= size)
        throw ArrayException();
    
    for (int j = index; j < size - 1; j++)
    ptr[j] = ptr[j + 1];
    
    ptr[size-1]=0;
    size--;
}

template <class Type>
Array<Type>& Array<Type>::operator = (const Array<Type>& arr)
{
    if (this == &arr)
        return *this;
    
    if (this->capacity != arr.capacity)
    {
        delete[] this->ptr;
        this->ptr = new Type[arr.capacity];
        this->capacity = arr.capacity;
    }
    
    this->size = arr.size;
    
    for(int i = 0; i < this->size; i++)
    this->ptr[i] = arr.ptr[i];
    
    return *this;
}

template <class Type>
Type& Array<Type>::operator[] (int index)
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

template <class Type>
int Array<Type>::getSize() const
{
    return size;
}

// Вывод вектора
template <class Type>
std::ostream& operator << (std::ostream& out, const Array<Type>& arr)
{
    out << "Размер вектора: " << arr.size << std::endl;
    
    for (int i = 0; i < arr.size; i++)
    out << arr.ptr[i] << std::endl;
    
    return out;
}

// Увеличение предельного размера
template <class Type>
void Array<Type>::increaseCapacity(int newCapacity)
{
    this->capacity = newCapacity < this->capacity*2 ? this->capacity*2 : newCapacity;
    
    Type* newPtr = new Type[this->capacity];
    
    for(int i = 0; i < size; i++)
    newPtr[i] = this->ptr[i];
    
    delete[] this->ptr;
    
    this->ptr = newPtr;
}
