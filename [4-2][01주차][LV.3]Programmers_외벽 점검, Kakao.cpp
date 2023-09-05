#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {

    int answer = 987654321;
    int weak_size = weak.size();

    for (int i = 0; i < weak_size; i++) {
        weak.push_back(weak[i] + n); // 10�� -> 1�� ������ 10 -> 13 �������� �Ÿ� ǥ��
    }

    do {
        for (int i = 0; i < weak_size; i++) { // �������� ����(���� Ž��)
            int start = weak[i]; // ��������
            int end = weak[weak_size - 1 + i]; // ���������� ���� ������ ����

            for (int fri = 0; fri < dist.size(); fri++) { // Ž���ϴ� ģ��
                start += dist[fri]; // ù��° ģ���� Ž���� �� �ִ� �Ÿ�

                if (answer != 987654321 && answer <= fri + 1)
                    break; // �̹� �� ���� ģ���� ���ԵǸ� ���

                if (start >= end) { // ģ���� weakpoint�� ��� ã����
                    answer = min(answer, fri + 1);
                    break; 
                }

                // ��� ã���� �ƴϸ� ���� ���� ã�ư�
                for (int k = i + 1; k < i + weak_size; k++) {
                    // ������������ �� �Ÿ��� �ȵȴٸ�
                    if (weak[k] > start) {
                        start = weak[k]; // ���� ��Ÿ���� ������.
                        break; // ���� ģ�� ����
                    }
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end())); // ����

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