#include <iostream>
#include <stdlib.h>
using namespace std;

char grid[3][3] = {
    {'X','.','.'},
    {'.','.','.'},
    {'.','.','.'}
};

void show(char grid[3][3]){
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

int main(){
    cout << checkRows(grid);
}