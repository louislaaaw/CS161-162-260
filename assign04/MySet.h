//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef MYSET_H
#define MYSET_H

#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;

//Node node for Set
template <class T>
struct SetNode
{
    T data;
    SetNode<T>* left;
    SetNode<T>* right;

    SetNode(const T& value);
};


//Set based on a BST
template <class T>
class MySet
{
private:
    SetNode<T>* root;

public:
    //Construct empty set
    MySet();

    //Copy constructor
    MySet(const MySet<T>& other);

    //Assignment Operator
    MySet<T>& operator=(const MySet<T>& other);

    //Destructor
    ~MySet();

    //get number of items contained
    int size() const;

    //get depth of underlying tree
    int depth() const;

    //Add item to set
    //  Duplicate items will be ignored
    void add(const T& item);

    //Check if item is in the set
    bool contains(const T& item) const;

    //Remove given item from the set if it exists
    void remove(const T& item);

    //get largest item in set (does not remove)
    T getLargest() const;

    //get smallest item in set (does not remove)
    T getSmallest() const;

    //generates a new set containing all the items that are in both
    //  this set and another set
    MySet<T> intersectionWith(const MySet<T>& other) const;

    //Returns a vector of items in the set that are >= start and < end
    std::vector<T> getRange(const T& startValue, const T& endValue) const;

    void deleteSubTree(SetNode<T>* startNode);
    SetNode<T>* copySubTree(SetNode<T>* currentNode);
    bool containsHelper(SetNode<T>* curNode, T valToFind) const;
    SetNode<T>* removeSmallestNode(SetNode<T>* curNode);
    T smallestValueFrom(SetNode<T>* curNode);
    T smallestValue();
    SetNode<T>* removeHelper(SetNode<T>* curNode, T valToRemove);
    int sizeHelper(SetNode<T>* currentNode) const;
    int depthHelper(SetNode<T>* currentNode) const;
    void intersectionHelper(SetNode<T>* curNode) const;
    void vecBuilder(SetNode<T>* curNode, vector<T>& theVec) const;
    vector<T> toVector() const;
};


//--------------------------------------------------------------------
// SetNode implementations
//--------------------------------------------------------------------

template <class T>
SetNode<T>::SetNode(const T& value)
    : data(value)
{
    left = nullptr;
    right = nullptr;
}

//--------------------------------------------------------------------
// Set Implementations
//--------------------------------------------------------------------

template <class T>
//Construct empty set
MySet<T>::MySet(){
    root = nullptr;
}

template <class T>
//Copy constructor
MySet<T>::MySet(const MySet<T>& other){
    root = copySubTree(other.root);
}

template <class T>
//Assignment Operator
MySet<T>& MySet<T>::operator=(const MySet<T>& other){
    if(this != &other) {
        //remove any existing nodes before
        //copying nodes of other tree
        deleteSubTree(root);
        root = copySubTree(other.root);
    }
    return *this;
}

template <class T>
SetNode<T>* MySet<T>::copySubTree(SetNode<T>* currentNode) {
    if(currentNode == nullptr)
        return nullptr;

    SetNode<T>* newNode = new SetNode<T>(currentNode->data);
    newNode->left = copySubTree(currentNode->left);
    newNode->right = copySubTree(currentNode->right);

    return newNode;
}


template <class T>
void MySet<T>::deleteSubTree(SetNode<T>* startNode) {
    if(startNode == nullptr)
        return;
    deleteSubTree(startNode->left);
    deleteSubTree(startNode->right);
    delete startNode;
}

template <class T>
//Destructor
MySet<T>::~MySet(){
    deleteSubTree(root);
}

template <class T>
int MySet<T>::sizeHelper(SetNode<T>* currentNode) const{
    if(currentNode == nullptr){
        return 0;
    }else{
        return 1 + sizeHelper(currentNode->left) + sizeHelper(currentNode->right);
    }
}


template <class T>
//get number of items contained
int MySet<T>::size() const{
    return sizeHelper(root);
}

template <class T>
int MySet<T>::depthHelper(SetNode<T>* currentNode) const{
    if(currentNode == nullptr)
        return -1;
    return 1 + max(depthHelper(currentNode->left), depthHelper(currentNode->right));
}

template <class T>
//get depth of underlying tree
int MySet<T>::depth() const{
    return depthHelper(root);
}

template <class T>
//Add item to set
//  Duplicate items will be ignored
void MySet<T>::add(const T& item){
    if(root == nullptr){
        root = new SetNode<T>(item);
    }
    if(contains(item)){
        return;
    }
    else{
        SetNode<T>* parent = root;
        SetNode<T>* current = root;
        do{
            parent = current;
            if(item < current->data){
                current = parent->left;
            }else{
                current = parent->right;
            }
        }
        while(current != nullptr);
            if(item < parent->data){
                parent->left = new SetNode<T>(item);
            }
            else{
                parent->right = new SetNode<T>(item);
            }
    }
}

template <class T>
bool MySet<T>::containsHelper(SetNode<T>* curNode, T valToFind) const {
    if(curNode == nullptr)
        return false;
    if(curNode->data == valToFind)
        return true;

    if(curNode->data > valToFind)
        return containsHelper(curNode->left, valToFind);
    else
        return containsHelper(curNode->right, valToFind);
}

template <class T>
//Check if item is in the set
bool MySet<T>::contains(const T& item) const{
    return containsHelper(root, item);
}

template <class T>
//Recursive helper function to remove smallest value starting from indicated node
SetNode<T>* MySet<T>::removeSmallestNode(SetNode<T>* curNode)
{
    //TODO - FIXME - See worksheet
    if(curNode->left == nullptr){
        SetNode<T>* current = curNode->right;
        delete current;
        return curNode->right;
    }
    else{
        curNode->left = removeSmallestNode(curNode->left);
        return curNode;
    }
}

template <class T>
//Recursive helper function to return smallest value starting from given node
T MySet<T>::smallestValueFrom(SetNode<T>* curNode)
{
    while(curNode->left != nullptr){
        curNode = curNode->left;
    }
    return curNode->data;
}


template <class T>
T MySet<T>::smallestValue() {
    if(root == nullptr)
        assert(0);

    return smallestValueFrom(root);
}

template <class T>
///Helper function for remove - chains down, until it finds node to
/// remove. Removes that node and repairs pointers on way back up
SetNode<T>* MySet<T>::removeHelper(SetNode<T>* curNode, T valToRemove) {
    if(curNode->data == valToRemove) {
        //Found node to remove
        if(curNode->right == nullptr) {
            //no right child, replace with left child
            SetNode<T>* leftChild = curNode->left;
            delete curNode;
            return leftChild;   //this replaces the current node
        }
        else if(curNode->left == nullptr) {
            //no left child, replace with right child
            SetNode<T>* rightChild = curNode->right;
            delete curNode;
            return rightChild;  //this replaces the current node
        }
        else {
            //Have two children, replace with smallest value from right hand side
            // then delete smallest node on right side
            curNode->data = smallestValueFrom(curNode->right);
            curNode->right = removeSmallestNode(curNode->right);

            //Return this node up the tree to hook to parent
            return curNode;
        }

    } else {
        //Keep looking, set child to result of removing from appropriate side
        if(curNode->data > valToRemove)
            curNode->left = removeHelper(curNode->left, valToRemove);
        else
            curNode->right = removeHelper(curNode->right, valToRemove);

        //Return this node up the tree to hook to parent
        return curNode;
    }
}

template <class T>
//Remove given item from the set if it exists
void MySet<T>::remove(const T& item){
    //Check if actualy have it first to simplify removal logic
    if(!contains(item))
        return;

    //new root is root that results from doing removeHelper
    root = removeHelper(root, item);
}

template <class T>
//get largest item in set (does not remove)
T MySet<T>::getLargest() const{
    SetNode<T>* current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    return current->data;
}

template <class T>
//get smallest item in set (does not remove)
T MySet<T>::getSmallest() const{
    SetNode<T>* current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current->data;
}

//template <class T>
//void MySet<T>::intersectionHelper(SetNode<T>* curNode) const{
//    if(curNode == nullptr){
//        return;
//    }
//    else{
//        intersectionHelper(curNode->left);
//        intersectionHelper(curNode->right);
//    }
//}

template <class T>
//generates a new set containing all the items that are in both
//  this set and another set
MySet<T> MySet<T>::intersectionWith(const MySet<T>& other) const{
    MySet<T> copy;

    SetNode<T>* temp = root;
    if(temp == nullptr){
        return copy;
    }else{
        while(temp != nullptr){
            if(other.contains(temp->data)){
                copy.add(temp->data);
                temp = temp->left;
            }
        }
    }

//    temp->left = intersectionWith(other);
//    temp->right = intersectionWith(other);

    return copy;
}

template <class T>
void MySet<T>::vecBuilder(SetNode<T>* curNode, vector<T>& theVec) const{
    if(curNode == nullptr)
        return;
    //in order traversal: left, self, right
    //don't print current, add to vector
    vecBuilder(curNode->left, theVec);
    theVec.push_back(curNode->data);
    vecBuilder(curNode->right, theVec);
}

template <class T>
vector<T> MySet<T>::toVector() const{
    vector<T> theVec;
    vecBuilder(root, theVec);
    return theVec;
}

template <class T>
//Returns a vector of items in the set that are >= start and < end
std::vector<T> MySet<T>::getRange(const T& startValue, const T& endValue) const{
    vector<T> vec = toVector();
    vector<T> range;
    for(auto it = vec.begin(); it != vec.end(); ++it){
        if(*it >= startValue && *it < endValue){
            range.push_back(*it);
        }
    }
    return range;
}



#endif // MYSET_H
