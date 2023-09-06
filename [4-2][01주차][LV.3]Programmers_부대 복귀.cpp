#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int isvisited[MAX]; // 0 : 방문 x, 1 이상 : 방문에 필요한 거리

// BFS
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    

    vector<int>* Roads = new vector<int>[n + 1];
    for (auto x : roads) { // Roads[현재위치].push_back(길이 있는곳)
        Roads[x[1]].push_back(x[0]);
        Roads[x[0]].push_back(x[1]);
    }

    queue<int> q;
    q.push(destination); // 도착지가 시작점
    
    int dist = 0; // 거리

    while (!q.empty()) {
        int q_size = q.size();
        dist++; // 이동한 거리
        for (int i = 0; i < q_size; i++) {
            int cur = q.front();
            q.pop();
            // 현재 위치에서 갈 수 있는 길들
            for (int j = 0; j < Roads[cur].size(); j++) {
                int next = Roads[cur][j];
                if (isvisited[next] == 0) { // 방문하지 않았다면
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