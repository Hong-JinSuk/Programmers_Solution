#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(long long begin, long long end) {

    vector<int> answer;

    for (int i = begin; i <= end; i++) {

        if (i == 1) {
            answer.push_back(0);
            continue;
        }

        bool isSosu = true;
        bool isinput = false;
        int MAX = 0;

        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0 && i / j <= 10000000) {
                answer.push_back(i / j);
                isSosu = false;
                isinput = true;
                break;
            }
            else if (i % j == 0 && i / j > 10000000) {
                MAX = max(MAX, j);
                isSosu = false;
            }
        }

        if (!isSosu&&!isinput) answer.push_back(MAX);
        if (isSosu) answer.push_back(1);
    }
    return answer;
}

int main() {

    long long begin, end;
    cin >> begin >> end;

    vector<int> answer = solution(begin, end);
    for (auto i : answer)
        cout << i << " ";
}