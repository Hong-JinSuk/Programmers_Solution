#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string to_time(int Time) {
    int Hour = Time / 60;
    int Min = Time % 60;
    string str_hour, str_min;
    if (Hour < 10) str_hour = "0" + to_string(Hour);
    else str_hour = to_string(Hour);
    if (Min < 10) str_min = "0" + to_string(Min);
    else str_min = to_string(Min);
    return str_hour + ":" + str_min;
}

string solution(int n, int t, int m, vector<string> timetable) {

    string answer = ""; // defalut °ª
    vector<int> min_table;

    for (int i = 0; i < timetable.size(); i++) {
        string hour = timetable[i].substr(0, 2);
        string min = timetable[i].substr(3, 2);
        min_table.push_back(stoi(hour) * 60 + stoi(min));
    }
    sort(min_table.begin(), min_table.end()); // ºÐÀ¸·Î Á¤¸®

    int crew_index = 0;
    int cutline = 540 - t;

    for (int i = 0; i < n; i++) {
        int cnt = 0; // Å¾½Â ½Â°´
        cutline += t;
        cout << cutline << endl;
        for (int x = crew_index; x < min_table.size(); x++) {
            if (min_table[x] <= cutline) {
                crew_index++; // Å©·ç¿ø ¼ø¼­
                cnt++; // Å¾½Â
                if (cnt == m) break; // ´Ù ÅÀÀ¸¸é º¸³»ÁÜ
            }
            else break;
        }

        if (i == n - 1) {
            if (cnt == m) {
                return to_time(min_table[crew_index - 1] - 1);
            }
            else {
                return to_time(cutline);
            }
        }
        
    }
    return "0000";
}

int main() {

    vector<string> timetable = { "09:00", "09:10" ,"09:20" ,"09:30" ,"09:40" ,"09:50", "10:00", "10:10" ,"10:20" ,"10:30" ,"10:40" ,"10:50" };
    int n, t, m;
    cin >> n >> t >> m;
    cout << solution(n, t, m, timetable);
    // cout << to_time(540);
    return 0;
}