#include <bits/stdc++.h>
using namespace std;

int main() {
    char board[3][3]{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char player_x = 'x';
    const char player_o = 'o';
    char current_player = player_x;
    char winner = ' ';
    int r = -1 , c = -1;

    for (int i = 0 ; i < 9 ; i++) {
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (winner != ' ') {
            break;
        }
        cout << "Current Player " << current_player << endl;
        while (true) {
            cout << "Enter r c from 0-2 for row and column: "<< endl;
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2) {
                cout << "Invalid input,Please try again!" << endl;
            }
            else if (board[r][c] != ' ') {
                cout << "Tile is full, Please try again!" << endl;
            }
            else {
                break;
            }
            r = -1, c = -1 ;
        }
        board[r][c] = current_player;
        current_player = (current_player == player_x) ? player_o : player_x;

        for (int r =0 ; r < 3; r++) {
            if (board[r][0] != ' ' && board[r][0] == board[r][1] && board[r][1]==board[r][2] ) {
                winner = board[r][0];
                break;
            }
        }
        for (int c =0 ; c < 3; c++) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c]==board[2][c] ) {
                winner = board[0][c];
                break;
            }
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1]==board[2][2] ) {
            winner = board[0][0];
        }
        else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1]==board[2][0] ) {
            winner = board[0][2];
        }
    }
    if (winner != ' ') {
        cout << "Player " << winner << " is the Winner!"<<endl;
    }
    else {
        cout << "Tie!" << endl;
    }
};