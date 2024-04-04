#include <iostream>

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

    Client(string firstName, string lastName, string bankAccount) {
        this->id = lastId++;
        this->firstName = firstName;
        this->lastName = lastName;
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

};


int main()
{
    
}