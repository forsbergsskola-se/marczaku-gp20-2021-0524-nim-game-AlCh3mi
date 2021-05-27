#include <iostream>
using namespace std;

class Nim{

public:
    Nim();
    Nim(int);
    int GetMatches();

    void TakeMatches(int);
    bool ValidEntry(int);
    void PlayerTurn();
    void ShowMatches();
    int AIDraw();
    bool AI = false;
private:
    int matches = 24;
    string DisplayMatches();
};

int main() {
    Nim nim(24);
    while(nim.GetMatches() > 0){

        cout << "PLAYER 1: "; //Player 1 Turn
        nim.PlayerTurn();
        if(nim.GetMatches() <= 0) { // Lose
            cout << "0 Matches left" << endl;
            cout << "Player 2 Wins!!";
            break;
        }
        nim.ShowMatches();

        cout << "PLAYER 2: "; //Player 2 Turn
        if(nim.AI){
            int AIDraw = nim.AIDraw();
            cout << "AI drew " << AIDraw << " matches.";
            nim.TakeMatches(AIDraw);
        }else
        {
            nim.PlayerTurn();
            if(nim.GetMatches() <= 0) { // Lose
                cout << "0 Matches left" << endl;
                cout << "Player 1 Wins!!";
                break;
            }
        }
        nim.ShowMatches();
    }
}

Nim::Nim(){
    cout << "New Nim Game Started vs AI. " << GetMatches() << " matches remaining!";
    AI = true;
}

Nim::Nim(int ma) {
    matches = ma;
    cout << "New Nim Game Started. " << GetMatches() << " matches remaining!" << endl;
    cout << DisplayMatches();
}

int Nim::GetMatches(){
    return matches;
}

void Nim::ShowMatches() {
    cout << DisplayMatches();
    cout << " - " << GetMatches() << " matches remaining!" << endl;
}

void Nim::PlayerTurn() {
    int playerInput;
    do{
        cout << "How many matches do you want to take: ";
        cin >> playerInput;
    }while(!ValidEntry(playerInput));
    TakeMatches(playerInput);
}

bool Nim::ValidEntry(int value) {
    return (value > 0 and value <= min(3, GetMatches()));
}

void Nim::TakeMatches(int value) {
    matches -= value;
}

int Nim::AIDraw() {
    int matchesToDraw;
    switch (matches) {
        default:matchesToDraw = rand() % 3 + 1; break;
        case 5: matchesToDraw = 1; break;
        case 4: matchesToDraw = 3; break;
        case 3: matchesToDraw = 2; break;
        case 2: matchesToDraw = 1; break;
        case 1: matchesToDraw = 1; break;
    }
    if(!ValidEntry(matchesToDraw)){
        cout << "AI Drew an invalid amount of matches";
        return 0;
    }
    return matchesToDraw;
}

string Nim::DisplayMatches(){
    string response = "";
    for (int i = 0; i < GetMatches(); i++) {
        response += "|";
    }
    return response;
}


