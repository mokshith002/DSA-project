#include <bits/stdc++.h>

using namespace std;

map<string, string> users;

bool userRegister(string username, string password)
{
    if (users.count(username))
    {
        cout << "Username already exists\n";
        return false;
    }
    users[username] = password;
    cout << "Successfully registered\n";
    return true;
}

bool validate(string username, string password)
{
    if (!users.count(username))
    {
        cout << "User does not exist\n";
        return false;
    }
    else if (users[username] != password)
    {
        cout << "Wrong password\n";
        return false;
    }
    cout << "Login successful\n";
    return true;
}

string login()
{
    cout << "Welcome to Course Registration!\n\n\n";
    while (true)
    {
        cout << "\n";
        cout << "1. Register\n"
             << "2. Login\n"
             << "Enter your choice -";
        int choice;
        cin >> choice;
        if (choice != 1 and choice != 2)
        {
            cout << "Invalid choice!\n";
        }
        else
        {
            string username, password;
            cout << "Enter username - ";
            cin >> username;
            cout << "Enter password - ";
            cin >> password;
            if (choice == 1)
            {
                userRegister(username, password);
            }
            else if (choice == 2)
            {
                if (validate(username, password))
                    return username;
            }
        }
    }
}
