#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void display() {
    string disp = "\n=========================================================================================="
                 "\n\t   CCCCCCC       AAA       SSSSSSSSS   IIIIIIIII  NNN     NN    OOOOOOOO                "
                 "\n\t  CC            A   A      SS             III     NN NN   NN   OO      OO               "
                 "\n\t  CC           AAAAAAA     SSSSSSSSS      III     NN  NN  NN   OO      OO               "
                 "\n\t  CC          AA     AA           SS      III     NN   NN NN   OO      OO               "
                 "\n\t   CCCCCCC   AA       AA   SSSSSSSSS   IIIIIIIII  NN     NNN    OOOOOOOO                "
                 "\n===========================================================================================\n";

    for (int i = 0; i < disp.size(); i++) {
        Sleep(10);
        cout << disp[i];
    }
}

void rules() {
    system("cls");
    cout << "\n\n";
    cout << "\n\n========================================================================================\n\n";
    cout << "\t\t\t\tRULES OF THE GAME\n";
    cout << "\n========================================================================================\n\n";
    cout << "\tRULE - 1. Choose any number between 1 to 10\n";
    cout << "\tRULE - 2. If you win you will get 10 times of money you bet\n";
    cout << "\tRULE - 3. If you bet on wrong number you will lose your betting amount";
    cout << "\n\n========================================================================================\n\n";
}
int main() {
    bool flag = 0;
    display();
    string yourName; 
    int amount;
    char input;
    cout << "\nEnter your Name : ";
    getline(cin, yourName);
    cout << endl;

    cout << "Enter your amount balance in $ : ";
    cin >> amount;
    cout << endl;

    do {
        rules();
        // game code
        int deposit;
        label1:
            cout << "Enter amount you want to bet in $ : ";
            cin >> deposit;
            cout << endl;
            if (deposit > amount) {
                cout << "You don't have enough money in your balance.\n" << endl;
                goto label1;
            }

        int ball = rand() % 10 + 1;
        int guess;
        label2:
            cout << "Enter input method : " << endl;
            cout << "Press 1 if you want to input your guessing number where ball will stop " << endl;
            cout << "Press 2 if you think that the number where ball will stop is EVEN number " << endl;
            cout << "Press 3 if you think that the number where ball will stop is ODD number " << endl;
            cout << "\nEnter input : ";
            cin >> guess;
            cout << endl;

        if (guess == 1) {
            int number;
            cout << "Enter input guessing number in between 1-10  : ";
            cin >> number;
            cout << endl;
            if (guess == ball) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }

        else if (guess == 2) {
            if (ball % 2 == 0) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }

        else if (guess == 3) {
            if (ball % 2 != 0) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }
        else {
            cout << "Invalid input entered !!!!" << endl;
            cout << "Try something to input from 1 , 2 or 3\n" << endl;
            goto label2;
        }

        if (flag == 1) {
            cout << "Congratulations !!! " << endl;
            cout << "You win " << deposit * 10 << " $" << endl;
            amount += deposit * 10;
        }

        else {
            cout << "Sorry !! ";
            cout << "You lose " << deposit << " $" << endl;
            amount = amount - deposit;
        }

        cout << "\nWould you like to play again (y/n) : ";
        cin >> input;
        cout << endl;
        if (amount == 0) {
            cout << "You have not enough money to play." << endl;
            break;
        }
    } while (input != 'n');

    cout << "Heyy " << yourName << " !! , " << " you have " << amount << " $ left in your balance" << endl;
    cout << "\nThank you for playing with us!!" << endl;
    cout << "\n================================================================================\n" << endl;
}
