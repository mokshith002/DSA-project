#include <bits/stdc++.h>

using namespace std;

struct course{
    string courseCode;
    string section;
    string instructor;
    pair<int, int> timing;
    vector<string> days;
    int credits;
};

map<string, course> findCourses(string year){
    if(year == "2021")
        freopen("first_courses.txt", "r", stdin);
    if(year == "2020")
        freopen("second_courses.txt", "r", stdin);
    if(year == "2019")
        freopen("third_courses.txt", "r", stdin);
    if(year == "2018")
        freopen("fourth_courses.txt", "r", stdin);


    int n;
    cin >> n;

    map<string, course> result;

    for(int i = 0; i < n; i++){
        string courseCode;
        string section;
        string instructor;
        pair<int, int> timing;
        vector <string> days;
        string classCode;
        int credits;

        cin >> classCode >> courseCode >> section >> instructor >> timing.first >> timing.second;
        int d; cin >> d;
        for(int i = 0; i < d; i++){
            string day; cin >> day;
            days.push_back(day);
        }
        cin >> credits;

        result[classCode] = { courseCode , section , instructor , timing, days, credits};
    }

    return result;
}



