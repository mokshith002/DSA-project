#include <bits/stdc++.h>
#include "login.h"
#include "checkout.h"

using namespace std;

int main(){
    // string user = login();
    // string year = user.substr(1, 4);
    string year = "2021";
    registration(year);
    while (!displayCart()) {
        registration(year);
    }
    getchar();

    return 0;
}