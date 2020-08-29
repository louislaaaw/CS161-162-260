//----------------------------------------------------------
// CS260 Assignment 3 Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Stack.h"

using namespace std;

int main()
{
   ifstream inFile("Document.html");
   if( !inFile.is_open() ) {
      cout << "Error opening file" << endl;
      return 1;
   }
   Stack<string> s1;
//   Stack<string> start;
//   Stack<string> end;
//   Stack<string> word;
   while(!inFile.eof()){
       string temp;
       inFile >> temp;
       s1.push(temp);
   }
   Stack<string> s2;
   vector<string> tag;
   vector<string> endtag;
   vector<string> word;
   while(!s1.isEmpty()){
       string temp = s1.pop();
       s2.push(temp);
   }
   while(!s2.isEmpty()){
       string temp = s2.pop();
       if(temp.at(0) != '<'){
           word.push_back(temp);
       }
       cout << temp << " ";
       if(temp.at(0) == '<'){
           if(temp.at(1) == '/'){
               break;
           }
           else{
               continue;
           }
       }else{
           break;
       }
   }
    cout << endl;
}
