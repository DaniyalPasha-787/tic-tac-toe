#include <iostream>
using namespace std;
char b[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void printboard() {
    cout << " " << b[1] << " | " << b[2] << " | " << b[3] << " \n";
    cout << "---|---|---\n";
    cout << " " << b[4] << " | " << b[5] << " | " << b[6] << " \n";
    cout << "---|---|---\n";
    cout << " " << b[7] << " | " << b[8] << " | " << b[9] << " \n";
}
int checkwin() {
    for (int i = 1; i <= 7; i += 3) {
        if (b[i] == b[i + 1] && b[i + 1] == b[i + 2])
            return 1;
    }
    for (int i = 1; i <= 3; i++) {
        if (b[i] == b[i + 3] && b[i + 3] == b[i + 6])
            return 1;
    }
    if ((b[1] == b[5] && b[5] == b[9]) || (b[3] == b[5] && b[5] == b[7]))
        return 1; 
    return 0;       
}
int aiMove() {
    return rand() % 9 + 1; 
}
int main() {
    int player = 1 , choice , s = 1;
    int gamestatus = 0; 
    do {
        printboard();
        player = (player % 2) ? 1 : 2;

        if (player == 1) {
            cout << "Player 1, enter a number: ";
            cin >> choice;
        } else {
        	cout << "AI (Player 2) is making a move...\n";
            choice = aiMove();
        }
        char mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && b[choice] == (choice + '0')) {
            b[choice] = mark;
            gamestatus = checkwin();
            player++;
            s++;
        } else {
            cout << endl << "Invalid move. Try again.\n";
        }
        if(s>9)
        break;
    } while (gamestatus == 0);
    printboard();
    if (gamestatus == 1) {
        cout << "Player " << (((player + 1) % 2) ? 1 : 2) << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }
    return 0;
}
