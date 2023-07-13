#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> menu;

void johab(string str, string Key, int Size, int index, int cnt) { // ABCDE, ", 2, 0, 0
    
    if (cnt == Size) {
        if (menu.find(Key) != menu.end()) menu[Key]++;
        else menu.insert({ Key, 1 });
        //cout << Key << endl;
        return;
    }

    for (int i = index; i < str.size(); i++) {
        Key += str[i];
        johab(str, Key, Size, i + 1, cnt + 1);
        Key.erase(Key.end()-1);
    }

    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // �־��� orders ��ü�� ����
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }

    for (int j = 0; j < course.size(); j++) {
        for (int i = 0; i < orders.size(); i++) {
            johab(orders[i], "", course[j], 0, 0);
        }

        int Min = 2; // �޴��� 2���̻� ����� ��,
        vector<pair<string, int>> Answer;
        for (auto key : menu) {
            if (key.second > Min) { // ���ο� menu�� �����
                Answer.clear(); // �����޴� ����
                Min = key.second;
                Answer.push_back({ key.first,key.second });
            }
            else if (key.second == Min) Answer.push_back({ key.first,key.second });
        }
        for (int i = 0; i < Answer.size(); i++) { // ���ο� �޴��� �信 �־���.
            answer.push_back(Answer[i].first);
        }
        menu.clear(); // ���� �޴����� ���� ����
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {

    vector<string> orders = { "XYZ", "XWY", "WXA" };
    vector<int> course = { 2,3,4 };

    vector<string> answer = solution(orders, course);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}