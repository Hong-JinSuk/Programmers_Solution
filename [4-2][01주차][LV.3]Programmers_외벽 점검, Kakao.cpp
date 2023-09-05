#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {

    int answer = 987654321;
    int weak_size = weak.size();

    for (int i = 0; i < weak_size; i++) {
        weak.push_back(weak[i] + n); // 10시 -> 1시 방향은 10 -> 13 형식으로 거리 표시
    }

    do {
        for (int i = 0; i < weak_size; i++) { // 시작지점 선택(완전 탐색)
            int start = weak[i]; // 시작지점
            int end = weak[weak_size - 1 + i]; // 시작지점에 대해 끝나는 지점

            for (int fri = 0; fri < dist.size(); fri++) { // 탐색하는 친구
                start += dist[fri]; // 첫번째 친구가 탐색할 수 있는 거리

                if (answer != 987654321 && answer <= fri + 1)
                    break; // 이미 더 많은 친구를 쓰게되면 통과

                if (start >= end) { // 친구가 weakpoint를 모두 찾으면
                    answer = min(answer, fri + 1);
                    break; 
                }

                // 모두 찾은게 아니면 다음 지점 찾아감
                for (int k = i + 1; k < i + weak_size; k++) {
                    // 다음지점까지 갈 거리가 안된다면
                    if (weak[k] > start) {
                        start = weak[k]; // 다음 스타팅을 정해줌.
                        break; // 다음 친구 투입
                    }
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end())); // 조합

    if (answer == 987654321) return -1;
    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<int> weak = { 1,5,6,10 };
    vector<int> dist = { 1,2,3,4 };

    cout << solution(n, weak, dist);

    return 0;
}