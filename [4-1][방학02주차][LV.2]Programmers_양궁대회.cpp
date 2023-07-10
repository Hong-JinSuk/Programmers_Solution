#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int Max = 0;

void Check(vector<int> Lion, vector<int> Apeach, vector<int>& answer) {

    int r_score = 0;
    int a_score = 0;

    for (int i = 0; i < 11; i++) {
        int Score = 10 - i;
        if (Lion[i] > Apeach[i]) r_score += Score;
        else if (Apeach[i] > 0) a_score += Score;
    }
    
    int diff = r_score - a_score;

    if (diff > 0 && diff >= Max) {
        if (diff > Max) {
            answer = Lion;
            Max = diff;
        }
        else {
            for (int i = 10; i > -1; i--) {
                if (answer[i] > Lion[i]) break; // 이부분을 안넣으면 8, 18 case를 틀림.
                else if (Lion[i] > answer[i]) {
                    answer = Lion;
                    break;
                }
            }
        }
    }
}

void DFS(int n, int index_, vector<int> result, vector<int> apeach, vector<int>& answer) {

    if (n == 0) { // 전부 넣었으면 check하러감
        Check(result, apeach, answer);
        return;
    }

    for (int index = index_; index < 11; index++) {
        result[index]++;
        DFS(n - 1, index, result, apeach, answer);
        result[index]--;
    }

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int a_score = 0, r_score = 0;

    vector<int> result(11, 0);

    DFS(n, 0, result, info, answer); // Lion = 라이언이 쏠 수 있는 모든 경우의 수

    if (answer.empty()) answer.push_back(-1); // 답이 없는경우 -1 리턴
    return answer;
}


int main() {

    int n = 9;
    vector<int> info = { 0,0,1,2,0,1,1,1,1,1,1 };

    vector<int> answer = solution(n, info);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }

    return 0;
}