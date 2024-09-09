/*
Develop a sytem to manage gboooks, borowers, and transactions in a library.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const string BOOK_FILE = "books.txt";
const string BORROWER_FILE = "borrowers.txt";
const string TRANSACTION_FILE = "transactions.txt";


void add_book() {
    ofstream file(BOOK_FILE, ios::app);
    if (file.is_open()) {
        string book_id, book_name, author;
        cout << "Enter book ID: ";
        cin >> book_id;
        cin.ignore(); 
        cout << "Enter book name: ";
        getline(cin, book_name);
        cout << "Enter author name: ";
        getline(cin, author);

        file << book_id << "," << book_name << "," << author << endl;
        file.close();
        cout << "Book added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void view_books() {
    ifstream file(BOOK_FILE);
    if (file.is_open()) {
        string line;
        cout << "\nBooks in Library:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}


void add_borrower() {
    ofstream file(BORROWER_FILE, ios::app);
    if (file.is_open()) {
        string borrower_id, borrower_name;
        cout << "Enter borrower ID: ";
        cin >> borrower_id;
        cin.ignore();
        cout << "Enter borrower name: ";
        getline(cin, borrower_name);

        file << borrower_id << "," << borrower_name << endl;
        file.close();
        cout << "Borrower added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void view_borrowers() {
    ifstream file(BORROWER_FILE);
    if (file.is_open()) {
        string line;
        cout << "\nBorrowers in Library:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}


void record_transaction() {
    ofstream file(TRANSACTION_FILE, ios::app);
    if (file.is_open()) {
        string borrower_id, book_id, transaction_type;
        cout << "Enter borrower ID: ";
        cin >> borrower_id;
        cout << "Enter book ID: ";
        cin >> book_id;
        cout << "Enter transaction type (issue/return): ";
        cin >> transaction_type;

        file << borrower_id << "," << book_id << "," << transaction_type << endl;
        file.close();
        cout << "Transaction recorded successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void view_transactions() {
    ifstream file(TRANSACTION_FILE);
    if (file.is_open()) {
        string line;
        cout << "\nTransactions in Library:" << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Add Borrower" << endl;
        cout << "4. View Borrowers" << endl;
        cout << "5. Record Transaction (Issue/Return Book)" << endl;
        cout << "6. View Transactions" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                view_books();
                break;
            case 3:
                add_borrower();
                break;
            case 4:
                view_borrowers();
                break;
            case 5:
                record_transaction();
                break;
            case 6:
                view_transactions();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
