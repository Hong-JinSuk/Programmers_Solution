#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int nx[4] = { 1,-1,0,0 };
int ny[4] = { 0,0,1,-1 };
bool isvisited[102][102];

tuple<int,int,int> BFS_L(int start_row, int start_col, vector<string> maps, int answer) {
    
    fill_n(&isvisited[0][0], 102 * 102, false); // �ʱ�ȭ

    queue<pair<int,int>> q;
    q.push({ start_row, start_col });

    int maps_row = maps.size(), maps_col = maps[0].size();

    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) { // ���� q�� ��� ����
            int Row = q.front().first, Col = q.front().second;
            if (maps[Row][Col] == 'L') return tie(Row, Col, answer); // ã���� ����
            isvisited[Row][Col] = true;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_row = Row + nx[j];
                int next_col = Col + ny[j];

                if (next_row > -1 && next_col > -1 && next_row < maps_row && next_col < maps_col && !isvisited[next_row][next_col]) {
                    if (maps[next_row][next_col] != 'X') {
                        q.push({ next_row,next_col });
                        isvisited[next_row][next_col] = true;
                    }
                }
            }
        }
        answer++; // �ѹ� q�� ���°� ��� �־��ָ� ++
    }

    return make_tuple(-1, -1, -1);
}

int BFS_E(int start_row, int start_col, int answer, vector<string> maps) {

    queue<pair<int, int>> q;
    q.push({ start_row, start_col });

    int maps_row = maps.size(), maps_col = maps[0].size();

    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) { // ���� q�� ��� ����
            int Row = q.front().first, Col = q.front().second;
            if (maps[Row][Col] == 'E') return answer;
            isvisited[Row][Col] = true;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_row = Row + nx[j];
                int next_col = Col + ny[j];

                if (next_row > -1 && next_col > -1 && next_row < maps_row && next_col < maps_col && !isvisited[next_row][next_col]) {
                    if (maps[next_row][next_col] != 'X') {
                        q.push({ next_row,next_col });
                        isvisited[next_row][next_col] = true;
                    }
                }
            }
        }
        answer++;
    }
    return -1;
}

int solution(vector<string> maps) {
    int maps_row = maps.size(), maps_col = maps[0].size();
    int x, y, answer = 0;

    for (int i = 0; i < maps_row; i++) {
        for (int j = 0; j < maps_col; j++) {
            if (maps[i][j] == 'S') x = i, y = j; // ���������� ã��
        }
    }

    // ��ǻ� BFS_L �� BFS_E�� ���� �ڵ��Դϴ�.
    tie(x, y, answer) = BFS_L(x, y, maps, answer); // L ������ ã�� ����
    if (x == -1) return answer; // ��ã���� ��

    answer = BFS_E(x, y, answer, maps); // L �������� E������ ã��
    return answer;
}

int main() {

    vector<string> maps = { "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" };

    cout << solution(maps);

    return 0;
}