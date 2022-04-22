#include <bits/stdc++.h>
#include "login.h"
#include "checkout.h"

using namespace std;

int main(){

    string year = "2020";
    registration(year);
    while (!displayCart()) {
        registration(year);
    }
    getchar();

    return 0;
}