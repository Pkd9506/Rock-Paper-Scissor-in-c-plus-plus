#include <iostream>
#include <ctime>
#include <cstdlib>

void rules() {
    using namespace std;
    cout << "\nThe rules of the game 'Rock, paper, scissor' are very simple.\nThe rules are as follows:\n\n";
    cout << "1. Paper vs scissor = scissor wins.\n2. Paper vs rock = paper wins.\n3. Rock vs scissor = rock wins.\n";
}

char PlayerInput() {
    using namespace std;
    char player_input;
    cout << "Choose amongst rock(r), paper(p) or scissor(s).\n";
    cin >> player_input;
    cout << "You chose " << player_input << '\n';
    return player_input;
}

char ComputerInput() {
    using namespace std;
    srand(time(0));
    int num = rand() % 3; // should be 0, 1, or 2

    if (num == 0) {
        return 'r';
    }
    else if (num == 1) {
        return 'p';
    }
    else {
        return 's';
    }
}

int Results(char player_move, char computer_move) {
    // draw case
    if (player_move == computer_move) {
        return 0;
    }

    // lose cases
    else if (player_move == 's' && computer_move == 'r') {
        return -1;
    }
    else if (player_move == 'r' && computer_move == 'p') {
        return -1;
    }
    else if (player_move == 'p' && computer_move == 's') {
        return -1;
    }

    // win cases
    else if (player_move == 's' && computer_move == 'p') {
        return 1;
    }
    else if (player_move == 'r' && computer_move == 's') {
        return 1;
    }
    else if (player_move == 'p' && computer_move == 'r') {
        return 1;
    }
    return -2; // Invalid case
}

int main() {
    using namespace std;
    char rules_input;

    cout << "**********WELCOME TO THE GAME OF ROCK, PAPER, SCISSOR**********\n";
    cout << "Are you aware of the rules? 1. Yes (Y) 2. No (N)\n";
    cin >> rules_input;

    if (rules_input == 'N' || rules_input == 'n') {
        rules();
    }

    char computer_move = ComputerInput();
    char player_move = PlayerInput();

    cout << "Computer chose " << computer_move << '\n';

    int result = Results(player_move, computer_move);

    if (result == 0) {
        cout << "The game ended in a draw.\n";
    }
    else if (result == 1) {
        cout << "You won !!\n";
    }
    else if (result == -1) {
        cout << "You lost. :( \n";
    }
    else {
        cout << "An error occurred in the game.\n";
    }
}