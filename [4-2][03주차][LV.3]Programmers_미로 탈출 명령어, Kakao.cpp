#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int len(int x, int y, int r, int c) {
    return abs(x - r) + abs(y - c); // 가장짧은 거리
}
// n : 세로, m : 가로, r : 가로, c : 세로, k : 앞으로 이동할 수 있는 거리, Len : 이동해야 하는 거리
string move_(int n, int m, int x, int y, int r, int c, int Len, int k, string answer) {
    
    while (k > Len) { // 거리가 맞을때까지
        // 아래로 내려갈 수 있을 때(최우선)
        cout << k << ", " << Len << endl;
        cout << x << ", " << y << endl;
        if (x < n) {
            // 현재 위치가 도착지와 같거나 아래라면
            if (r <= x && k - 1 >= Len + 1) {
                cout << "down+\n";
                x++; k--; Len++; answer += "d"; continue;
            }
            else {
                cout << "down-\n";
                x++; k--; Len--; answer += "d"; continue;
            }
        }
        // 왼쪽으로 이동할 수 있다면
        if (y > 1) { 
            // 현재 위치가 도착지와 같거나 왼쪽이라면
            if (c >= y && k - 1 >= Len + 1) {
                cout << "left+\n";
                y--; k--; Len++; answer += "l"; continue;
            }
            else {
                cout << "left-\n";
                y--; k--; Len--; answer += '"l'; continue;
            }
        }
        // 오른쪽으로 이동할 수 있다면
        if (y < m) {
            // 현재 위치가 도착지와 같거나 오른쪽이라면
            if (y >= c && k - 1 >= Len + 1) {
                cout << "right+\n";
                y++; k--; Len++; answer += "r"; continue;
            }
            else {
                cout << "right-\n";
                y++; k--; Len--; answer += "r"; continue;
            }
        }
        // 위로 이동할 수 있다면
        if (c < n) {
            if (x >= r && k - 1 >= Len + 1) {
                cout << "up+\n";
                x++; k--; Len++; answer += "u"; continue;
            }
            else {
                cout << "up-\n";
                x++; k--; Len--; answer += "u"; continue;
            }
        }
    }

    while (Len--) {
        if (x < r) {
            answer += "d";
            x++;
        }
        else if (y > c) {
            answer += "l";
            y--;
        }
        else if (y < c) {
            answer += "r";
            y++;
        }
        else if (x > r) {
            answer += "u";
            x--;
        }
    }

    return answer;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int Len = len(x, y, r, c); // 시작점과 도착점 사이의 거리

    if (k - Len < 0 || (k - Len) % 2 != 0) return "impossible";

    answer = move_(n, m, x, y, r, c, Len, k, answer);

    return answer;
}

int main() {

    int n, m, x, y, r, c, k;
    cin >> n >> m >> x >> y >> r >> c >> k;
    cout << solution(n, m, x, y, r, c, k);

    return 0;
}