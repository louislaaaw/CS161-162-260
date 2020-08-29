/**
  * @file main.cpp
  * @author Andrew Scholer
  * @brief Main function for a console based tic-tac-toe game.
  *         Do NOT modify this file. You need to write TicTacToe.h/TicTacToe.cpp
  *         to work with this file as is.
  */
#include <iostream>
#include <iomanip>
#include <string>


#include "TicTacToe.h"

using namespace std;

//void TicTacToe::print(){
//    cout << "  ";
//    for(int a = 1; a <= 3; a++){
//        cout << a << " ";
//    }
//    cout << endl;
//    for(int i = 0; i < 3; i++){
//        cout << i + 1 << " ";
//        for(int j = 0; j < 3; j++){
//            cout << board[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

//char TicTacToe::getCurrentPlayer(){
//    return currentPlayer;
//}

//char TicTacToe::getWinner(){
//    bool X = ((board[0][0] == 'X')&&(board[0][1] == 'X')&&(board[0][2] == 'X')) ||
//             ((board[1][0] == 'X')&&(board[1][1] == 'X')&&(board[1][2] == 'X')) ||
//             ((board[2][0] == 'X')&&(board[2][1] == 'X')&&(board[2][2] == 'X')) ||
//             ((board[0][0] == 'X')&&(board[1][0] == 'X')&&(board[2][0] == 'X')) ||
//             ((board[0][1] == 'X')&&(board[1][1] == 'X')&&(board[2][1] == 'X')) ||
//             ((board[0][2] == 'X')&&(board[1][2] == 'X')&&(board[2][2] == 'X')) ||
//             ((board[0][0] == 'X')&&(board[1][1] == 'X')&&(board[2][2] == 'X')) ||
//             ((board[0][2] == 'X')&&(board[1][1] == 'X')&&(board[2][0] == 'X')) ;
//    if(X){
//        return 'X';
//    }
//    else{
//        return 'O';
//    }
//}

//bool TicTacToe::isDone(){

//    if ((getWinner() == 'X') || (getWinner() == 'O')){
//        return true;
//    }
//    else{
//        for(int i = 0; i < 3; i++){
//            for(int j = 0; j < 3; j++){
//                if (board[i][j] == '-'){
//                    break;
//                }
//            }
//        }
//        return false;
//    }
//}

//bool TicTacToe::isValidMove(int row, int col){
//    if (board[row - 1][col - 1] != '-'){
//        return true;
//    }
//    else{
//        return false;
//    }
//}

//void TicTacToe::makeMove(int row, int col){
//    board[row - 1][col - 1] = currentPlayer;
//    currentPlayer = 'O';
//}

int main()
{
    cout << "Tic Tac Toe v0.1" << endl << endl;

    //create a TicTacToe object
    TicTacToe theGame;

    //keep playing until someone wins or no more moves
    while(!theGame.isDone()) {
        //show current state
        theGame.print();

        //ask who the current player is
        char playerName = theGame.getCurrentPlayer();

        //get their move
        cout << playerName << "'s turn. Enter row (1-3) and column (1-3): " << endl;
        int row, col;
        cin >> row >> col;

        //only make the move if it is valid...
        if(theGame.isValidMove(row, col)) {
            theGame.makeMove(row, col);
            //makeMove should change turn to next player
        } else {
            cout << "Invalid move." << endl;
            //will redo this player's turn next time through loop
        }
    }

    char winner = theGame.getWinner();

    cout << winner << " wins!"<< endl;

    return 0;
}
