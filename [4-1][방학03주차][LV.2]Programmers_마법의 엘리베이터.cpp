#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int MIN = 99999;

// cnt : DFS에서 자릿수에 더해주기 위한 파라미터
void DFS(int storey, int cnt, int ANSWER) {

    string str = to_string(storey);
    int str_size = str.size();

    // storey < 0 조건이 왜 필요할까?? 이걸 안넣으면 6,10번 케이스가 통과X
    if (storey < 0 || str[0] =='0') {
        if (str[0] - '0' <= 5) ANSWER += str[0] - '0';
        else ANSWER += 10 - (str[0] - '0') + 1;
        MIN = min(MIN, ANSWER);
        return;
    }

    int temp = str[str_size - 1 - cnt] - '0'; // 1의자리부터
    // 더해서 0을 만들어줌
    DFS(storey + (10 - temp) * pow(10, cnt), cnt + 1, ANSWER + 10 - temp);
    // 빼서 0을 만들어줌
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