#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int Len = s.size() / 2;
    
    for (int Size = 1; Size <= Len; Size++) { // Size = 자르는 단위
        string result = "";
        string Post = s.substr(0, Size); // 반복할 문자 선택
        int cnt = 1;

        for (int index = Size; index <= s.size(); index += Size) {
            if (Post == s.substr(index, Size)) { // 반복할 문자와 같은가?
                cnt += 1;
            }
            else {
                if (cnt == 1) result += Post; // 1인경우는 숫자를 안넣음
                else {
                    result += (to_string(cnt) + Post); //아니면 숫자째로 더해준다.
                }
                Post = s.substr(index, Size); // 현재 위치부터 반복할 문자 선택
                cnt = 1; // 다시 초기화
            }
        }

        if (s.size() % Size != 0) { // aabbaccc 의 경우에서 size=3인 경우 bba <-> ccc 검사하고나서 bac <-> cc 여서 cc가 검사가 안되게 넘어간다. (위 조건에서 index+=Size때문에)
                                    // 따라서 마지막 짜투리는 그냥 더해주는 것이다.
            //cout << s.substr((s.size() / Size) * Size) << endl;
            result += s.substr((s.size() / Size) * Size);
        }

        int result_size = result.size();
        for (int i = 0; i < result_size; i++) {
            cout << result[i];
        }
        cout << endl;
        answer = min(answer, result_size);
    }
    
    return answer;
}

int main() {

    string s = "ababdabab"; // 이 경우가 2ab d 2ab로 나와야 하는줄 알고,,, 시간이 너무 오래걸림
    //cout<< s.substr(6);
    cout << solution(s);

    return 0;
}