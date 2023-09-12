#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MOD = 20170805;
//int dp[501][501][2]; 이렇게하면 왜 틀리는거지???

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(2)));

    for (int y = 1; y < m; y++) {
        if (city_map[y][0] == 1) break;
        dp[y][0][1] = 1;
    }
    for (int x = 1; x < n; x++) {
        if (city_map[0][x] == 1) break;
        dp[0][x][0] = 1;
    }
    for (int y = 1; y < m; y++) {
        for (int x = 1; x < n; x++) {
            if (city_map[y - 1][x] == 0) {
                dp[y][x][1] += (dp[y - 1][x][1] + dp[y - 1][x][0]) % MOD;
            }
            if (city_map[y][x - 1] == 0) {
                dp[y][x][0] += (dp[y][x - 1][0] + dp[y][x - 1][1]) % MOD;
            }
            if (city_map[y - 1][x] == 2) {
                dp[y][x][1] += (dp[y - 1][x][1]) % MOD;
            }
            if (city_map[y][x - 1] == 2) {
                dp[y][x][0] += (dp[y][x - 1][0]) % MOD;
            }
        }
    }
    answer += (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    return answer;
}

int main() {
    int m, n;
    cin >> m >> n;
    //vector<vector<int>> city_map = { { 0, 2, 0, 0, 0, 2},{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0 } };
    vector<vector<int>> city_map;
    for (int i = 0; i < m; i++) {
        vector<int> x;
        for (int j = 0; j < n; j++) {
            x.push_back(0);
        }
        city_map.push_back(x);
    }

    cout << solution(m, n, city_map);

    /*for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j][0] + dp[i][j][1] << " ";
        }
        cout << endl;
    }*/
    return 0;
}