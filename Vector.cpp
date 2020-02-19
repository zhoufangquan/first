//
// Created by molin on 2020/2/15.
//
#include "Student.h"

bool Vector::insert(const int i, const ElemType &e) {
    if (i < 0 || i >= n) return false;
    if (n == capacity && !add_capacity())
        return false;
    for (int j = n; j > i; j--)
        data[j] = data[j - 1];
    data[i] = e;
    n++;
    return true;
}

bool Vector::erase(const int i) {
    if (i < 0 || i >= n) return false;
    for (int j = i; j < n; j++) {
        data[j] = data[j + 1];
    }
    n--;
    return true;
}

bool Vector::push_back(const ElemType &e) {
    if (n == capacity && !add_capacity())
        return false;
    data[n++] = e;
    return true;
}

bool Vector::pop_back() {
    if (n == 0) return true;
    n--;
    return true;
}

bool Vector::get(const int i, ElemType &e) const {
    if (i < 0 || i >= n) return false;
    e = data[i];
    return true;
}

bool Vector::set(const int i, const ElemType e) {
    if (i < 0 || i >= n) return false;
    data[i] = e;
    return false;
}

bool Vector::add_capacity() {
    ElemType *temp = new ElemType[2 * capacity];
    if (!temp) return false;
    for (int i = 0; i < n; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity *= 2;
    return true;
}
