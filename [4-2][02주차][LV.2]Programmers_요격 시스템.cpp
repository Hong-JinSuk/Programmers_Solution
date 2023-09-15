#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isLast(vector<int>& t1, vector<int>& t2) {
    return t1[1] < t2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    int Start = 0, End = targets.size();
    sort(targets.begin(), targets.end(), isLast);

    int shoot = 0; // 쏘는 위치
    int boom = 0; // 폭탄 위치

    while (boom < End) {
        answer++; // 미사일 발사 횟수
        shoot = targets[boom][1];
        cout << shoot << endl;
        while (shoot > targets[boom][0]) {
            boom++;
            if (boom == End) return answer; // 모두 요격 했으면 끝
        }
    }
    
    return answer;
}

int main() {

    vector<vector<int>> targets = { {4,5},{4,8},{10,14},{11,13},{5,12},{3,7},{1,4} };
    cout << solution(targets);

    return 0;
}