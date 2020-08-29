//----------------------------------------------------------
// CS260 Assignment 2 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------
#ifndef ADDRESSARRAYLIST_H
#define ADDRESSARRAYLIST_H

#include "ArrayList.h"
#include "Address.h"

#include <iostream>


/**
 * @brief Outputs a range of addresses from an address list
 * @param list List to printListRange
 * @param startIndex index of first item to print
 * @param endIndex index of last item to print. If endIndex == -1 will print to end
 */
void printListRange(const ArrayList<Address>& list, int startIndex = 0, int endIndex = -1) {
    if(endIndex == -1)
        endIndex = list.listSize() - 1;
    for(int i = startIndex; i <= endIndex; i++) {
        std::cout << list.retrieveAt(i);
    }
}


/**
 * Template specialization for ArrayList of Addresses
 *   This is defining a combine that will ONLY work for an ArrayList<Address>
 *
 * @brief Move all items from otherList to the end of this List.
 * @param otherList List to be combined into this one. It should end up empty.
 *
 */
template <>
void ArrayList<Address>::combine(ArrayList<Address>& otherList) {
    for(int i = 0; i < otherList.listSize(); i++){
        insertEnd(otherList.retrieveAt(i));
    }
    otherList.clear();
}

/**
 * Template specialization for ArrayList of Addresses
 *   This is defining an extractAllMatches that will ONLY work for an ArrayList<Address>
 *
 * @brief Remove all items in which the state matches the itemToMatch.sate from the ArrayList and return them in a new ArrayList
 * @param itemToMatch All items whose state matches this Address' .state this value will be extracted
 * @return A new list containing the extracted items.
 *
 * NOTE: should extract items that have a matching .state, not just items that are ==
 *
 * Sample usage:
 * Address searchAddress;
 * searchAddress.state = "OR";
 * ArrayList<Address> oregonList = masterList.extractAllMatches(searchAddress);
 */
template <>
ArrayList<Address> ArrayList<Address>::extractAllMatches(const Address& itemToMatch) {
    //FIXME - returns empty list
    ArrayList<Address> newList;
    for(int i = 0; i < length; i++){
        if(list[i].state == itemToMatch.state){
            newList.insertEnd(list[i]);
            removeAt(i);
            i--;
        }
    }
    return ArrayList<Address>(newList);
}

#endif // ADDRESSARRAYLIST_H
