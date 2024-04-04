﻿#include <iostream>
#include <string>
#define random(min, max) min + rand() % (max - min + 1)

using namespace std;

class Client;
class Bank;

class Client {
    friend class Bank;
private:
    static int lastId;
    int id;
    string firstName;
    string lastName;
    unsigned short age;
    string bankAccount;
    double balance = 0;

    Client() {};

    Client(string firstName, string lastName, 
        unsigned short age, 
        string bankAccount) {

        this->id = lastId++;
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->bankAccount = bankAccount;

    }

    void setFirstName(string fName) {
        this->firstName = fName;
    }
    
    string getFirstName() {
        return this->firstName;
    }

    void setLastName(string lName) {
        this->lastName = lName;
    }
    
    string getLastName() {
        return this->lastName;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return this->age;
    }

    string getBankAccount() {
        return this->bankAccount;
    }

    void setBalance(double balance) {
        this->balance = balance;
    }

    double getBalance() {
        return this->balance;
    }

    void showInfo() {
        cout << "ID: " << this->id << endl;
        cout << "First name: " << this->firstName << endl;
        cout << "Last name: " << this->lastName << endl;
        cout << "Age: " << this->age << endl;
        cout << "Bank account: " << this->bankAccount << endl;
        //cout << "Balance" << this->balance << endl;
        cout << "\n\n";
    }

};

int Client::lastId = 1;

class Bank {
private:
    string name;
    Client* clients = new Client[0];
    int size = 0;
public:
    Bank(string name) {
        this->name = name;
    }
    
    ~Bank() {
        delete[] clients;
    }

    void createClient(string firstName,
                      string lastName,
                      unsigned short age) {
        Client* buf = new Client[size + 1];
        for (int i = 0; i < size; i++)
        {
            buf[i] = clients[i];
        }
        delete[] clients;
        clients = buf;
        clients[size] = Client(firstName, lastName, age, createBankAccount());
        size++;
    }

    void showClients() {
        for (int i = 0; i < size; i++)
        {
            clients[i].showInfo();
        }
    }

private:
    string createBankAccount() {
        string bankAccount;
        do {
            bankAccount = "";
            bankAccount += to_string(random(1000, 9999));
            bankAccount += to_string(random(1000, 9999));
        } while (checkBankAccount(bankAccount));

        return bankAccount;
    }

    bool checkBankAccount(string bankAccount) {
        for (int i = 0; i < size; i++)
        {
            if (clients[i].getBankAccount() == bankAccount) return true;
        }
        return false;
    }

};


int main()
{
    srand(time(NULL));
    Bank bank("NYBank");
    for (int i = 0; i < 200; i++)
    {
        bank.createClient("John", "Smith", 25);
    }
    bank.showClients();

    
}