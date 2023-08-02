#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool survived(int enemy, int& n) {
    n -= enemy;
    if (n >= 0) return true;
    return false;
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;

    while (n >= 0 && answer != enemy.size()) {

        pq.push(enemy[answer]);

        if (survived(enemy[answer], n)) {
            answer++;
        }
        else {
            if (k > 0) {
                answer++;
                n += pq.top();
                pq.pop();
                k--;
            }
        }
    }
    return answer;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> enemy = { 3,3,3,3 };

    cout << solution(n, k, enemy);

    return 0;
}