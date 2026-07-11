#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Account {
public:
    int accountNumber;
    string name;
    double balance;

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin ,name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }
};


vector<Account> accounts;


void saveData() {
    ofstream file("bank.txt");

    for(auto acc : accounts) {
        file << acc.accountNumber << " "
             << acc.name << " "
             << acc.balance << endl;
    }

    file.close();
}


void loadData() {

    ifstream file("bank.txt");

    Account acc;

    while(file >> acc.accountNumber >> acc.name >> acc.balance) {
        accounts.push_back(acc);
    }

    file.close();
}


void createNewAccount() {

    Account acc;

    acc.createAccount();

    accounts.push_back(acc);

    saveData();

    cout << "\nAccount Created Successfully\n";
}


void deposit() {

    int number;
    double amount;

    cout << "Enter Account Number: ";
    cin >> number;


    for(auto &acc : accounts) {

        if(acc.accountNumber == number) {

            cout << "Enter Amount: ";
            cin >> amount;

            acc.balance += amount;

            saveData();

            cout << "Money Deposited Successfully\n";
            return;
        }
    }

    cout << "Account Not Found\n";
}



void withdraw() {

    int number;
    double amount;

    cout << "Enter Account Number: ";
    cin >> number;


    for(auto &acc : accounts) {

        if(acc.accountNumber == number) {

            cout << "Enter Amount: ";
            cin >> amount;


            if(acc.balance >= amount) {

                acc.balance -= amount;

                saveData();

                cout << "Withdraw Successful\n";
            }
            else {
                cout << "Insufficient Balance\n";
            }

            return;
        }
    }

    cout << "Account Not Found\n";
}



void showAccount() {

    int number;

    cout << "Enter Account Number: ";
    cin >> number;


    for(auto acc : accounts) {

        if(acc.accountNumber == number) {

            acc.displayAccount();
            return;
        }
    }

    cout << "Account Not Found\n";
}



void showAllAccounts() {

    for(auto acc : accounts) {

        acc.displayAccount();
    }
}



int main() {

    loadData();

    int choice;


    do {

        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Search Account\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;


        switch(choice) {

            case 1:
                createNewAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                showAccount();
                break;

            case 5:
                showAllAccounts();
                break;

            case 6:
                cout << "Thank You!";
                break;

            default:
                cout << "Invalid Choice";
        }


    } while(choice != 6);


    return 0;
}