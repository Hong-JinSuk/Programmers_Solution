#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

queue<pair<int, pair<int,pair<int,string>>>> q; // 위치, cnt, answer, name
bool isfirst = true;

int check(char word) {
    int cnt = word - 'A';
    if (cnt / 13 == 0) {
        return cnt;
    }
    else {
        return 13 - (cnt % 13);
    }
}

void input(pair<int,pair<int,pair<int,string>>> cur) {
    
    int index = cur.first;
    int cnt = cur.second.first;
    int answer = cur.second.second.first;
    string name = cur.second.second.second;

    if (index < 0) index += name.size();
    else if (index >= name.size()) index %= name.size();
    cout << index << ", "<< cnt << ", "<< answer << endl;

    if (name[index] != 'A') {
        isfirst = false;
        int Answer = answer + check(name[index]);
        name[index] = 'A';
        q.push({ index + 1,{cnt - 1,{Answer, name}} });
        q.push({ index - 1,{cnt - 1,{Answer, name}} });
    }
    else if (name[index] == 'A' || isfirst) {
        isfirst = false;
        q.push({ index + 1, {cnt,{answer,name}} });
        q.push({ index - 1, {cnt,{answer,name}} });
    }

}

int solution(string name) {
    int answer = 0;
    int cnt = 0;
    for (char word : name) {
        if (word != 'A') cnt++; // 바꿔야할 단어 숫자
    }

    q.push({ 0,{cnt,{answer,name}} });

    while (!q.empty()) {
        int q_size = q.size();

        for (int i = 0; i < q_size; i++) {
            auto cur = q.front(); q.pop();
            if (cur.second.first == 0) {
                if (!isfirst) return cur.second.second.first + answer - 1;
                else return cur.second.second.first;
            }
            input(cur);
        }
        answer++;
        cout << endl;
    }

    return answer;
}

// 26개
int main() {

    string name;
    cin >> name;
    cout << solution(name);

    return 0;
}