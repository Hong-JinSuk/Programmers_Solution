#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int isvisited[MAX]; // 0 : �湮 x, 1 �̻� : �湮�� �ʿ��� �Ÿ�

// BFS
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    

    vector<int>* Roads = new vector<int>[n + 1];
    for (auto x : roads) { // Roads[������ġ].push_back(���� �ִ°�)
        Roads[x[1]].push_back(x[0]);
        Roads[x[0]].push_back(x[1]);
    }

    queue<int> q;
    q.push(destination); // �������� ������
    
    int dist = 0; // �Ÿ�

    while (!q.empty()) {
        int q_size = q.size();
        dist++; // �̵��� �Ÿ�
        for (int i = 0; i < q_size; i++) {
            int cur = q.front();
            q.pop();
            // ���� ��ġ���� �� �� �ִ� ���
            for (int j = 0; j < Roads[cur].size(); j++) {
                int next = Roads[cur][j];
                if (isvisited[next] == 0) { // �湮���� �ʾҴٸ�
                    isvisited[next] = dist;
                    //cout << cur << "->" << next << endl;
                    q.push(next);
                }
            }
        }
    }

    for (int i = 0; i < sources.size(); i++) {
        if (sources[i] == destination) answer.push_back(0);
        else if (isvisited[sources[i]] == 0) answer.push_back(-1);
        else answer.push_back(isvisited[sources[i]]);
    }

    return answer;
}

int main() {

    int n, destination;
    cin >> n >> destination;
    vector<vector<int>> roads = { { 1, 2} ,{1, 4},{2, 4},{2, 5},{4, 5} };
    //vector<vector<int>>roads = { {1,2},{2,3} };
    vector<int> sources = { 1,3,5 };

    vector<int> answer = solution(n, roads, sources, destination);

    for (auto x : answer) {
        cout << x << " ";
    }

    return 0;
}