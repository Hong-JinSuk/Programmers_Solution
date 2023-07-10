#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void check(vector<int> lion, vector<int> apeach, int a_score, vector<vector<int>>& answer) {
    int r_score = 0;

    for (int i = 0; i < lion.size(); i++) {
        int score = 10 - i;
        if (lion[i] != 0) {
            if (apeach[i] == 0) r_score += score;
            else if (lion[i] > apeach[i]) r_score += score * 2;
        }
    }
    if (r_score > a_score) {
        answer.push_back(lion); // lion�� ����̸� ��ȯ
        return;
    }
}

void compare(int n, vector<int>& lion, vector<int> new_lion, vector<int> apeach) {

    if (new_lion[0] == -1) return;

    int lion_score = 0;
    int newlion_score = 0;

    for (int i = 0; i < lion.size(); i++) {
        int score = 10 - i;
        if (lion[i] > 0 && lion[i] > apeach[i]) lion_score += score;
        if (new_lion[i] > 0 && new_lion[i] > apeach[i]) newlion_score += score;
    }

    if (lion_score < newlion_score) {
        lion = new_lion; // ���̰� ��ũ�� ��ü
    }
    else if (lion_score == newlion_score) { // ���̰� ���ٸ�
        for (int i = lion.size() - 1; i > -1; i--) { // �������� ���� ��
            if (lion[i] == 0 && new_lion[i] == 0) continue;
            if (lion[i] < new_lion[i]) {
                lion = new_lion;
                break;
            }
            else break;
        }
    }
}

void dfs(int n, vector<int> result, vector<vector<int>>& lion, int index_) {

    if (n == 0) {
        lion.push_back(result);
        return;
    }

    for (int index = index_; index < 11; index++) {
        result[index]++;
        dfs(n - 1, result, lion, index);
        result[index]--;
    }

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    int a_score = 0, r_score = 0;

    for (int i = 0; i < info.size(); i++) { // ����ġ ����
        int score = 10 - i;
        if (info[i] != 0) a_score += score;
    }

    vector<vector<int>> lion;
    vector<int> result(11, 0);
    dfs(n, result, lion, 0); // lion = ���̾��� �� �� �ִ� ��� ����� ��

    vector<vector<int>> answer;

    for (int i = 0; i < lion.size(); i++) {
        check(lion[i], info, a_score, answer); // answer = lion�� �� �� �ִ� ����� ����ġ���� ���� ��� 
    }
    if (answer.empty()) {
        return answer;
    }
    answer = answer[0];
    for (int i = 0; i < answer.size(); i++) {
        compare(n, answer, answer[i], info);
    }

    return answer;
}


int main() {

    int n = 9;
    vector<int> info = { 0,0,1,2,0,1,1,1,1,1,1 };

    vector<int> answer = solution(n, info);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }

    return 0;
}