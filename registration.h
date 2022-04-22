#include <bits/stdc++.h>
#include <chrono>
#include <thread>
#include "courses.h"

using namespace std;

struct cartItem
{
    pair<int, int> timing;
    string classCode;
};
bool operator<(const cartItem &lhs, const cartItem &rhs)
{
    return lhs.timing < rhs.timing;
}

map<string, course> courses;
map<string, int> dayIndex = {{"M", 0}, {"T", 1}, {"W", 2}, {"Th", 3}, {"F", 4}, {"S", 5}};

const int DAYS = 6;
vector<set<cartItem>> cart(DAYS);
map<string, set<string>> currentSections;

void addToCart(string class_code)
{   
    if(!courses.count(class_code)){
        cout << "Course with class code " + class_code + " does not exist\n";
        return;
    }

    course c = courses[class_code];
    string sectionType = c.section.substr(0, 1);
    if (currentSections.count(c.courseCode) and
        currentSections[c.courseCode].count(sectionType))
    {
        cout << "Cannot add to cart, " + sectionType + " section for " + c.courseCode + " already present in cart!\n";
        return;
    }
    currentSections[c.courseCode].insert(sectionType);

    for (auto d : c.days)
    {
        cart[dayIndex[d]].insert({c.timing, class_code});
    }
    cout << "Successfully inserted " + c.courseCode + " " + c.section << endl;
}

void removeFromCart(string class_code)
{
    if (!courses.count(class_code))
    {
        cout << "Course with class code " + class_code + " does not exist\n";
        return;
    }

    course c = courses[class_code];
    for (auto d : c.days)
    {
        cart[dayIndex[d]].erase({c.timing, class_code});
    }

    string sectionType = c.section.substr(0, 1);
    if (currentSections.count(c.courseCode) and
        currentSections[c.courseCode].count(sectionType))
    {
        currentSections[c.courseCode].erase(sectionType);
        if (currentSections[c.courseCode].empty())
        {
            currentSections.erase(c.courseCode);
        }
    }

    cout << "Successfully deleted " + c.courseCode + " " + c.section << endl;
}

void displayCourses(string code = "all")
{
    cout << setw(7) << "Code"
         << setw(10) << "Course"
         << setw(10) << "Credits"
         << setw(10) << "Section"
         << setw(15) << "Instructor"
         << setw(10) << "Days  "
         << setw(7) << "Start"
         << setw(5) << "End\n";

    for (auto crs : courses)
    {
        course c = crs.second;
        if (code != "all" && c.courseCode != code)
            continue;
        cout << endl;
        cout << setw(7) << crs.first;
        cout << setw(10) << c.courseCode;
        cout << setw(10) << c.credits;
        cout << setw(10) << c.section;
        cout << setw(15) << c.instructor;
        string ds;
        for (auto d : c.days)
            ds.append(d + " ");
        cout << setw(10) << ds;
        cout << setw(7) << c.timing.first;
        cout << setw(5) << c.timing.second;
    }

    cout << endl
         << endl;
}

void registration(string year)
{
    courses = findCourses(year);
    displayCourses();
    bool flag = true;
    while (flag)
    {
        // std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
        cout << "\n\n\n1. View all courses" << endl
             << "2. Search by course code" << endl
             << "3. Enter class code to add to cart" << endl
             << "4. Enter class code to remove from cart" << endl
             << "5. View cart" << endl
             << "Enter you choice - ";
        int choice;
        cin >> choice;
        cout << "Choice is " << choice << endl;
        string class_code, code;
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
            cout << "Enter class to add to cart - ";
            cin >> class_code;
            removeFromCart(class_code);
            break;
        case 5:
            return;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    }
}
