#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1단계
    for (int i = 0; i < new_id.size(); i++) {
        if (int(new_id[i]) >= 65 && int(new_id[i]) <= 90) { // 알파벳 대문자면
            new_id[i] += 32;
        }
    }

    // 2단계
    for (int i = 0; i < new_id.size(); i++) {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        if (int(new_id[i]) >= 97 && int(new_id[i]) <= 122) continue;
        if (int(new_id[i] >= 48 && int(new_id[i] <= 57))) continue;
        new_id.erase(i, 1);
        i--;
    }

    // 3단계
    for (int i = 0; i < new_id.size() - 1; i++) {
        char Post = new_id[i];
        char Next = new_id[i + 1];
        if (Post == '.' && Next == '.') {
            new_id.erase(i, 1);
            i--;
        }
    }

    // 4단계
    if (!new_id.empty() && new_id[0] == '.') new_id.erase(0, 1);
    if (!new_id.empty() && new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

    // 5단계
    if (new_id.empty()) new_id = "a";

    // 6단계
    if (new_id.size() >= 16) new_id.erase(15, -1);

    // 4단계
    if (!new_id.empty() && new_id[0] == '.') new_id.erase(0, 1);
    if (!new_id.empty() && new_id[new_id.size() - 1] == '.') new_id.erase(new_id.size() - 1, 1);

    // 7단계
    if (new_id.size() <= 2) {
        while (1) {
            if (new_id.size() == 3) break;
            new_id += new_id[new_id.size() - 1];
        }
    }
    return answer;
}

int main() {

    string new_id = "1adf89df0d.123.456";
    //cin >> new_id;

    for (char ch : new_id) cout << ch;

    /*string now_id = solution(new_id);
    cout << now_id;*/
}