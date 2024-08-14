#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if the username and password are correct
bool authenticate(string username, string password) {
    ifstream infile("credentials.txt"); 
    string storedUsername, storedPassword;

   
    while (infile >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            infile.close();
            return true; // Authentication successful
        }
    }

    
    infile.close();

    return false; // Authentication failed
}

// Function to check if the username exists
bool userExists(string username) {
    ifstream infile("credentials.txt"); 
    string storedUsername, storedPassword;

    
    while (infile >> storedUsername >> storedPassword) {
        if (username == storedUsername) {
            infile.close();
            return true; 
        }
    }

    
    infile.close();

    return false; 
}

// Function to register a new user
bool registerUser(string username, string password) {
    ofstream outfile("credentials.txt", ios::app); 

    
    if (userExists(username)) {
        outfile.close();
        return false; // User already exists, registration failed
    }

    
    outfile << username << " " << password << endl;

    
    outfile.close();

    return true; // Registration successful
}

int main() {
    string username, password;

    
    while (true) {
    
        cout << "\n\n\n**** Welcome to Login Portal !!! ****\n\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "\nChoose an option: ";
        int option;
        cin >> option;

    
        switch (option) {
            case 1:
                // Login
                cout << "\n\nEnter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                // Authenticate the user
                if (authenticate(username, password)) {
                    cout << "\n\nLogin successful! Welcome, " << username << "!" << endl;
                } else {
                    cout << "\n\nIncorrect username or password. Please try again." << endl;
                }
                break;
            
            case 2:
                // Registration
                cout << "\n\nEnter a new username: ";
                cin >> username;
                cout << "Enter a new password: ";
                cin >> password;

           
                if (registerUser(username, password)) {
                    cout << "\n\nRegistration successful! Welcome, " << username << "!" << endl;
                } else {
                    cout << "\n\nUsername already exists. Please choose a different username." << endl;
                }
                break;
            
            case 3:
                // Exit the program
                cout << "Thank You\n";
                return 0;
            
            default:
                cout << "\n\nInvalid option. Please choose either 1, 2, or 3." << endl;
        }
    }

    return 0;
}
