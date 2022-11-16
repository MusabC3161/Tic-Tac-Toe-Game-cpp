#include <iostream>
#include <cstdlib>

using namespace std;

int Restart = 0;
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin() {
    if (square[1] == square[2] && square[2] == square[3]) {
        return 1;
    }
    else if (square[4] == square[5] && square[5] == square[6]) {
        return 1;
    }
    else if (square[7] == square[8] && square[8] == square[9]) {
        return 1;
    }
    else if (square[1] == square[4] && square[4] == square[7]) {
        return 1;
    }
    else if (square[2] == square[5] && square[5] == square[8]) {
        return 1;
    }
    else if (square[3] == square[6] && square[6] == square[9]) {
        return 1;
    }
    else if (square[1] == square[5] && square[5] == square[9]) {
        return 1;
    }
    else if (square[3] == square[5] && square[5] == square[7]) {
        return 1;
    }
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
        && square[4] != '4' && square[5] != '5' && square[6] != '6'
        && square[7] != '7' && square[8] != '8' && square[9] != '9')
    {
        return 0;
    }
    else {
        return -1;
    }
}

void board() {

    //Every time we make a move, we call this function in order to properly set the game board

    system("cls");
    cout << "\n\n\tTic Tac Toe Game \n\n";
    cout << endl;

    cout << "Player 1(X) - Player 2(O)" << endl << endl;
    cout << endl;

    cout << "     |     |    " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |   " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |   " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |   " << endl;

}

void restartRequest() {
    char input;
    cin >> input;

    // Reset the game and restart
    if (input == 'y') {
        square[0] = '0';
        square[1] = '1';
        square[2] = '2';
        square[3] = '3';
        square[4] = '4';
        square[5] = '5';
        square[6] = '6';
        square[7] = '7';
        square[8] = '8';
        square[9] = '9';
        Restart = 1;
    }

    // Close the Program
    else if (input == 'n') {
        return;
    }
}

//Main Logic of the Game
void engine() {

    int player = 1, i, choice;
    char mark;

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter the number: ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';

        //Set the Game Board
        if (choice == 1 && square[1] == '1') {
            square[1] = mark;
        }
        else if (choice == 2 && square[2] == '2') {
            square[2] = mark;
        }
        else if (choice == 3 && square[3] == '3') {
            square[3] = mark;
        }
        else if (choice == 4 && square[4] == '4') {
            square[4] = mark;
        }
        else if (choice == 5 && square[5] == '5') {
            square[5] = mark;
        }
        else if (choice == 6 && square[6] == '6') {
            square[6] = mark;
        }
        else if (choice == 7 && square[7] == '7') {
            square[7] = mark;
        }
        else if (choice == 8 && square[8] == '8') {
            square[8] = mark;
        }
        else if (choice == 9 && square[9] == '9') {
            square[9] = mark;
        }

        // Check for invalid inputs
        else {
            cout << "Invalid Move!";
            player--;
            cin.ignore();
            cin.get();
            return;
        }

        i = checkwin();
        player++;

    } while (i == -1);
    board();

    // If one of the players had won, write it on the console and ask the player if he wants to play again
    if (i == 1) {

        cout << "\aCongratulations! Player " << --player << " Wins!" << endl;
        cout << "Do you want to play again? (y/n) ";
    
        restartRequest();
    }

    // If it's a draw, ask the player to play again
    else {
        cout << "\aGame Draw!";
        restartRequest();
    }
    //Check if user restarted the game
    if (Restart == 1) {
        Restart = 0;
        engine();
    }
    cin.ignore();
    cin.get();
    return;
}


int main() {
    engine();
}

