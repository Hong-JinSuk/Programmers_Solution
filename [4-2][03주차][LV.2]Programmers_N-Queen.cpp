#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Y[15];

bool isCan(int x) {
	// �̹��� x�࿡ ��ġ�� y��
	for (int check = 0; check < x; check++) {
		// ���� or �밢�� �� �ɸ��ٸ�
		if (Y[check] == Y[x] || abs(Y[check] - Y[x]) == x - check) return false;
	}
	// �ɸ��� �ʴ´ٸ�
	return true;
}

void N_Queen(int x, int n, int& answer) {
	if (x == n) { // ������ ������ٸ�
		answer++;
		return;
	}

	for (int y = 0; y < n; y++) {
		Y[x] = y; // �̹� x�࿡ y�� ��ġ
		if (isCan(x)) // ��ġ�� �� �ִٸ�
			N_Queen(x + 1, n, answer);
	}

}

int solution(int n) {
	int answer = 0;

	N_Queen(0, n, answer);

	return answer;
}

int main() {

	int n;
	cin >> n;

	cout << solution(n);

	return 0;
}