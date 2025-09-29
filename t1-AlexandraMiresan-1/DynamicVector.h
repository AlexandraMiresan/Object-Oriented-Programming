//
// Created by Ale on 4/1/2025.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdexcept>


template<typename T>
class DynamicVector {
private:
    T *elems;
    int capacity{};
    int size{};

    void resize();

public:
    DynamicVector(int capacity = 10);

    DynamicVector(const DynamicVector &other);

    ~DynamicVector();

    DynamicVector &operator=(const DynamicVector &other);

    T &operator[](int index) { return this->elems[index]; };

    void add(const T& elem);

    void remove(const int pos);

    void update(const int pos, const T elem);

    T get_elem(const int pos) const;

    int get_size() const{return this->size;};

    void set_elem(int index, T elem);

};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];

}

template<typename T>
void DynamicVector<T>::resize() {
    T *temp = new T[this->capacity*2];
    for(int i = 0; i < this->size; i++) {
        temp[i] = this->elems[i];
    }

    this->capacity *= 2;
    delete [] this->elems;
    this->elems = temp;

}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->elems = new T[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->elems[i] = other.elems[i];
    }

}

template<typename T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector &other) {
    if(this == &other) {
        return *this;
    }


    this->capacity = other.capacity;
    this->size = other.size();

    delete [] this->elems;
    this->elems = new T[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->elems[i] = other.elems[i];
    }
    return *this;
}

template<typename T>
DynamicVector<T>& operator+(DynamicVector<T>& other, const T elem) {
    other.add(elem);
    return other;
}

template<typename T>
DynamicVector<T>& operator+(const T elem, DynamicVector<T>& other) {
    other.add(elem);
    return other;
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
    delete [] this->elems;
}

template<typename T>
void DynamicVector<T>::add(const T &elem) {
    if(this->size == this->capacity) {
        resize();
    }

    this->elems[this->size++] = elem;
}

template<typename T>
void DynamicVector<T>::remove(const int pos) {
    for(int i = 0; i < this->size; i++) {
        if(i == pos) {
            for(int j = i; j < this->size - 1; j++) {
                this->elems[j] = this->elems[j + 1];
            }
            this->size--;
        }
    }
}

template<typename T>
void DynamicVector<T>::update(const int pos, const T elem) {
    this->elems[pos] = elem;
}

template<typename T>
T DynamicVector<T>::get_elem(const int pos) const {
    return this->elems[pos];
}

template<typename T>
void DynamicVector<T>::set_elem(int index, T elem) {
    if (index >= 0 && index < this->size) {
        this->elems[index] = elem;
    } else {
        throw std::out_of_range("Index out of bounds!");
    }
}




#endif //DYNAMICARRAY_H
