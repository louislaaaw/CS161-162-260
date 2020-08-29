//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <functional>
#include <iostream>
#include <cassert>
#include <stdexcept>

#include "IndexMap.h"

using namespace std;

//handle resizing the hash table into a new array with twice as many buckets
void IndexMap::grow(){
    //temp copies of old array and size
    IndexRecord* oldData = buckets;
    int oldSize = numBuckets;

    //setup new storage
    numBuckets = oldSize * 2;
    buckets = new IndexRecord[numBuckets];
    for(int i = 0; i < numBuckets; i++){
        buckets[i].word = "?";
    }

    for(int i = 0; i < oldSize; i++){
        if(oldData[i].word != "?"){
            for(unsigned int v = 0; v < oldData[i].locations.size(); v++){
                IndexLocation loc = oldData[i].locations.at(v);
                add(oldData[i].word, loc.pageNum, loc.wordNum);
            }

        }

    }

    //delete old storage
    delete [] oldData;
}

//Get the location this key should be placed at.
//  Will either containt IndexRecord with that key or an empty IndexRecord
int IndexMap::getLocationFor(const std::string& key) const{
    hash<string> hasher;
    unsigned int hashValue = hasher(key);  //technicall type is size_t
    //return that mapped onto table
    return hashValue % numBuckets;
}

//Construct HashMap with given number of buckets
IndexMap::IndexMap(int startingBuckets){
    numBuckets = startingBuckets;
    keyCount = 0;
    buckets = new IndexRecord[startingBuckets];
    for(int i = 0; i < numBuckets; i++){
        buckets[i].word = "?";
    }
}

//Destructor
IndexMap::~IndexMap(){
    delete [] buckets;
}

//Copy constructor and assignment operators
//IndexMap::IndexMap(const IndexMap &other){
//    assert(0);
//}

//IndexMap& IndexMap::operator=(const IndexMap& other){
//    assert(0);
//}


//Returns true of indicated key is in the map
bool IndexMap::contains(const std::string& key) const{
    int bucketNumber = getLocationFor(key);

    //look for the value starting in that bucket - need to keep searching until
    // we find an empty bucket
    while(buckets[bucketNumber].word != "?") {
        if( buckets[bucketNumber].word == key ){
            return true;
        }
        bucketNumber = (bucketNumber + 1) % numBuckets;
    }
    //move to next bucket, wrap if necessary

    return false;
}

//Add indicated location to the map.
//  If the key does not exist in the map, add an IndexRecord for it
//  If the key does exist, add a Location to its IndexRecord
void IndexMap::add(const std::string& key, int pageNumber, int wordNumber){
    int bucketNumber = getLocationFor(key);
    IndexLocation loc(pageNumber, wordNumber);

        //find an empty location to insert value at
        while(buckets[bucketNumber].word != "?") {
            if( buckets[bucketNumber].word == key ){
                buckets[bucketNumber].addLocation(loc);
                return;
            }
            //move to next bucket, wrap if necessary
            bucketNumber = (bucketNumber + 1) % numBuckets;
        }

        buckets[bucketNumber].word = key;
        buckets[bucketNumber].addLocation(loc);
        keyCount++;
        //if more than half full, resize storage to be 2n+1 size
        if(keyCount > 0.5 * numBuckets){
            grow();
        }
}

//get number of keys contained in the map
int IndexMap::numKeys() const{
    return keyCount;
}

//print out the contents of the hash table
void IndexMap::print() const{
    for(int i = 0; i < numBuckets; i++){
        if(buckets[i].word != "?"){
            cout << buckets[i] << endl;
        }
    }
}

//get the IndexRecord associated with a particular word
IndexRecord IndexMap::get(const std::string& word) const{
    int bucketNumber = getLocationFor(word);
    while(buckets[bucketNumber].word != word){
        if(buckets[bucketNumber].word == word){
            break;
        }
        bucketNumber = (bucketNumber + 1) % numBuckets;
    }
    return buckets[bucketNumber];
}

//find all locations where one word is directly followed on the same page by a second
//  print them to cout
void IndexMap::findWordPairs(const std::string& key1, const std::string& key2) const{
    IndexRecord word1 = get(key1);
    IndexRecord word2 = get(key2);
    cout << key1 << " " << key2 << ": ";
    for(unsigned int n = 0; n < word1.locations.size(); n++){
        IndexLocation cur = word1.locations.at(n);
        for(unsigned int i = 0; i < word2.locations.size(); i++){
            IndexLocation cur1 = word2.locations.at(i);
            if(cur.pageNum == cur1.pageNum && cur1.wordNum - 1 == cur.wordNum){
                cout << cur << " & " << cur1 << ", ";
            }
        }
    }
}

//std::string IndexMap::getWord(int index) const{
//    return buckets[index].word;
//}

//returns the first word on the indicated page
std::string IndexMap::firstWordOnPage(int pageNumber) const{
    IndexLocation loc(pageNumber, 1);
    string word;
    for(int i = numBuckets - 1; i >= 0; i--){
        if(buckets[i].word == "?"){
            continue;
        }
        for(int v = buckets[i].locations.size() - 1; v >= 0; v--){
            if(buckets[i].locations.at(v) == loc){
                word = buckets[i].word;
                break;
            }
        }
    }
    return word;
}
