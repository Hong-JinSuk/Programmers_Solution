#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long int S[2501];

int XOR(int Begin, int End) {
    int answer;
    for (int i = Begin; i < End; i++) {
        S[i + 1] = S[i] ^ S[i + 1];
    }
    answer = S[End];
    return answer;
}

bool com(const vector<int>& a, const vector<int>& b, int col) {
    if (a[col-1] == b[col-1]) return a[0] > b[0];
    else return a[col-1] < b[col-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    sort(data.begin(), data.end(), [col](const vector<int>& a, const vector<int>& b) {
        return com(a, b, col);
    }); // << 아예몰라서 찾아본 부분.

    /*for (auto a : data) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }*/

    for (int i = row_begin - 1; i < row_end; i++) {
        for (int j = 0; j < data[0].size(); j++) {
            S[i + 1] += data[i][j] % (i + 1);
        }
    }
    
    /*for (int i = row_begin - 1; i < row_end; i++) {
        cout << S[i + 1] << endl;
    }*/

    answer = XOR(row_begin, row_end);

    return answer;
}

int main() {

    vector<vector<int>> data = { {2,2,6},{1,5,10},{4,2,9},{3,8,3} };
    int col = 2, row_begin = 2, row_end = 3;
    
    cout << solution(data, col, row_begin, row_end);

    return 0;
}