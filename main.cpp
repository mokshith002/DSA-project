#include <bits/stdc++.h>
#include "login.h"
#include "checkout.h"


using namespace std;

int main(){

    string user = login();
    string year = user.substr(1, 4);
    registration(year);
    while (!displayCart()) {
        cout << "Press any key to go back to Registration\n";
        system("pause");
        registration(year);
        cout << "\n\n";
    }
    system("pause");

    return 0;
}