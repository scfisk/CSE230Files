#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayBalance(double balance) {

    cout << "Account balance: " << balance << endl;

}

double readBalance(string filename) {
    ifstream fin;

    fin.open(filename);

    if (fin.fail()) {
        cout << "Unable to open " << filename << endl;
        return 0.00;
    }
    double num;
    double balance;
    while (fin >> num) {
        balance = num;
    }

    fin.close();
     return balance;

}

double updateBalance(double balance) {

    double change;
    cout << "Change: $" << endl;
    cin >> change;

    return change + balance;
}

void writeBalance(double balance, string filename) {

    ofstream fout;

    fout.open(filename);

    if (!fout.fail()) {
        fout << balance << endl;

        cout << "Balance successfully written to " << filename << endl;
    }
    else {
        cout << "Unable to write balance to " << filename << endl;
    }

    fout.close();

}

int main() {

    string filename = "data.txt";

    double balance = readBalance(filename);
    displayBalance(balance);
    double newBalance = updateBalance(balance);
    displayBalance(newBalance);
    writeBalance(newBalance, filename);

    return 0;
}
