/**
  @author (Louis)YunHo Law
  @brief Assignment 1 part 2
  */
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TicTacToe{
private:
    char currentPlayer;
    char board[3][3];

public:
    TicTacToe(){
        currentPlayer = 'X';
        board[0][0] = '-';
        board[0][1] = '-';
        board[0][2] = '-';
        board[1][0] = '-';
        board[1][1] = '-';
        board[1][2] = '-';
        board[2][0] = '-';
        board[2][1] = '-';
        board[2][2] = '-';
    }

    void print();
    char getCurrentPlayer();
    char getWinner();
    bool isDone();
    bool isValidMove(int row, int col);
    void makeMove(int row, int col);
};

/**
 * @brief TicTacToe::print print out the table
 */
void TicTacToe::print(){
    cout << "  ";
    for(int a = 1; a <= 3; a++){
        cout << a << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; i++){
        cout << i + 1 << " ";
        for(int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief TicTacToe::getCurrentPlayer
 * @return the current player, "X" or "O"
 */
char TicTacToe::getCurrentPlayer(){
    return currentPlayer;
}

/**
 * @brief TicTacToe::getWinner
 * @return which player won or tie
 */
char TicTacToe::getWinner(){
    bool X = ((board[0][0] == 'X')&&(board[0][1] == 'X')&&(board[0][2] == 'X')) ||
             ((board[1][0] == 'X')&&(board[1][1] == 'X')&&(board[1][2] == 'X')) ||
             ((board[2][0] == 'X')&&(board[2][1] == 'X')&&(board[2][2] == 'X')) ||
             ((board[0][0] == 'X')&&(board[1][0] == 'X')&&(board[2][0] == 'X')) ||
             ((board[0][1] == 'X')&&(board[1][1] == 'X')&&(board[2][1] == 'X')) ||
             ((board[0][2] == 'X')&&(board[1][2] == 'X')&&(board[2][2] == 'X')) ||
             ((board[0][0] == 'X')&&(board[1][1] == 'X')&&(board[2][2] == 'X')) ||
             ((board[0][2] == 'X')&&(board[1][1] == 'X')&&(board[2][0] == 'X')) ;
    bool O = ((board[0][0] == 'O')&&(board[0][1] == 'O')&&(board[0][2] == 'O')) ||
             ((board[1][0] == 'O')&&(board[1][1] == 'O')&&(board[1][2] == 'O')) ||
             ((board[2][0] == 'O')&&(board[2][1] == 'O')&&(board[2][2] == 'O')) ||
             ((board[0][0] == 'O')&&(board[1][0] == 'O')&&(board[2][0] == 'O')) ||
             ((board[0][1] == 'O')&&(board[1][1] == 'O')&&(board[2][1] == 'O')) ||
             ((board[0][2] == 'O')&&(board[1][2] == 'O')&&(board[2][2] == 'O')) ||
             ((board[0][0] == 'O')&&(board[1][1] == 'O')&&(board[2][2] == 'O')) ||
             ((board[0][2] == 'O')&&(board[1][1] == 'O')&&(board[2][0] == 'O')) ;
    if(X){
        return 'X';
    }
    else if(O){
        return 'O';
    }
    else{
        return '-';
    }
}

/**
 * @brief TicTacToe::isDone
 * @return the game is finished or not
 */
bool TicTacToe::isDone(){
    if ((getWinner() != '-')){
        return true;
    }
    else {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                bool good = (board[i][j] == 'X') || (board[i][j] == 'O');
                if (!good){
                    good = false;
                    return false;
                    break;
                }else if(good){
                    good = true;
                }
            }
        }
        return true;
    }
}

/**
 * @brief TicTacToe::isValidMove
 * @param row the row that players choose
 * @param col the col that players choose
 * @return if the box is available
 */
bool TicTacToe::isValidMove(int row, int col){
    if(board[row - 1][col - 1] == '-'){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief TicTacToe::makeMove
 * @param row player choice
 * @param col player choice
 */
void TicTacToe::makeMove(int row, int col){
    board[row - 1][col - 1] = currentPlayer;
    if(currentPlayer == 'X'){
        currentPlayer = 'O';
    }else{
        currentPlayer = 'X';
    }
}


#endif // TICTACTOE_H
