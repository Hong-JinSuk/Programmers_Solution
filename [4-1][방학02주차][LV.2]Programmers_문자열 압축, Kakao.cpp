#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int Len = s.size() / 2;
    
    for (int Size = 1; Size <= Len; Size++) { // Size = �ڸ��� ����
        string result = "";
        string Post = s.substr(0, Size); // �ݺ��� ���� ����
        int cnt = 1;

        for (int index = Size; index <= s.size(); index += Size) {
            if (Post == s.substr(index, Size)) { // �ݺ��� ���ڿ� ������?
                cnt += 1;
            }
            else {
                if (cnt == 1) result += Post; // 1�ΰ��� ���ڸ� �ȳ���
                else {
                    result += (to_string(cnt) + Post); //�ƴϸ� ����°�� �����ش�.
                }
                Post = s.substr(index, Size); // ���� ��ġ���� �ݺ��� ���� ����
                cnt = 1; // �ٽ� �ʱ�ȭ
            }
        }

        if (s.size() % Size != 0) { // aabbaccc �� ��쿡�� size=3�� ��� bba <-> ccc �˻��ϰ��� bac <-> cc ���� cc�� �˻簡 �ȵǰ� �Ѿ��. (�� ���ǿ��� index+=Size������)
                                    // ���� ������ ¥������ �׳� �����ִ� ���̴�.
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

    string s = "ababdabab"; // �� ��찡 2ab d 2ab�� ���;� �ϴ��� �˰�,,, �ð��� �ʹ� �����ɸ�
    //cout<< s.substr(6);
    cout << solution(s);

    return 0;
}