//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>

using namespace std;

/**
 * @brief List node for AddressLinkedList
 */
template <class T>
struct StackNode
{
    T data;
    StackNode* next;

    StackNode();
    StackNode(const T& value);
};


/**
 * @brief Stack based on a linked list
 */
template <class T>
class Stack
{
private:
    StackNode<T>* top;
   int length;

public:
    /**
     * @brief Construct empty stack
     */
    Stack();

    /**
     * @brief Copy constructor
     */
    Stack(const Stack<T>& other);

    /**
     * @brief Assignment Operator
     */
    Stack<T>& operator=(const Stack<T>& other);

    /**
     * @brief Destructor
     */
    ~Stack();

    /**
     * @brief Check if stack is empty
     * @return true if nothing in stack, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief Add item to stack
     * @param value Item to push a copy of onto the stack
     */
    void push(const T& item);

    /**
     * @brief Remove and return top item from stack
     * @return Item that was at the top of the stack
     * Can throw exception/blow up with assertion if currently empty
     */
    T pop();

    /**
     * @brief Return a copy of the top item on the stack (wihtout removing it)
     * @return Item that is at the top of the stack
     */
    T peek() const;


    /**
     * @brief Output the stack in order to cout
     */
    void print() const;
	 
    /**
     * @brief Output the stack in reverse order to cout
     */
    void reversePrint() const;

};


//--------------------------------------------------------------------
// StackNode implementations
//--------------------------------------------------------------------

template <class T>
StackNode<T>::StackNode() {
    next = nullptr;
    data = T(); //data will be default initialized
}

template <class T>
StackNode<T>::StackNode(const T& value)
    : data(value)
{
    next = nullptr;
}

//--------------------------------------------------------------------
// Stack Implementations
//--------------------------------------------------------------------

template <class T>
/**
 * @brief Construct empty stack
 */
Stack<T>::Stack(){
    length = 0;
    top = nullptr;
}

template <class T>
/**
 * @brief Copy constructor
 */
Stack<T>::Stack(const Stack<T>& other){
    if(other.isEmpty()){
        top = nullptr;
        length = 0;
        return;
    }
    StackNode<T>* temp = other.top;
    Stack copy;
    while(temp != nullptr){
        copy.push(temp->data);
        temp = temp->next;
    }
    while(!copy.isEmpty()){
        push(copy.pop());
    }
}

template <class T>
/**
 * @brief Assignment Operator
 */
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
    if(this != &other){
        while(!isEmpty()){
            pop();
        }
        StackNode<T>* temp = other.top;
        Stack copy;
        while(temp != nullptr){
            copy.push(temp->data);
            temp = temp->next;
        }
        while(!copy.isEmpty()){
            push(copy.pop());
        }
    }
    return *this;
}

template <class T>
/**
 * @brief Destructor
 */
Stack<T>::~Stack(){
    while(!isEmpty()){
        pop();
    }
}

template <class T>
/**
 * @brief Check if stack is empty
 * @return true if nothing in stack, false otherwise
 */
bool Stack<T>::isEmpty() const{
    if(length == 0){
        return true;
    }
    return false;
}

template <class T>
/**
 * @brief Add item to stack
 * @param value Item to push a copy of onto the stack
 */
void Stack<T>::push(const T& item){
    StackNode<T>* newNode = new StackNode<T>(item);
    if(!isEmpty()){
        newNode->next = top;
    }
    top = newNode;
    length++;
}

template <class T>
/**
 * @brief Remove and return top item from stack
 * @return Item that was at the top of the stack
 * Can throw exception/blow up with assertion if currently empty
 */
T Stack<T>::pop(){
    if(isEmpty()){
        assert(0);
    }
    StackNode<T>* deleteNode = top;
    top = top->next;
    T value = deleteNode->data;
    delete deleteNode;
    length--;

    return value;
}

template <class T>
/**
 * @brief Return a copy of the top item on the stack (wihtout removing it)
 * @return Item that is at the top of the stack
 */
T Stack<T>::peek() const{
    StackNode<T>* copy = top;
    return copy->data;
}

template <class T>
/**
 * @brief Output the stack in order to cout
 */
void Stack<T>::print() const{
    StackNode<T>* temp = top;
    for(int i = 0; i < length; i++){
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

template <class T>
/**
 * @brief Output the stack in reverse order to cout
 */
void Stack<T>::reversePrint() const{
    Stack<T> reverse;
    StackNode<T>* temp = top;
    while(temp != nullptr){
        reverse.push(temp->data);
        temp = temp->next;
    }
    reverse.print();
}


#endif // STACK_H
