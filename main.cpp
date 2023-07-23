#include <iostream>
#include <stdlib.h>
using namespace std;

int x,y;

bool turn = 1;
bool game_over = 0;

char grid[3][3] = {
    {'.','.','.'},
    {'.','.','.'},
    {'.','.','.'}
};

void show(char grid[3][3]){
    cout << "\n";
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkRows(char grid[3][3]){
    for (int i=0; i<3; i++){
        char ini = grid[i][0];
        if (ini == '.') break;

        for (int j=1; j<3; j++){
            if (grid[i][j] != ini){
                break;
            }
            else if (j == 2){
                return 1;
            }
        }
    }
    return 0;
}

bool checkCols(char grid[3][3]){
    for (int i=0; i<3; i++){
        char ini = grid[0][i];
        if (ini == '.') break;

        for (int j=1; j<3; j++){
            if (grid[j][i] != ini){
                break;
            }
            else if (j == 2){
                return 1;
            }
        }
    }
    return 0;
}

bool checkDiag(char grid[3][3]){
    for (int i=1; i<3; i++){
        char ini = grid[0][0];
        if (ini == '.') break;

        if (grid[i][i] != ini){
            break;
        }
        else if (i == 2){
            return 1;
        }
    }
    return 0;
}

int main(){

    while (!game_over){
        show(grid);

        if (turn)
            cout << "\nX's turn: ";
        else
            cout << "\nO's turn: ";

        cin >> x >> y;

        grid[x][y] = turn ? 'X' : 'O';

        if (checkRows(grid) || checkCols(grid) || checkDiag(grid)){
            show(grid);
            game_over = 1;
            cout << (turn ? 'X' : 'O') << " won.\n";
        }

        turn = !turn;
    }
}