//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <cassert>
#include "AddressLinkedList.h"

AddressListNode::AddressListNode() {
    next = nullptr;
    //data will be default initialized
}

AddressListNode::AddressListNode(const Address& value)
    : data(value)
{
    next = nullptr;
}

AddressLinkedList::AddressLinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}

AddressLinkedList::~AddressLinkedList() {
    AddressListNode* temp = head;
    while(head != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
    length = 0;
}

AddressLinkedList::AddressLinkedList(const AddressLinkedList& other) {
    //TODO - Write copy constructor...
    //Don't forget to initialize head/tail/length
    AddressListNode* temp = other.head;
    head = nullptr;
    tail = nullptr;
    length = 0;
    while(temp != nullptr){
        insertEnd(temp->data);
        temp = temp->next;
    }
}

AddressLinkedList& AddressLinkedList::operator=(const AddressLinkedList& other) {
    if(this != &other) {
        AddressListNode* temp = head;
        while(temp != nullptr){
            head = head->next;
            delete temp;
            temp = head;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
        temp = other.head;
        while(temp != nullptr){
            insertEnd(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

void AddressLinkedList::insertStart(const Address& value){
    AddressListNode* newNode = new AddressListNode(value);
    newNode->next = head;
    head = newNode;
    if(head->next == nullptr){
        tail = head;
    }
    length++;
}

void AddressLinkedList::insertEnd(const Address& value){
    if(length == 0){
        insertStart(value);
        return;
    }
    AddressListNode* newNode = new AddressListNode(value);
    tail->next = newNode;
    tail = newNode;
    length++;
}

void AddressLinkedList::printRange(int startIndex, int endIndex) const{
    for(int i = startIndex; i <= endIndex; i++) {
        std::cout << retrieveAt(i);
    }
}

Address AddressLinkedList::retrieveAt(int index) const{
    if(index < 0 || index >= length)
        throw out_of_range("Bad index in retrieveAt");

    AddressListNode* current = head;
    for(int i = 0; i < index; i++) {
        current = current->next;
        //know those steps are safe, since we checked index against length
    }

    return current->data;
}

int AddressLinkedList::listSize() const{
    return length;
}

void AddressLinkedList::combine(AddressLinkedList& other){
    for(int i = 0; i < other.length; i++){
        insertEnd(other.retrieveAt(i));
    }
    other.~AddressLinkedList();
}

void AddressLinkedList::removeFirstIndex() {
    if(head == nullptr)
        throw out_of_range("Can't remove from empty list");

    AddressListNode* targetNode = head;

    head = head->next;  //find new head

    //Check to see if the nodes we are deleting was also the tail
    if(targetNode == tail) {
        tail = nullptr;
    }

    delete targetNode;

    length--;
}

void AddressLinkedList::removeAt(int index){
    if(index < 0 || index >= length)
        throw out_of_range("Bad index in removeAt");

    if(index == 0) {
        //First item is special case... use removeFirst for it
        removeFirstIndex();
        return;
    }

    //Find node BEFORE one we want to delete - it is "current"
    AddressListNode* current = head;
    for(int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    AddressListNode* nodeToRemove = current->next;

    //Cut node out of list
    current->next = nodeToRemove->next;

    delete nodeToRemove;    //Delete it from heap

    //Is there nothing left after current node? Then it is the new tail
    if(current->next == nullptr)
        tail = current;

    length--;
}

AddressLinkedList AddressLinkedList::extractAllMatches(const Address& itemToMatch){
    AddressLinkedList matchList;
    for(int i = 0; i < length; i++){
        if(retrieveAt(i).state == itemToMatch.state){
            matchList.insertEnd(retrieveAt(i));
            removeAt(i);
            i--;
        }
    }
    return matchList;
}

Address AddressLinkedList::removeFirst(){
    Address targetAddress = head->data;
    removeFirstIndex();
    return targetAddress;
}

void AddressLinkedList::interleave(AddressLinkedList& other){
    AddressLinkedList newList = *this;
    this->~AddressLinkedList();
    AddressListNode* temp = newList.head;
    while(temp != nullptr){
        insertEnd(temp->data);
        insertEnd(other.removeFirst());
        temp = temp->next;
    }
}
