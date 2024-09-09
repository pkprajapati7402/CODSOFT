/*
build a simple console based Tic-Tac-Toe game that allows two palyers to play against eaach other.

*/
#include <iostream>
using namespace std;

char grid[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void display_grid() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool place_marker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (grid[row][col] != 'X' && grid[row][col] != 'O') {
        grid[row][col] = current_marker;
        return true;
    }
    return false;
}

int check_winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return current_player;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return current_player;
        }
    }

    // Diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return current_player;
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return current_player;
    }

    return 0;
}

void swap_player() {
    if (current_player == 1) {
        current_player = 2;
        current_marker = 'O';
    } else {
        current_player = 1;
        current_marker = 'X';
    }
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    if (current_marker == 'X' || current_marker == 'x') {
        current_marker = 'X';
    } else {
        current_marker = 'O';
    }

    display_grid();
    
    int winner = 0;
    for (int i = 0; i < 9; i++) {
        int slot;
        cout << "Player " << current_player << "'s turn. Enter your slot (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please try again.\n";
            i--;
            continue;
        }

        if (!place_marker(slot)) {
            cout << "Slot is occupied! Please try again.\n";
            i--;
            continue;
        }

        display_grid();

        winner = check_winner();
        if (winner == 1 || winner == 2) {
            cout << "Player " << winner << " wins the game!\n";
            break;
        }

        swap_player();
    }

    if (winner == 0) {
        cout << "It's a tie!\n";
    }
}

int main() {
    game();
    return 0;
}
