#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long int> Y;

// k = 곱해주는 수, d = 한계선
long long solution(int k, int d) {
    long long answer = 0;
    int Start = d / k * k;
    long long Max = pow(d, 2);

    // 위에서 계단 타고내려오는 느낌
    for (long long x = 0; x <= d; x += k) {
        for (long long y = Start; y >= 0; y -= k) {
            if (pow(y, 2) + pow(x, 2) <= Max) {
                Y.push_back(y); // 가장 윗점만 표시
                Start = y; // x는 앞으로 커지니깐 y는 마지막 지점으로 저장
                break;
            }
        }
    }
    for (auto a : Y) {
        answer += a / k + 1;
    }
    return answer;
}

int main() {

    int k, d;
    cin >> k >> d;

    cout << solution(k, d);

    return 0;
}