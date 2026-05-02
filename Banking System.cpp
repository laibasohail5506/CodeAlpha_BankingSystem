#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string date;
    Transaction(string t, double a, string d) : type(t), amount(a), date(d) {}
};

class Account {
private:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(string accNum) : accountNumber(accNum), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount, "2026-05-02"));
        cout << "Deposited: Rs." << amount << endl;
    }

    bool withdraw(double amount) {
        if(amount > balance) {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount, "2026-05-02"));
        cout << "Withdrawn: Rs." << amount << endl;
        return true;
    }

    void showBalance() const {
        cout << "Account: " << accountNumber << " | Balance: Rs." << fixed << setprecision(2) << balance << endl;
    }

    void showTransactions() const {
        cout << "\nTransaction History:\n";
        for(const auto& t : transactions) {
            cout << t.date << " | " << t.type << " | Rs." << t.amount << endl;
        }
    }
};

int main() {
    string name, accNum;
    cout << "=== Banking System ===\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accNum;

    Account acc(accNum);
    int choice;
    double amount;

    while(true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Transaction History\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount: ";
                cin >> amount;
                acc.deposit(amount);
                break;
            case 2:
                cout << "Enter amount: ";
                cin >> amount;
                acc.withdraw(amount);
                break;
            case 3:
                acc.showBalance();
                break;
            case 4:
                acc.showTransactions();
                break;
            case 5:
                cout << "Thank you for using our bank!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}