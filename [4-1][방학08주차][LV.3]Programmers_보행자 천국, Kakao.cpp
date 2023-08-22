#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MOD = 20170805;
int dp[501][501][2]; // 0 : 왼쪽, 1 : 위쪽
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

// 아래껀 왜 안되는지 모르겠네 시간복잡도 상으로??
//bool can_next(int x, int y, int n, int m, int& vec, vector<vector<int>> city_map) {
//    if (x >= n || y >= m) return false; // 범위 벗어나면 아웃
//    if (city_map[y][x] == 0) {
//        return true;
//    }
//    else if (city_map[y][x] == 1) {
//        return false;
//    }
//    else if (city_map[y][x] == 2 && vec > 0) { // 오른쪽
//        vec++; //오른쪽으로 한칸더
//        return can_next(x + 1, y, n, m, vec, city_map);
//    }
//    else if (city_map[y][x] == 2 && vec < 0) { // 아래
//        vec--; // 아래로 한칸 더
//        return can_next(x, y + 1, n, m, vec, city_map);
//    }
//    return false;
//}
//int DFS(int x, int y, int n, int m, vector<vector<int>> city_map) {
//    //cout << x << ", " << y << endl;
//    if (dp[y][x] != -1) // 이미 방문한 곳이면
//        return dp[y][x]; // 그곳을 더해준다.
//
//    if (x == n - 1 && y == m - 1) { // 마지막에 도착하면 1을 더함
//        return 1; // answer++
//    }
//    dp[y][x] = 0; // 지금 지점 초기화
//
//    int vec_right = 1;
//    int vec_down = -1;
//    if (can_next(x + 1, y, n, m, vec_right, city_map)) {
//        dp[y][x] += DFS(x + vec_right, y, n, m, city_map); // 다음 곳만큼 더함
//        if (dp[y][x] > MOD) dp[y][x] %= MOD;
//    }
//    if (can_next(x, y + 1, n, m, vec_down, city_map)) {
//        dp[y][x] += DFS(x, y - vec_down, n, m, city_map); // 다음 곳 만큼 더함
//        if (dp[y][x] > MOD) dp[y][x] %= MOD;
//    }
//    return dp[y][x]; // 현재지점 더해줌
//}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    for (int y = 0; y < m; y++) {
        if (city_map[y][0] == 1) break;
        dp[y][0][1] = 1;
    }
    for (int x = 0; x < n; x++) {
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
    //vector<vector<int>> city_map = { {0, 2, 0, 0, 0, 2} ,{0, 0, 2, 0, 1, 0},{1, 0, 0, 2, 2, 0} };
    //vector<vector<int>> city_map = { {0,0,0},{0,0,0},{0,0,0} };
    vector<vector<int>> city_map;
    for (int i = 0; i < m; i++) {
        vector<int> a;
        for (int j = 0; j < n; j++) {
            a.push_back(0);
        }
        city_map.push_back(a);
    }
    cout << solution(m, n, city_map);

    return 0;
}