//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <iostream>

using namespace std;

const int QUEUE_INIT_SIZE = 20;

/**
 * @brief Queue defined using array as ring
 */
template <class T>
class Queue
{
private:
    T* data;
    int start;
    int end;
    int dataSize;

    /**
     * @brief used to allocate a larger backing array when storage fills
     */
    void grow();

public:
    /**
     * @brief Construct empty stack
     */
    Queue();

    /**
     * @brief Copy constructor
     */
    Queue(const Queue<T>& other);

    /**
     * @brief Assignment Operator
     */
    Queue<T>& operator=(const Queue<T>& other);

    /**
     * @brief Destructor
     */
    ~Queue();

    /**
     * @brief Check if queue is empty
     * @return true if nothing in the queue, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief add item to back of queue
     * @param value Item to add
     */
    void enqueue(const T& item);

    /**
     * @brief Remove and return front item from queue
     * @return Item that was at the front of the queue
     * Can throw exception/blow up with assertion if currently empty
     */
    T dequeue();

    /**
     * @brief Return a copy of the front item
     * @return Item that is at the front of the queue
     */
    T front() const;
    void duplicate(const Queue& other);
    bool full();
    void print() const;
};

//--------------------------------------------------------------------
// Queue Implementations
//--------------------------------------------------------------------

template <class T>

Queue<T>::Queue(){
    dataSize = QUEUE_INIT_SIZE;
    start = 0;
    end = 0;
    data = new T[dataSize];
}

template <class T>
/**
 * @brief Copy constructor
 */
Queue<T>::Queue(const Queue<T>& other){
    duplicate(other);
}

template <class T>
/**
 * @brief Assignment Operator
 */
Queue<T>& Queue<T>::operator=(const Queue<T>& other){
    if(this != &other) {
        //no self copies
        delete [] data;  //delete old storage
        duplicate(other);
    }

    return *this;
}

template <class T>
/**
 * @brief Destructor
 */
Queue<T>::~Queue(){
    delete [] data;
}

template <class T>
void Queue<T>::duplicate(const Queue& other) {
    dataSize = other.dataSize;
    start = other.start;
    end = other.end;
    data = new T[dataSize];

    //this copies unused indexes, but keeps things simple...
    for(int i = 0; i < dataSize; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
/**
 * @brief used to allocate a larger backing array when storage fills
 */
void Queue<T>::grow(){
    T* newData = new T[dataSize * 2];

    ///TODO - starting from start and continuing to end (possibly wrapping)
    ///          copy items from old list to newList
    int temp = 0;
    for(int i = start; i != end; i++){
        newData[temp] = data[i];
        if(i + 1 == dataSize){
            i = -1;
        }
        temp++;
    }
    ///TODO - Set start and end positions based on position in new list
    start = 0;
    end = temp;

    //update size and storage
    dataSize *= 2;
    delete [] data;
    data = newData;
}

template <class T>
/**
 * @brief Check if queue is empty
 * @return true if nothing in the queue, false otherwise
 */
bool Queue<T>::isEmpty() const{
    if(end == start)
        return true;
    else
        return false;
}

template <class T>
bool Queue<T>::full() {
    if(end + 1 == start || (end + 1 == dataSize && start == 0)){
        return true;
    }
    return false;
}

template <class T>
/**
 * @brief add item to back of queue
 * @param value Item to add
 */
void Queue<T>::enqueue(const T& item){
    if(full()){
        grow();
    }
    data[end] = item;
    if(end == dataSize && start != 0){
        end = 0;
    }else{
        end++;
    }
}

template <class T>
/**
 * @brief Remove and return front item from queue
 * @return Item that was at the front of the queue
 * Can throw exception/blow up with assertion if currently empty
 */
T Queue<T>::dequeue(){
    if(isEmpty()){
        assert(0);
    }
    T temp = data[start];
    if(start == dataSize - 1){
        start = 0;
    }else{
        start++;
    }

    return temp;
}

template <class T>
/**
 * @brief Return a copy of the front item
 * @return Item that is at the front of the queue
 */
T Queue<T>::front() const{
    T copy = data[start];
    return copy;
}

template <class T>
void Queue<T>::print() const{
    for(int i = start; i != end; i++){
        cout << data[i];
        if(i + 1 == dataSize){
            i = -1;
        }
    }
}


#endif // STACK_H
