#include<bits/stdc++.h>

using namespace std;

map<string, string> users;

bool userRegister(string username, string password){
    if(users.count(username)){
        cout << "Username already exists\n";
        return false;
    }
    users[username] = password;
    cout << "Successfully registered\n";
    return true;
}

bool validate(string username, string password){
    if(!users.count(username)){
        cout << "User does not exist\n";
        return false;
    }
    else if(users[username] != password){
        cout << "Wrong password\n";
        return false;
    }
    cout << "Login successful\n";
    return true;
}