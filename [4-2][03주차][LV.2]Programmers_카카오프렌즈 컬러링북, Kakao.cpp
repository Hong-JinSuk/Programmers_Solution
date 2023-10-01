#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int next_x[] = { 1,-1,0,0 };
int next_y[] = { 0,0,1,-1 };

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    bool isvisit[101][101];
    for (int i = 0; i< m; i++) {
        for (int j = 0; j < n; j++) {
            isvisit[i][j] = false;
        }
    }

    queue<pair<int,int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            int y = i, x = j;
            int color = picture[y][x];
            if (color == 0) continue;
            if (!isvisit[y][x]) {
                q.push({ x,y });
                number_of_area++;
                cout << y << ", " << x << endl;
            }
            while (!q.empty()) {
                pair<int,int> cur = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = cur.first + next_x[k];
                    int ny = cur.second + next_y[k];
                    // 범위 안, 방문 x, 같은 컬러
                    if (nx > -1 && ny > -1 && nx < n && ny < m && !isvisit[ny][nx] && picture[ny][nx]==color) {
                        q.push({ nx,ny });
                        cnt++;
                        isvisit[ny][nx] = true;
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area, cnt);
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {

    int m, n;
    cin >> m >> n;
    vector<vector<int>> picture = { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };

    vector<int> answer = solution(m, n, picture);
    cout << answer[0] << " " << answer[1];

    return 0;
}