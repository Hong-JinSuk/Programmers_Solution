#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 1000000000001 // 10만 * 10만 + 1
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    long long Max_x = -MAX, Max_y = -MAX, Min_x = MAX, Min_y = MAX;

    vector<pair<long long, long long>> Ans;
    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = i + 1; j < line.size(); j++) {
            long long AD_BC = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            long long BF_ED = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            long long EC_AF = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
            if (AD_BC == 0 || BF_ED % AD_BC != 0 || EC_AF % AD_BC != 0) continue; // 평행 or 정수가 아닌경우
            long long x = BF_ED / AD_BC;
            long long y = EC_AF / AD_BC;
            //cout << x << "," << y << endl;
            Ans.push_back({ x,y });
            Max_x = max(Max_x, x);
            Max_y = max(Max_y, y);
            Min_x = min(Min_x, x);
            Min_y = min(Min_y, y);
        }
    }

    for (int i = 0; i <= Max_y - Min_y; i++) {
        string str = "";
        for (int j = 0; j <= Max_x - Min_x; j++) {
            str += '.';
        }
        answer.push_back(str);
    }

    for (auto k : Ans) {
        k.first += -Min_x;
        k.second += -Min_y;
        //cout << k.first << ", " << k.second << endl;
        answer[k.second][k.first] = '*';
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {

    vector<vector<int>> line = { {2, -1, 4}, {-2, -1, 4},{0, -1, 1},{5, -8, -12},{5, 8, 12 } };
    vector<string> answer = solution(line);
    for (auto ans : answer)
        cout << ans << endl;

    return 0;
}