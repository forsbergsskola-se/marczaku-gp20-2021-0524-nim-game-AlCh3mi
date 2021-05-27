#include <iostream>

using namespace std;

enum BlockState { nought, available, cross };

BlockState Grid[3][3];

void PrintGrid();
void ResetBoard();
void Place(BlockState, int);
bool IsAvailable(int);
bool CheckWin();

int main() {

    ResetBoard();
    do{
        int input;
        do {
            cout << "Where would Player X like to place? index 1 - 9: ";
            cin >> input;
        } while (!(input > 0 && input < 10) || !IsAvailable(input));
        Place(cross, input);
        if(CheckWin()) {
            cout << "Player X wins.";
            break;
        }
        PrintGrid();
        do {
            cout << "Where would Player O like to place? index 1 - 9: ";
            cin >> input;
        } while (!(input > 0 && input < 10) || !IsAvailable(input));
        Place(nought, input);
        if(CheckWin()) {
            cout << "Player O wins.";
            break;
        }
        PrintGrid();
    }while(!CheckWin());
    PrintGrid();
    return 0;
}

bool CheckWin(){
    for (int i = 0; i < 3; ++i) {
        if((Grid[i][0] != available) && (Grid[i][0] == Grid[i][1]) && (Grid[i][0] == Grid[i][2])) return true;
        if((Grid[0][i] != available) && (Grid[0][i] == Grid[1][i]) && (Grid[0][i] == Grid[2][i])) return true;
    }
    if((Grid[0][0] != available) && Grid[0][0] == Grid[1][1] && Grid[0][0] == Grid[2][2]) return true;
    if((Grid[0][2] != available) && Grid[0][2] == Grid[1][1] && Grid[0][2] == Grid[2][0]) return true;
    return false;
}

void Place(BlockState newState, int index){
    if(IsAvailable(index))
        Grid[--index / 3][index % 3] = newState;

}

bool IsAvailable(int index){
    return (Grid[--index / 3][index % 3] == available);
}

void ResetBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Grid[i][j] = available;
        }
    }
}

void PrintGrid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            switch (Grid[i][j]) {

                case nought: cout << "O";
                    break;
                case available: cout << " ";
                    break;
                case cross: cout << "X";
                    break;
            }

            if(j != 2)
                cout << "|";
        }
        if(i != 2)
            cout << endl <<"-----" << endl;
    }
    cout << endl;
}


