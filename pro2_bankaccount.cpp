#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a Transaction
class Transaction {
private:
    string type; // "Deposit", "Withdraw", "Transfer"
    double amount;
    string date;

public:
    Transaction(string t, double a, string d) : type(t), amount(a), date(d) {}

    void display() const {
        cout << "Type: " << type << ", Amount: " << amount << ", Date: " << date << endl;
    }
};

// Class to represent an Account
class Account {
private:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount, string date) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount, date));
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount, string date) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            transactions.push_back(Transaction("Withdraw", amount, date));
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    void transfer(Account &recipient, double amount, string date) {
        if (amount > balance) {
            cout << "Insufficient balance for transfer!\n";
        } else {
            balance -= amount;
            recipient.balance += amount;
            transactions.push_back(Transaction("Transfer to " + recipient.getAccountNumber(), amount, date));
            recipient.transactions.push_back(Transaction("Transfer from " + accountNumber, amount, date));
            cout << "Transfer successful. New balance: " << balance << endl;
        }
    }

    void displayTransactions() const {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        for (const auto &t : transactions) {
            t.display();
        }
    }
};

// Class to represent a Customer
class Customer {
private:
    string name;
    string customerId;
    vector<Account> accounts;

public:
    Customer(string n, string id) : name(n), customerId(id) {}

    void createAccount(string accNum, double initialBalance) {
        accounts.push_back(Account(accNum, initialBalance));
        cout << "Account created successfully.\n";
    }

    Account* getAccount(string accNum) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                return &acc;
            }
        }
        return nullptr;
    }

    void displayAccounts() const {
        cout << "Accounts for Customer " << name << " (ID: " << customerId << "):\n";
        for (const auto &acc : accounts) {
            cout << "Account Number: " << acc.getAccountNumber() << ", Balance: " << acc.getBalance() << endl;
        }
    }
};

// Main function to demonstrate the banking system
int main() {
    // Create customers
    Customer customer1("Ayan sharma", "C001");
    Customer customer2("Raman Bhalla", "C002");

    // Create accounts for customers
    customer1.createAccount("A1001", 1000.0);
    customer2.createAccount("A2001", 500.0);

    // Perform transactions
    Account *acc1 = customer1.getAccount("A1001");
    Account *acc2 = customer2.getAccount("A2001");

    if (acc1 && acc2) {
        acc1->deposit(500.0, "2023-10-01");
        acc1->withdraw(200.0, "2023-10-02");
        acc1->transfer(*acc2, 300.0, "2023-10-03");

        // Display account information
        customer1.displayAccounts();
        customer2.displayAccounts();

        // Display transaction history
        acc1->displayTransactions();
        acc2->displayTransactions();
    } else {
        cout << "Error: Account not found!\n";
    }

    return 0;
}
