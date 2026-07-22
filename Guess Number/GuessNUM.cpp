#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void playGame() {

    int low, high;

    cout << "\n===== GUESS THE NUMBER =====\n";

    cout << "Enter Minimum Range: ";
    cin >> low;

    cout << "Enter Maximum Range: ";
    cin >> high;

    while (low >= high) {
        cout << "\nInvalid Range!\n";
        cout << "Enter Minimum Range: ";
        cin >> low;
        cout << "Enter Maximum Range: ";
        cin >> high;
    }

    int secret = low + rand() % (high - low + 1);

    int guess;
    int attempts = 0;

    cout << "\nI have selected a number between "
         << low << " and " << high << ".\n";

    while (true) {

        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess == secret) {
            cout << "\nCorrect!!\n";
            break;
        }
        else if (guess < secret) {
            cout << "Too Low!\n";
        }
        else {
            cout << "Too High!\n";
        }
    }

    cout << "\nNumber = " << secret << endl;
    cout << "Attempts = " << attempts << endl;

    int score = 100 - (attempts - 1) * 10;

    if (score < 10)
        score = 10;

    cout << "Score = " << score << "/100\n";
}

int main() {

    srand(time(0));

    int choice;

    do {

        cout << "\n=============================\n";
        cout << "     GUESS NUMBER GAME\n";
        cout << "=============================\n";

        cout << "1. Play Game\n";
        cout << "2. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            playGame();
            break;

        case 2:
            cout << "\nThanks for Playing!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 2);

    return 0;
}
