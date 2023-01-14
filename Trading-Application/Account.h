#pragma once
#include <iostream>
#include <vector>
class Account {
private:
    int dogecoin, balance;
    int bitcoin;
    int deposit, withdraw;
    int total_equity = 100;
    int predict;
    int dogecoin_value;
    int bitcoin_value;
    int crypto_invest;
    int crypto_return;

    vector<pair<string, int> > transactions;

public:
    bool Deposit(int money)
    {
        deposit += money;
        balance += money;
        transactions.push_back({ "Deposit:", money });
    }

  
    void Get_account_information()
    {

        cout << "Money Details:\n";
        cout << "Bank Balance:" << balance << endl;
        cout << "Dogecoin:" << dogecoin << endl;
        cout << "Bitcoin:" << bitcoin << endl;
    }

    bool Withdraw(int money)
    {
        if (money > balance) {
            return false;
        }

        withdraw += money;
        balance -= money;
        transactions.push_back({ "Withdraw:", money });
        return true;
    }

    bool buy_crypto()
    {
        int option;
        cout << "Want to purchase dogecoin press 1 else "
            "for bitcoin press 2\n";
        cin >> option;

        if (total_equity != 0) {
            srand(time(NULL));
            int luck = rand();

            // Checking if random number is divisible by
            // 251 to check (random case for buying  crypto
            // used)
            if (luck % 251 == 0) {
                if (option == 1) {
                    dogecoin += 1;
                    balance -= dogecoin_value;
                    crypto_invest
                        += (dogecoin)*dogecoin_value;
                }
                else {
                    bitcoin += 1;
                    balance -= bitcoin_value;
                    crypto_invest += bitcoin_value;
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }

        return true;
    }

    bool sell_crypto()
    {
        int option;
        cout << "Want to sell dogecoin press 1 else for "
            "bitcoin press 2\n";
        cin >> option;

        if (option == 2) {
            if (bitcoin == 0)
                return false;
            crypto_return += bitcoin_value;
            balance += bitcoin_value;
            transactions.push_back(
                { "Bitcoin Sold:", bitcoin_value });
            bitcoin -= 1;
        }
        else {
            if (dogecoin == 0)
                return false;
            crypto_return += dogecoin_value;
            balance += dogecoin_value;
            transactions.push_back(
                { "Dogecoin Sold:", dogecoin_value });
            dogecoin -= 1;
        }

        return true;
    }

    void History()
    {
        cout << "Displaying All transactions\n";
        for (auto it : transactions) {
            cout << it.first << " " << it.second << endl;
        }

        char temp;
        cout << "Do you want to clear all transactions:";
        cin >> temp;

        int no = transactions.size();

        if (temp == 'Y') {
            transactions.clear();
            cout << "Total transactions cleared:" << no
                << endl;
        }
        else {
            cout << "Total transaction:" << no << endl;
        }
    }

    Account()
    {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;

        balance = 50000;
        dogecoin = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        dogecoin_value = 100;
        bitcoin_value = 500;
    }
};
