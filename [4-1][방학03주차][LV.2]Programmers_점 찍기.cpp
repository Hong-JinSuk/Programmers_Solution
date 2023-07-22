#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long int> Y;

// k = �����ִ� ��, d = �Ѱ輱
long long solution(int k, int d) {
    long long answer = 0;
    int Start = d / k * k;
    long long Max = pow(d, 2);

    // ������ ��� Ÿ�������� ����
    for (long long x = 0; x <= d; x += k) {
        for (long long y = Start; y >= 0; y -= k) {
            if (pow(y, 2) + pow(x, 2) <= Max) {
                Y.push_back(y); // ���� ������ ǥ��
                Start = y; // x�� ������ Ŀ���ϱ� y�� ������ �������� ����
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