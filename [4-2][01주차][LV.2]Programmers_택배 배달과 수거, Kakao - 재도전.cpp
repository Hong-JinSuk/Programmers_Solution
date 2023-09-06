#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Pop(vector<int>& deliveries, vector<int>& pickups) {
    if (!deliveries.empty() && deliveries.back() == 0) {
        deliveries.pop_back();
        return true;
    }
    else if (!pickups.empty() && pickups.back() == 0) {
        pickups.pop_back();
        return true;
    }
    else return false;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    // ��� ���&���� �� ������ ����Ѵ�.
    while (!deliveries.empty() || !pickups.empty()) {
        
        // ���� or ��� �������� �ִٸ� (�ڿ�������)����
        if (Pop(deliveries, pickups)) continue;

        // �� �հ� ����
        int dist = max(deliveries.size(), pickups.size());
        answer += (dist * 2); 

        int de_cap = cap, pi_cap = cap;

        // ����� �� �ְų� ������ �� ���� ��,
        while (de_cap > 0 || pi_cap > 0) {
            if (deliveries.empty()) de_cap = 0;
            if (pickups.empty()) pi_cap = 0;

            //����� �� �ְ�, ����� ���� �ִٸ�
            if (de_cap > 0 && !deliveries.empty()) {
                if (de_cap >= deliveries.back()) {
                    de_cap -= deliveries.back();
                    deliveries.pop_back(); // ��޿Ϸ�
                }
                else {
                    deliveries[deliveries.size() - 1] -= de_cap;
                    de_cap = 0;
                }
            }
            // ������ �� �ְ�, ������ ���� �ִٸ�
            if (pi_cap > 0 && !pickups.empty()) {
                if (pi_cap >= pickups.back()) {
                    pi_cap -= pickups.back();
                    pickups.pop_back();
                }
                else {
                    pickups[pickups.size() - 1] -= pi_cap;
                    pi_cap = 0;
                }
            }
        }
        
    }

    return answer;
}

int main() {

    int n, cap;
    cin >> cap >> n;
    vector<int> deliveries = { 1 };
    vector<int> pickups = { 0,3,0,4,0 };

    cout << solution(cap, n, deliveries, pickups);

    return 0;
}