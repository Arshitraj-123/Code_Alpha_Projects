#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
public:
    string username;
    string password;

    User(string user, string pass)
        : username(user), password(pass) {}
};

bool registerUser(const User& user) {
    // Check if username already exists
    ifstream infile("database.txt");
    string line;
    while (getline(infile, line)) {
        if (line.substr(0, line.find(',')) == user.username) {
            cout << "Username already exists. Please choose a different username." << endl;
            return false;
        }
    }
    infile.close();

    // Save username and password to the file
    ofstream outfile("database.txt", ios::app);
    outfile << user.username << "," << user.password << endl;
    outfile.close();

    cout << "Registration successful!" << endl;
    return true;
}

bool loginUser(const User& user) {
    ifstream infile("database.txt");
    string line;
    while (getline(infile, line)) {
        string storedUsername = line.substr(0, line.find(','));
        string storedPassword = line.substr(line.find(',') + 1);

        if (storedUsername == user.username && storedPassword == user.password) {
            cout << "Login successful!" << endl;
            return true;
        }
    }
    infile.close();

    cout << "Invalid username or password." << endl;
    return false;
}

int main() {
    int choice;
    string username, password;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    User user(username, password);

    switch (choice) {
    case 1:
        registerUser(user);
        break;
    case 2:
        loginUser(user);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}
