//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "IndexRecord.h"

#include <iostream>

using namespace std;

//--------------------------------------------------
// IndexLocation Implemenetations
//--------------------------------------------------

IndexLocation::IndexLocation(int pageNumber, int wordNumber)
{
    pageNum = pageNumber;
    wordNum = wordNumber;
}

bool operator<(const IndexLocation& loc1, const IndexLocation& loc2) {
    if( (loc1.pageNum < loc2.pageNum) ||
        (loc1.pageNum == loc2.pageNum && loc1.wordNum < loc2.wordNum) )
    {
        return true;
    }
    return false;
}

bool operator==(const IndexLocation& loc1, const IndexLocation& loc2) {
    return loc1.pageNum == loc2.pageNum &&
            loc1.wordNum == loc2.wordNum;
}

std::ostream& operator<<(std::ostream& theStream, const IndexLocation& loc) {
   theStream << loc.pageNum << "-" << loc.wordNum;
   return theStream;
}


//--------------------------------------------------
// IndexRecord Implemenetations
//--------------------------------------------------


IndexRecord::IndexRecord() {
    word = "?";
}

IndexRecord::IndexRecord(const std::string& wordVal) {
    word = wordVal;
}

std::ostream& operator<<(std::ostream& theStream, const IndexRecord& r) {
   theStream << r.word << " : ";
   for(const IndexLocation& loc : r.locations)
      theStream << loc << " ";
   return theStream;
}


//TODO  ---  addLocation & hasLocation

//Add an IndexLocation to the record
// Does NOT check for duplicate records
void IndexRecord::addLocation(const IndexLocation& loc){
    locations.push_back(loc);
}

//Returns true if the record contains the indicated location
bool IndexRecord::hasLocation(const IndexLocation& loc) const{
    for(unsigned int i = 0; i < locations.size(); i++){
        if(locations.at(i) == loc){
            return true;
        }
    }
    return false;
}

