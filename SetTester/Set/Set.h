/**
  @author (Louis)YunHo Law
  @brief Assignment 7
  */
#ifndef SET_H
#define SET_H


#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>

using namespace std;

template <class T>
class Set{
public:
    Set();
    bool contains(T item) const;
    void add(T item);
    void grow();
    int getSize() const;
    Set(const Set<T>& otherItems);
    Set<T>& operator=(const Set<T>& other);
    ~Set();
    void remove(T item);
    void clear();
    T removeSmallest();
    bool operator==(const Set<T>& other) const;
    string toString() const;
    Set<T> intersectionWith(const Set<T>& other) const;

private:
    T *items;
    int capacity;
    int size;
};

//-----------------IMPLEMENTATIONS---------------------

template <class T>
Set<T>::Set(){
    capacity = 8;
    size = 0;
    items = new T[capacity];
}

template <class T>
bool Set<T>::contains(T item) const{

        for (int i = 0; i < size; i++){
            if(items[i] == item){
                return true;
                break;
            }

        }

    return false;
}

template <class T>
void Set<T>::add(T item){
    if(size >= capacity){
        grow();
    }
    if(!contains(item)){
        items[size] = item;
        size++;
    }
}

template <class T>
void Set<T>::grow(){
    if(size >= capacity){
        int newCapacity = capacity * 2;
        T* newitems = new T[newCapacity];
        for (int i = 0; i < capacity; i++){
            newitems[i] = items[i];
        }
        capacity = newCapacity;
        delete[]items;
        items = newitems;
    }
}

template <class T>
int Set<T>::getSize() const{
    return size;
}

template <class T>
Set<T>::Set(const Set<T> &otherItems){
    capacity = otherItems.capacity;
    size = otherItems.size;
    items = new T[capacity];
    for(int i = 0; i < capacity; i++){
        items[i] = otherItems.items[i];
    }
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& other){
    if(&other == this){
        return *this;
    }
    size = other.size;
    capacity = other.capacity;
    delete[]items;
    items = new T[other.capacity];
    for(int i = 0; i < size; i++){
        items[i] = other.items[i];
    }

    return *this;
}

template <class T>
Set<T>::~Set(){
    delete[]items;
}

template <class T>
void Set<T>::remove(T item){
    int location;
    for(int i = 0; i < size; i++){
        if(items[i] == item){
            location = i;
        }
    }
    for(int i = location; i < size - 1; i ++){
        items[i] = items[i+1];
    }
    size--;
}

template <class T>
void Set<T>::clear(){
    size = 0;
}

template <class T>
T Set<T>::removeSmallest(){
    assert(size != 0);
    T smallest = items[0];
    for (int i = 0; i < size; i++){
        if(items[i] < smallest){
            smallest = items[i];
        }
    }

    remove(smallest);
    return smallest;
}

template <class T>
bool Set<T>::operator==(const Set<T>& other) const{
    bool same;
    if (size != other.size){
        same = false;
    }
    else{
        for (int i = 0; i < size; i++){
            if(other.contains(items[i])){
                same = true;
            }
            else{
                same = false;
            }
        }
    }
    return same;
}

template <class T>
string Set<T>::toString() const{
    stringstream output;
    output << "{";
    if(size <= 0){
        output << "";
    }
    else{
        for(int i = 0; i < size - 1; i++){
            output << items[i] << ", ";
        }
        output << items[size - 1];
    }
    output << "}";

    return output.str();
}

template <class T>
Set<T> Set<T>::intersectionWith(const Set<T> &other) const{
    Set<T> newSet;
    for(int i = 0; i < size; i++){
        if(other.contains(items[i])){
            newSet.add(items[i]);
        }
    }
    return newSet;
}

#endif // SET_H
