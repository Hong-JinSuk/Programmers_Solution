#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ooz = 0; // 110

void cut_110(string& str, int start) {
    if (str.find("110", start) == string::npos || str.size() < 3) return; // start 지점부터 110을 못찾으면 끝
    ooz++; // 110 찾음

    int index = str.find("110", start);
    str.erase(index, 3);
    index = index - 2 < 0 ? 0 : index - 2;
    
    cut_110(str, index);

    return;
}

void insert_110(string& str) {
    int one = 0;
    int index = -1;

    for (int i = 0; i < str.size(); i++) {
        one++;
        if (str[i] == '0') {
            one = 0;
            index = i;
        }
        if (one == 3) {
            index = i - 3;
            break;
        }
    }

    cout << "index : " << index << endl;
    for (int i = 0; i < ooz; i++) {
        if (index == -1) str.insert(0, "110");
        else str.insert(index+1, "110");
    }
    ooz = 0;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (string str : s) {
        cut_110(str, 0);
        insert_110(str);
        answer.push_back(str);
    }

    return answer;
}

int main() {

    vector<string> s = { "1011110","01110","101101111010", "110111", "111110"};

    vector<string> answer = solution(s);

    for (auto a : answer)
        cout << a << endl;

    return 0;
}