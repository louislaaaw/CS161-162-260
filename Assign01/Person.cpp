//----------------------------------------------------------
// CS260 Assignment 1 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#include "Person.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

bool operator==(const Person& p1, const Person& p2){
    if(p1.kNum == p2.kNum)
        return true;
    else
        return false;
}

//void check(Person* array, int low, int mid, int high, Person* temp){
//    int a = low;
//    int b = mid + 1;
//    int c = low;
//    while((a <= mid) && (b <= high)){
////        if(array[a].last == array[b].last){
////            if(array[a].first[0] > array[b].first[0]){
////                temp[c] = array[b];
////                temp[c + 1] = array[a];
////            }else{
////                temp[c] = array[a];
////                temp[c + 1] = array[b];
////            }
////            a++;
////            b++;
////            c += 2;
////        }
//        if(array[a].last[0] > array[b].last[0]){
//            temp[c] = array[b];
//            b++;
//            c++;
//        }
//        else{
//            temp[c] = array[a];
//            a++;
//            c++;
//        }
//    }
//}

//Sort a portion of array of Persons by zicode
//  Range of elements to sort is [start-end) (inclusive or start, exclusive of end)
void partialZipSort(Person* array, int start, int end){
    for(int i = start ; i <= end ; i++){
        for(int j = i + 1 ; j <= end ; j++){
            if(array[j].zipCode < array[i].zipCode){
                swap(array[i], array[j]);
            }
        }
    }

}

//Counts all the individuals in an array who have a given last name
int countLastName(const std::string& lastName, const Person* array, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        if (array[i].last == lastName){
            count++;
        }
    }
    return count;
}

void mergeFunc(Person* array, int low, int mid, int high, Person* temp) {
    //TODO - Fixme
    int a = low;
    int b = mid + 1;
    int c = low;
    //While either first sequence has an item left or second sequence has an item left
    while((a <= mid) && (b <= high)){
        if(array[a].last > array[b].last){
            temp[c] = array[b];
            b++;
            c++;
        }
        else{
            if(array[a].last == array[b].last){
                if(array[a].first > array[b].first){
                    temp[c] = array[b];
                    b++;
                    c++;
                }else{
                    temp[c] = array[a];
                    a++;
                    c++;
                }
            }else{
                temp[c] = array[a];
                a++;
                c++;
            }
        }
    }
    while(a <= mid){
        temp[c] = array[a];
        c++;
        a++;
    }
    while(b <= high){
        temp[c] = array[b];
        c++;
        b++;
    }
    //   Move smaller remaining item from front of first or second sequence
    //   to next available location in temp
    //Copy indexes from low-high from temp back to arr
    for(int i = low; i < c; i++){
        array[i] = temp[i];
    }
}

void mergeSortInternal(Person* array, int low, int high, Person* temp) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSortInternal(array, low, mid, temp);
    mergeSortInternal(array, mid+1, high, temp);
    mergeFunc(array, low, mid, high, temp);
}


//Sort an array of Persons so that they are alphabetized by last name
//  Individuals with the same last name should be ordered by first name
void nameSort(Person* array, int size){
    Person* temp = new Person[size];
    mergeSortInternal(array, 0, size - 1, temp);
    delete [] temp;
}

//Returns index of the first Person with a given lastName
//  If there is no one with that last name, return the size to indicate failure
int binaryFindFirstByLastName(const std::string& lastName, const Person* array, int size){
    int minLoc = 0;
    int maxLoc = size - 1;
    if(array[minLoc].last == lastName){
        return minLoc;
    }
    while(minLoc <= maxLoc){
        int midLoc = (minLoc + maxLoc) / 2;
        int PrevLoc = midLoc - 1;
        if((array[midLoc].last == lastName)){
            if ((maxLoc - midLoc == 1) || array[PrevLoc].last != array[midLoc].last){
                return midLoc;
            }else{
                maxLoc = midLoc - 1;
            }
        }
        else{
             if(array[midLoc].last < lastName){
                minLoc = midLoc + 1;
            }
            else{
                maxLoc = midLoc - 1;
            }
        }
    }
    return size;
}

//Returns index of the last Person with a given lastName
//  If there is no one with that last name, return the size to indicate failure
int binaryFindLastByLastName(const std::string& lastName, const Person* array, int size){
    int minLoc = 0;
    int maxLoc = size - 1;
    if(array[maxLoc].last == lastName){
        return maxLoc;
    }
    while(minLoc <= maxLoc){
        int midLoc = (minLoc + maxLoc) / 2;
        int NextLoc = midLoc + 1;
        if((array[midLoc].last == lastName)){
            if (((maxLoc - midLoc == 1) || array[NextLoc].last != array[midLoc].last)){
                return midLoc;
            }else{
                minLoc = midLoc + 1;
            }
        }
        else{
             if(array[midLoc].last < lastName){
                minLoc = midLoc + 1;
            }
            else{
                maxLoc = midLoc - 1;
            }
        }
    }
    return size;
}

//Counts all the individuals in an array who have a given last name.
//  Function ONLY works on arrays sorted by last name.
int countLastNameInSorted(std::string lastName, const Person* array, int size){
    int low = binaryFindFirstByLastName(lastName, array, size);
    int high = binaryFindLastByLastName(lastName, array, size);
    int num_sorted = high - low + 1;
    return num_sorted;
}
