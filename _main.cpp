#include<bits/stdc++.h>

using namespace std;

// struct course
// {
//     string courseCode;
//     string section;
//     string instructor;
//     pair<int, int> timing;
//     vector<string> days;
//     int credits;
// };


    // first_year.insert{courseCode, {"CSF211", "L1", "C Hota", {2, 3}, {"T", "Th", "S"}, 4}}

string daysFormat(vector<string> days, int n){
    string ret = "{";
    for(int i = 0; i < n; i++){
        ret.append("\"" + days[i] + "\"");
        if(i < n - 1) ret.append(", ");
    }

    ret.append("}");

    return ret;
}

void generateCourses(){

    string name = ("fourth_year");

    freopen("fourth_courses.txt", "r", stdin);
    
    int n;
    cin >> n;

    cout << n << endl;
        
    cout << "{\n";

    for (int i = 0; i < n; i++)
    {
        string courseCode;
        string section;
        string instructor;
        pair<int, int> timing;
        vector<string> days;
        string classCode;
        int credits;

        cin >> classCode >> courseCode >> section >> instructor >> timing.first >> timing.second;
        int d;
        cin >> d;
        for (int i = 0; i < d; i++)
        {
            string day;
            cin >> day;
            days.push_back(day);
        }
        cin >> credits;


        cout << "{\"" 
                << classCode 
                << "\", {\"" 
                    << courseCode << "\", \"" 
                    << section << "\", \"" 
                    << instructor << "\", {"
                        << timing.first << ", "
                        << timing.second
                    << "}, " 
                    << daysFormat(days, d) << ", "
                    << credits
                << "}" 
            << "},\n";
    }

    cout << "}";
}

int main(){
    generateCourses();
    return 0;
}