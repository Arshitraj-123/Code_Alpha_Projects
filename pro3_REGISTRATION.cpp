#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(const string& username) 
{
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() 
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    
    if (userExists(username)) 
    {
        cout << "Username already exists. Try a different one.\n";
        return;
    }
    
    cout << "Enter password: ";
    cin >> password;
    
    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    
    cout << "Registration successful!\n";
}

bool loginUser() 
{
    string username, password, storedUser, storedPass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream file(username + ".txt");
    if (!file) 
    {
        cout << "User not found. Please register first.\n";
        return false;
    }
    
    getline(file, storedUser);
    getline(file, storedPass);
    file.close();
    
    if (storedUser == username && storedPass == password) 
    {
        cout << "Login successful!\n";
        return true;
    } else 
    {
        cout << "Invalid credentials. Try again.\n";
        return false;
    }
}

void resetPassword() 
{
    string username, newPassword;
    cout << "Enter your username: ";
    cin >> username;
    
    if (!userExists(username)) 
    {
        cout << "User not found. Please register first.\n";
        return;
    }
    
    cout << "Enter new password: ";
    cin >> newPassword;
    
    ofstream file(username + ".txt");
    file << username << endl << newPassword;
    file.close();
    
    cout << "Password reset successful!\n";
}

int main() {
    int choice;
    
    while (true)
    {
        cout << "\n1. Register\n2. Login\n3. Reset Password\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                resetPassword();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}