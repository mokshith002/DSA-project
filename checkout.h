#include <bits/stdc++.h>
#include "registration.h"

using namespace std;
const int MAX_CREDITS = 25;

bool checkout()
{
    int totalCreds = 0;
    set<string> seen;

    for (int i = 0; i < DAYS; ++i)
    {
        for (auto it = cart[i].begin(); it != cart[i].end(); ++it)
        {
            // Check for overlapping sections
            auto nxt = it;
            nxt++;
            if (nxt != cart[i].end())
            {
                if (nxt->timing.first <= it->timing.second)
                {
                    cout << it->classCode << " clashes with " << nxt->classCode << "\n";
                    return false;
                }
            }

            // Check for maximum credits exceeded
            if (!seen.count(it->classCode))
            {
                seen.insert(it->classCode);
                totalCreds += courses[it->classCode].credits;
                if (totalCreds > MAX_CREDITS)
                {
                    cout << "Total credits exceed maximum limit\n";
                    return false;
                }
            }
        }
    }

    for (auto [courseCode, sections] : currentSections)
    {
        if (courseSections[courseCode].size() != sections.size())
        {
            cout << "All required sections for " + courseCode + " have not been added\n";
            return false;
        }
    }

    cout << "Registration successful!\n";
    return true;
}

bool displayCart()
{
    set<string> classCodes;
    for (int i = 0; i < DAYS; ++i)
    {
        for (auto [_, code] : cart[i])
            classCodes.insert(code);
    }

    cout << setw(7) << "Code"
         << setw(10) << "Course"
         << setw(10) << "Credits"
         << setw(10) << "Section"
         << setw(15) << "Instructor"
         << setw(10) << "Days"
         << setw(7) << "Start"
         << setw(5) << "End\n";

    for (auto code : classCodes)
    {
        course c = courses[code];
        cout << endl;
        cout << setw(7) << code;
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

    cout << "1. Go to checkout\n"
         << "2. Back registration menu\n"
         << "Enter you choice - ";
    int choice;
    cin >> choice;
    if (choice == 2)
        return false;
    return checkout();
}
