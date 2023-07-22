#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int MIN = 99999;

// cnt : DFS���� �ڸ����� �����ֱ� ���� �Ķ����
void DFS(int storey, int cnt, int ANSWER) {

    string str = to_string(storey);
    int str_size = str.size();

    // storey < 0 ������ �� �ʿ��ұ�?? �̰� �ȳ����� 6,10�� ���̽��� ���X
    if (storey < 0 || str[0] =='0') {
        if (str[0] - '0' <= 5) ANSWER += str[0] - '0';
        else ANSWER += 10 - (str[0] - '0') + 1;
        MIN = min(MIN, ANSWER);
        return;
    }

    int temp = str[str_size - 1 - cnt] - '0'; // 1���ڸ�����
    // ���ؼ� 0�� �������
    DFS(storey + (10 - temp) * pow(10, cnt), cnt + 1, ANSWER + 10 - temp);
    // ���� 0�� �������
    DFS(storey - temp * pow(10, cnt), cnt + 1, ANSWER + temp);

    return;
}

int solution(int storey) {
    int answer = 0;
    
    DFS(storey, 0, 0);
    answer = MIN;

    return answer;
}

int main() {

    int storey;
    cin >> storey;
    cout << solution(storey);
    return 0;
}