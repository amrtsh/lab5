#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class BankAccount {
private:
    int m_id;
    string m_owner_name;
    double m_balance;

public:
    BankAccount(int id, string owner_name, double balance) : m_id(id), m_owner_name(owner_name), m_balance(balance) {
    }

    void showAccount() {
        cout<<"id: "<<m_id<<"\n"<<"Owner: "<<m_owner_name<<"\n"<<"Balance: "<<m_balance<<"\n";
    }

    void addBalance(double a)
    {
        m_balance += a;
    }

    double reduceBalance(double a)
    {
        if ((m_balance - a) >= 0)
        {
            m_balance -= a;

        }
        else
        {
            a = m_balance;
            m_balance = 0;
        }
        return a;
    }

    int getId(){return m_id;}
    int getBalance(){return m_balance;}

};


bool compareAccount(BankAccount *a1, BankAccount *a2)
{
    return (a1->getBalance() > a2->getBalance());
}

class Bank {
private:
    string m_name;
    std::vector<BankAccount *> m_accounts;

public:
    Bank(string name) : m_name(name) {}

    void add(BankAccount *account) {
        m_accounts.push_back(account);
    }

    void remove(int id) {
        for(int i = 0; i < m_accounts.size(); i++)
        {
            if (m_accounts[i]->getId() == id)
            {
                m_accounts.erase(m_accounts.begin() + i);
            }
        }
    }

    void sorting() {
        sort(m_accounts.begin(), m_accounts.end(), compareAccount);
    }

    void print_accounts() {
        for (auto obj: m_accounts)
            obj->showAccount();
        cout<<endl;
    }

};


int main() {
    Bank privatBank{"My bank"};

    BankAccount account1{1, "Dima", 1000};
    BankAccount account2{2, "Igor", 3000.5};
    BankAccount account3{3, "Ivan", 10};


    privatBank.add(&account1);
    privatBank.add(&account2);
    privatBank.add(&account3);

    account1.showAccount();
    account1.addBalance(10.5);
    account1.showAccount();

    account2.reduceBalance(100);
    account2.showAccount();


    privatBank.print_accounts();

    privatBank.sorting();

    privatBank.print_accounts();

    privatBank.remove(3);

    privatBank.print_accounts();

    return 0;
}