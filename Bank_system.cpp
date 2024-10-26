#include <iostream>
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string accountHolderName;
    double balance;
    Account* next;

    Account(int accNum, const string& name, double bal)
        : accountNumber(accNum), accountHolderName(name), balance(bal), next(nullptr) {}
};

class Bank {
private:
    Account* head;
    static int accountCounter;  

public:
    Bank() : head(nullptr) {}

    void createAccount(const string& name, double initialDeposit) {
        int accNum = ++accountCounter;  
        Account* newAccount = new Account(accNum, name, initialDeposit);
        newAccount->next = head;
        head = newAccount;
        cout << "Account created successfully for " << name << " with account number: " << accNum << "\n";
    }

    Account* findAccount(int accNum) {
        Account* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accNum) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void deposit(int accNum, double amount) {
        Account* acc = findAccount(accNum);
        if (acc) {
            acc->balance += amount;
            cout << "Deposited $" << amount << " to account number: " << accNum << "\n";
        } else {
            cout << "Account not found!\n";
        }
    }

    void withdraw(int accNum, double amount) {
        Account* acc = findAccount(accNum);
        if (acc && acc->balance >= amount) {
            acc->balance -= amount;
            cout << "Withdrew $" << amount << " from account number: " << accNum << "\n";
        } else {
            cout << "Insufficient funds or account not found!\n";
        }
    }

    void transfer(int fromAccNum, int toAccNum, double amount) {
        Account* fromAcc = findAccount(fromAccNum);
        Account* toAcc = findAccount(toAccNum);
        if (fromAcc && toAcc && fromAcc->balance >= amount) {
            fromAcc->balance -= amount;
            toAcc->balance += amount;
            cout << "Transferred $" << amount << " from account " << fromAccNum << " to account " << toAccNum << "\n";
        } else {
            cout << "Transfer failed: check account details and funds!\n";
        }
    }

    void displayAccounts() {
        Account* current = head;
        cout << "\nAccounts in the Bank:\n";
        while (current != nullptr) {
            cout << "Account Number: " << current->accountNumber 
                 << ", Holder Name: " << current->accountHolderName 
                 << ", Balance: $" << current->balance << "\n";
            current = current->next;
        }
    }

    ~Bank() {
        while (head != nullptr) {
            Account* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int Bank::accountCounter = 10000;

void displayMenu() {
    cout << "\n--- Banking System Menu ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Transfer\n";
    cout << "5. Display Accounts\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Bank bank;

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string accHolderName;
                double initialDeposit;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, accHolderName);
                cout << "Enter Initial Deposit Amount: ";
                cin >> initialDeposit;

                bank.createAccount(accHolderName, initialDeposit);
                break;
            }
            case 2: {
                int accNum;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;

                bank.deposit(accNum, amount);
                break;
            }
            case 3: {
                int accNum;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;

                bank.withdraw(accNum, amount);
                break;
            }
            case 4: {
                int fromAccNum, toAccNum;
                double amount;
                cout << "Enter From Account Number: ";
                cin >> fromAccNum;
                cout << "Enter To Account Number: ";
                cin >> toAccNum;
                cout << "Enter Amount to Transfer: ";
                cin >> amount;

                bank.transfer(fromAccNum, toAccNum, amount);
                break;
            }
            case 5:
                bank.displayAccounts();
                break;
            case 6:
                cout << "Exiting the system. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
