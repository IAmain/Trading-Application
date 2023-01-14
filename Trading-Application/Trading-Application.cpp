
#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
    Account person;
    int amount, choice;
    bool check;
    while (1) {

        cout << "  "
            "******************************************"
            "*****************************  \n";

        cout << endl;
        cout << "Press 1 if want to have your Account Info "
            << endl;
        cout << "Press 2 if want to Deposit your money "
            << endl;
        cout << "Press 3 if want to withdraw your money "
            << endl;
        cout << "Press 4 if want to know your history "
            << endl;
        cout << "Press 5 if want to know your Buy Crypto "
            << endl;
        cout << "Press 6 if want to know your Sell Crypto "
            << endl;
        cout << "Else press any invalid key for exit \n"
            << endl;

        cout << "  "
            "******************************************"
            "*****************************  \n";

        cin >> choice;
        int ans;

        switch (choice) {
        case 1:
            person.Get_account_information();
            break;

        case 2:
            cout << "Enter amount to deposit : ";
            cin >> amount;
            ans = person.Deposit(amount);
            if (ans)
                cout << "Successfully deposited money"
                << endl;
            else
                cout << "Failed\n";

            break;

        case 3:
            cout << "Enter amount to withdrawn : ";
            cin >> amount;
            person.Withdraw(amount);

            if (ans)
                cout << "Successfully withdrawn Amount"
                << endl;
            else
                cout << "Not Enough Balance\n";

            break;

        case 4:
            person.History();
            break;

        case 5:
            ans = person.buy_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Better Luck next time\n";
            break;

        case 6:
            ans = person.sell_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Not Enough Cryptocoins\n";
            break;

        default:
            exit(0);
            break;
        }
    }
}