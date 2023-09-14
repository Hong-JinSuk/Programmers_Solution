#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long DP[360002];

// �� �� �� => ��
int Split(string log) {
    int Time;
    
    Time = stoi(log.substr(0, 2)) * 3600 + stoi(log.substr(3, 2)) * 60 + stoi(log.substr(6, 2));

    return Time;
}

// String => �� �� �� ��ȯ
string make_string(int time) {
    string answer = "";
    if (time / 3600 < 10) {
        answer += "0" + to_string(time / 3600) + ":";
    }
    else {
        answer += to_string(time / 3600) + ":";
    }
    time %= 3600;
    if (time / 60 < 10) {
        answer += "0" + to_string(time / 60) + ":";
    }
    else {
        answer += to_string(time / 60) + ":";
    }
    time %= 60;
    if (time < 10) {
        answer += "0" + to_string(time);
    }
    else answer += to_string(time);
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "00:00:00";

    for (string log : logs) {
        int Start = Split(log.substr(0, 8));
        int End = Split(log.substr(9, 8));
        /*for (int i = Start; i < End; i++)
            DP[i]++;*/ // �� �κ��� �����ɸ��� ����.
                       // �׷��� ���� ����ϰ� Ǭ �ڵ�� �����.. ����???
        DP[Start] += 1;
        DP[End] -= 1;
    }

    int playing_time = stoi(play_time.substr(0, 2)) * 3600 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    int daving_time = stoi(adv_time.substr(0, 2)) * 3600 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));

    long long temp = 0;
    for (int i = 1; i < playing_time; i++) {
        //temp += DP[i]; // ù ���Һ��� ����ð���ŭ ���� ������� ����
        DP[i] += DP[i - 1];
    }
    for (int i = 0; i < daving_time; i++) {
        temp += DP[i];
    }

    long long Ans = temp;
    long long result = 0;

    for (int i = daving_time; i < playing_time; i++) {
        temp -= DP[i-daving_time]; // ���� �սð� ��� ���ְ�
        temp += DP[i]; // �ֱ� ���� ��� �÷���
        if (temp > Ans) {
            Ans = temp; // ���� ���� �� ����� �� ������Ʈ
            result = i - daving_time + 1; // ���� ���۽ð� ������Ʈ
        }
    }

    answer = make_string(result);
    return answer;
}

int main() {

    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> log = { "01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30" };

    //string play_time = { "99:59:59" };
    //string adv_time = { "25:00:00" };
    //vector<string> log = { "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00" };

   /* string play_time = { "50:00:00" };
    string adv_time = { "50:50:50" };
    vector<string> log = { "15:36:51-38:21:49", "10:14:18-15:36:51", "38:21:49-42:51:45" };
    */
    //cout << stoi(log[0].substr(0, 2)) * 3600 + stoi(log[0].substr(3, 2)) * 60 + stoi(log[0].substr(6, 2)) << endl;
    //cout << stoi(log[0].substr(9, 2)) * 3600 + stoi(log[0].substr(12, 2)) * 60 + stoi(log[0].substr(15, 2)) << endl;

    //vector<string> log = { "00:00:03-00:00:07","00:00:05-00:00:09","00:00:00-00:00:06" };
    cout << solution(play_time, adv_time, log) << endl;

    /*cout << DP[3600 - 1] << endl;
    cout << DP[3600] << endl;
    cout << DP[3601] << endl;
    cout << DP[93600 - 1] << endl;
    cout << DP[93600] << endl;
    cout << DP[93601] << endl;*/

    return 0;
}