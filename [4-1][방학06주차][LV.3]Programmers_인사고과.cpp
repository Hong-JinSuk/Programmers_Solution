#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool com_1(vector<int>& a, vector<int>& b) {
    return a < b;
}
bool com_2(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;

    auto wanho = scores[0];
    int wanho_score = scores[0][0] + scores[0][1];

    sort(scores.begin(), scores.end(), com_1);

    /*for (auto a : scores) {
        if (a[0] > wanho[0] && a[1] > wanho[1]) return -1;
        else if (a[0] + a[1] > wanho_score) answer++;
    }*/

    // 위에 주석처리와 다른점은 완호 점수보다 낮은 사람은 고려할 필요가 없게 미리 삭제해줌.
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i][0] > wanho[0] && scores[i][1] > wanho[1]) return -1;
        else if (scores[i][0] + scores[i][1] <= wanho_score) {
            scores.erase(scores.begin() + i);
            i--;
        }
        else if (scores[i][0] + scores[i][1] > wanho_score) answer++;
    }

    //sort(scores.begin(), scores.end(), com_1);
    for (int i = 0; i < scores.size(); i++) {
        for (int j = scores.size() - 1; j > i; j--) {
            // 삭제되야 하는 놈들
            if (scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]) {
                // 그 중에 완호보다 점수 큰 친구들
                if (wanho_score < scores[i][0] + scores[i][1]) {
                    answer--;
                }
                break;
            }
        }
    }

    return answer;
}