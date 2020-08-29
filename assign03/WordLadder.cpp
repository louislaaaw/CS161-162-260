//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Queue.h"

using namespace std;

int main()
{
   string startWord, endWord;
   cout << "Enter the start word for your ladder:";
   cin >> startWord;
   cout << "Enter the end word for your ladder:";
   cin >> endWord;

   ifstream inFile("FiveLetterWords.txt");
   if( !inFile.is_open() ) {
      cout << "Error opening file" << endl;
      return 1;
   }
   vector<string> list;
   while(!inFile.eof()){
       string temp;
       getline(inFile, temp);
       list.push_back(temp);
   }
   Queue<string> todo;
   todo.enqueue(startWord);
   vector<string> used;
   int startWordlength = startWord.size();
   for(unsigned int i = 0; i < list.size(); i++){
       for(int r = 0; r < startWordlength; i++){
           if(list[i].at(r) == todo.front().at(r)){
               todo.enqueue(list[i]);
           }
       }
   }

}
