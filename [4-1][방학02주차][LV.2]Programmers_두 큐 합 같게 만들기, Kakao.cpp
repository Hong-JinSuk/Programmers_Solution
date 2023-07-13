#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long int q1_sum = 0, q2_sum = 0;
    int cnt = queue1.size();

    deque<int> Q1;
    deque<int> Q2;
    Q1.assign(queue1.begin(), queue1.end());
    Q2.assign(queue2.begin(), queue2.end());

    for (int i = 0; i < queue1.size(); i++) {
        q1_sum += Q1[i];
        q2_sum += Q2[i];
    }

    while (q1_sum != q2_sum) {
        answer++;
        if (q1_sum > q2_sum) {
            int temp = Q1[0];
            Q2.push_back(temp);
            q2_sum += temp;
            q1_sum -= temp;
            Q1.pop_front();
        }
        else {
            int temp = Q2[0];
            Q1.push_back(temp);
            q1_sum += temp;
            q2_sum -= temp;
            Q2.pop_front();
        }
        if (answer > cnt * cnt / 2) {
            answer = -1;
            break;
        }
    }

    return answer;
}

int main() {

    vector<int> queue1 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 10 };
    vector<int> queue2 = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    cout << solution(queue1, queue2);

    return 0;
}