#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPerfect(string u) {
    vector<char> L;
    vector<char> R;
    int cnt = 0;
    do {
        if (u[cnt] == '(') L.push_back(u[cnt++]);
        else R.push_back((u[cnt++]));
    } while (L.size() > R.size());

    if (cnt == u.size()) return true;
    return false;
}

string answer = "";

string solution(string p) {
    

    if (p.empty()) return p;
    
    string u;
    vector<char> L;
    vector<char> R;
    int cnt = 0;
    do {
        if (p[cnt] == '(') {
            L.push_back(p[cnt]);
            u += p[cnt];
        }
        else {
            R.push_back((u[cnt]));
            u += p[cnt];
        }
        cnt++;
    } while (L.size() != R.size());

    //cout << L.size() << " / " << R.size() << endl;
    p.erase(p.begin(), p.begin() + u.size());

    // u = 올바른 괄호 문자열
    if (isPerfect(u)) {
        //cout << answer << " + " << u << endl;
        answer += u;
        solution(p);
    }
    else {
        answer += '(';
        solution(p);
        answer += ')';
        u.erase(u.begin());
        u.erase(u.begin() + u.size() - 1);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(')answer += ')';
            else answer += '(';
        }
    }

    return answer;
}

int main() {

    string p = "()))((()";

    cout << solution(p);

    return 0;
}