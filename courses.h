#include <bits/stdc++.h>

using namespace std;

struct course
{
    string courseCode;
    string section;
    string instructor;
    pair<int, int> timing;
    vector<string> days;
    int credits;
};
map<string, set<string>> courseSections;

map<string, course> findCourses(string year)
{
    course c = {"CSF211", "L1", "C Hota", {2, 3}, {"T", "Th", "S"}, 4};
    map<string, course> c2021 = {{"1001", c}};
    // if (year == "2021")
    return c2021;
    // if (year == "2020")
    //     return c2020;
    // if (year == "2019")
    //     return c2019;
    // if (year == "2018")
    //     return c2018;
}
// map<string, course> findCourses(string year)
// {
//     if (year == "2021")
//         freopen("first_courses.txt", "r", stdin);
//     if (year == "2020")
//         freopen("second_courses.txt", "r", stdin);
//     if (year == "2019")
//         freopen("third_courses.txt", "r", stdin);
//     if (year == "2018")
//         freopen("fourth_courses.txt", "r", stdin);

//     int n;
//     cin >> n;

//     map<string, course> result;

//     for (int i = 0; i < n; i++)
//     {
//         string courseCode;
//         string section;
//         string instructor;
//         pair<int, int> timing;
//         vector<string> days;
//         string classCode;
//         int credits;

//         cin >> classCode >> courseCode >> section >> instructor >> timing.first >> timing.second;
//         int d;
//         cin >> d;
//         for (int i = 0; i < d; i++)
//         {
//             string day;
//             cin >> day;
//             days.push_back(day);
//         }
//         cin >> credits;

//         courseSections[courseCode].insert(section.substr(0, 1));
//         result[classCode] = {courseCode, section, instructor, timing, days, credits};
//     }

//     return result;
// }
