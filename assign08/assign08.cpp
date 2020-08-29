#include <iostream>
#include <cassert>

using namespace std;

//void printTable(const char table[10][10]){
//    cout << "  ";
//    for(int i = 0; i < 10; i++){
//        cout << i << " ";
//    }
//    cout << endl;
//    for(int i = 0; i < 10; i++){
//        cout << i << " ";
//        for(int j = 0; j < 10; j++){
//            cout << table[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

void contaminatedLocation(char table[10][10], int xLoc, int yLoc){
    assert(xLoc != 0 && yLoc != 0);
    table[xLoc][yLoc] = 'O';
}

void wallLocation(char table[10][10], int xLoc, int yLoc){
    assert(table[xLoc][yLoc] != 'O');
    if((xLoc == 0) && (yLoc == 0)){
        return;
    }else{
        table[xLoc][yLoc] = '/';
    }
}

void contaminatedArea(char table[10][10], int xLoc, int yLoc){
    if(xLoc < 0 || yLoc < 0 || xLoc >= 10 || yLoc >= 10){
        return;
    }
    if(table[xLoc][yLoc] != '-' && table[xLoc][yLoc] != 'O' && table[xLoc][yLoc] != 'V'){
       return;
    }

    table[xLoc][yLoc] = '.';
    contaminatedArea(table, xLoc, yLoc - 1);
    contaminatedArea(table, xLoc, yLoc + 1);
    contaminatedArea(table, xLoc - 1, yLoc);
    contaminatedArea(table, xLoc + 1, yLoc);
    contaminatedArea(table, xLoc + 1, yLoc + 1);
    contaminatedArea(table, xLoc + 1, yLoc - 1);
    contaminatedArea(table, xLoc - 1, yLoc + 1);
    contaminatedArea(table, xLoc - 1, yLoc - 1);
}

bool safe(char table[10][10]){
    if(table[0][0] == 'V'){
        return true;
    }
    else{
        return false;
    }
}

int contaminatedAmount(char table[10][10], int xLoc, int yLoc){
    if(table[0][yLoc] == '.'){

    }
    int amount = 0;
    for(int i = xLoc; i >= 0; i--){
        for(int j = yLoc; j >= 0; j--){
            if(table[i][j] == '.'){
                amount++;
            }
        }
    }
    return amount;
}

int main()
{
    char tables[10][10] = { 'V','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'
                           ,'-','-','-','-','-','-','-','-','-','-'};
    int contaminatedX;
    int contaminatedY;
    cout << "Enter contaminated location (x,y): ";
    cin >> contaminatedX >> contaminatedY;
    contaminatedLocation(tables, contaminatedX, contaminatedY);
//    printTable(tables);
    int wallX = -1; int wallY = -1;
    while(wallX != 0 || wallY != 0){
        cout << "Enter wall locations (x,y): " << endl;
        cin >> wallX >> wallY;
        wallLocation(tables, wallX, wallY);
    }
//    printTable(tables);
    contaminatedArea(tables, contaminatedX, contaminatedY);
//    printTable(tables);
    if(safe(tables) == true){
        cout << "Safe!" << endl;
    }
    else{
        cout << "Not Safe!" << endl;
    }
    cout << "Contaminated area: " << contaminatedAmount(tables, 9, 9) << endl;


    return 0;
}
