#include<bits/stdc++.h>
#include "courses.h"
#include "login.h"

using namespace std;

struct cartItem{
    pair<int, int> timing;
    string classCode;
};

map<string, course> courses;
map<string, int> dayIndex = {{"M", 1}, {"T", 2}, {"W", 3}, {"Th", 4}, {"F", 5}, {"S", 6}};

vector<set<cartItem>> cart(6);

void registration(string year){
    courses = findCourses(year);
}

void addToCart(string class_code){
    course c = courses[class_code];
    for(auto d : c.days){
        cart[dayIndex[d]].insert({c.timing, class_code});
    }
}


void displayCourses(string code="all"){
    bool flag = true;
    while(flag){
        cout<< setw(7) << "Code"
            << setw(10) << "Course"
            << setw(10) << "Credits"
            << setw(10) << "Section"
            << setw(15) << "Instructor"
            << setw(10) << "Days"
            << setw(7) << "Start"
            << setw(5) << "End\n";


        for (auto crs : courses)
        {
            course c = crs.second;
            if (code != "all" && c.courseCode != code)
                continue;
            cout << endl;
            cout << setw(7) << crs.first;
            cout << setw(10) << c.courseCode << endl;
            cout << setw(10) << c.credits ;
            cout << setw(10) << c.section ;
            cout << setw(15) << c.instructor ;
            string ds;
            for(auto d : c.days) ds.append(d + " ");
            cout << setw(10) << ds;
            cout << setw(7) << c.timing.first ; 
            cout << setw(5) << c.timing.second ;
        }

        cout << endl << endl;
        cout <<"1. View all courses\n" 
            <<"2. Search by course code\n"
            <<"3. Enter class code to add to cart\n"
            <<"4. Go to checkout\n"
            <<"Enter you choice - ";
        int choice;
        cin >> choice;
        string class_code;
        switch (choice)
        {
        case 1:
            displayCourses();
            break;
        case 2:
            cout << "Enter course code to search - ";
            cin >> code;
            displayCourses(code);
            break;
        case 3:
            cout << "Enter class to add to cart - ";
            cin >> class_code;
            addToCart(class_code);
            break;
        case 4:
            flag = false;
            //Add checkout function here
        }
    }
}


