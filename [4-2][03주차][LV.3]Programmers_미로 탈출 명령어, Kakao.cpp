#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int len(int x, int y, int r, int c) {
    return abs(x - r) + abs(y - c); // ����ª�� �Ÿ�
}
// n : ����, m : ����, r : ����, c : ����, k : ������ �̵��� �� �ִ� �Ÿ�, Len : �̵��ؾ� �ϴ� �Ÿ�
string move_(int n, int m, int x, int y, int r, int c, int Len, int k, string answer) {
    
    while (k > Len) { // �Ÿ��� ����������
        // �Ʒ��� ������ �� ���� ��(�ֿ켱)
        cout << k << ", " << Len << endl;
        cout << x << ", " << y << endl;
        if (x < n) {
            // ���� ��ġ�� �������� ���ų� �Ʒ����
            if (r <= x && k - 1 >= Len + 1) {
                cout << "down+\n";
                x++; k--; Len++; answer += "d"; continue;
            }
            else {
                cout << "down-\n";
                x++; k--; Len--; answer += "d"; continue;
            }
        }
        // �������� �̵��� �� �ִٸ�
        if (y > 1) { 
            // ���� ��ġ�� �������� ���ų� �����̶��
            if (c >= y && k - 1 >= Len + 1) {
                cout << "left+\n";
                y--; k--; Len++; answer += "l"; continue;
            }
            else {
                cout << "left-\n";
                y--; k--; Len--; answer += '"l'; continue;
            }
        }
        // ���������� �̵��� �� �ִٸ�
        if (y < m) {
            // ���� ��ġ�� �������� ���ų� �������̶��
            if (y >= c && k - 1 >= Len + 1) {
                cout << "right+\n";
                y++; k--; Len++; answer += "r"; continue;
            }
            else {
                cout << "right-\n";
                y++; k--; Len--; answer += "r"; continue;
            }
        }
        // ���� �̵��� �� �ִٸ�
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
    int Len = len(x, y, r, c); // �������� ������ ������ �Ÿ�

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