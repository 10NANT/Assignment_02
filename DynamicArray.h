#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>  //for std::out_of_range

//Template based dynamic array
template <typename T>
class DynamicArray {
private:
    T* data;
    std::size_t size;
    std::size_t capacity;

public:
    //Constructors and destructor
    DynamicArray();
    ~DynamicArray();

    //Copy semantics
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    //Move semantics
    DynamicArray(DynamicArray&& other);
    DynamicArray& operator=(DynamicArray&& other);

    void push_back(const T& value);
    void pop_back();
    T& at(std::size_t index);

    std::size_t getSize() const;
    std::size_t getCapacity() const;

    //Iterator support
    T* begin();
    T* end();
};

//Constructor
template <typename T>
DynamicArray<T>::DynamicArray()
{
    data = nullptr;
    size = 0;
    capacity = 0;
}

//Destructor
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] data;
}

//Copy constructor
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
    size = other.size;
    capacity = other.capacity;

    if (capacity > 0) {
        data = new T[capacity];
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    else {
        data = nullptr;
    }
}

//Copy assignment operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
    if (this != &other) {
        delete[] data;

        size = other.size;
        capacity = other.capacity;

        if (capacity > 0) {
            data = new T[capacity];
            for (std::size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }
    return *this;
}

//Move constructor
template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other)
{
    data = other.data;
    size = other.size;
    capacity = other.capacity;

    // Reset source object to a valid empty state
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

//Move assignment operator
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other)
{
    if (this != &other) {
        delete[] data;

        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

//push_back
template <typename T>
void DynamicArray<T>::push_back(const T& value)
{
    if (size >= capacity) {
        std::size_t newCapacity;
        if (capacity == 0) {
            newCapacity = 1;
        }
        else {
            newCapacity = capacity * 2;
        }

        T* newData = new T[newCapacity];
        for (std::size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    data[size] = value;
    size++;
}

//pop_back
template <typename T>
void DynamicArray<T>::pop_back()
{
    if (size == 0) {
        throw std::out_of_range("Cannot pop_back from an empty array");
    }
    size--;
}

//at
template <typename T>
T& DynamicArray<T>::at(std::size_t index)
{
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

//getSize
template <typename T>
std::size_t DynamicArray<T>::getSize() const
{
    return size;
}

//getCapacity
template <typename T>
std::size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}

//Iterator support
template <typename T>
T* DynamicArray<T>::begin()
{
    return data;
}

template <typename T>
T* DynamicArray<T>::end()
{
    return data + size;
}

#endif // DYNAMIC_ARRAY_H
