#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Y[15];

bool isCan(int x) {
	// 이번에 x축에 설치한 y가
	for (int check = 0; check < x; check++) {
		// 직선 or 대각선 에 걸린다면
		if (Y[check] == Y[x] || abs(Y[check] - Y[x]) == x - check) return false;
	}
	// 걸리지 않는다면
	return true;
}

void N_Queen(int x, int n, int& answer) {
	if (x == n) { // 끝까지 만들었다면
		answer++;
		return;
	}

	for (int y = 0; y < n; y++) {
		Y[x] = y; // 이번 x축에 y를 설치
		if (isCan(x)) // 설치할 수 있다면
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