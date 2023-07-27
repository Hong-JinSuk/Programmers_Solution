#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0, cnt = 0;
    long long y_l;

    for (int x = 0; x <= r2; x++) {
        long long y_h = sqrt(pow(r2, 2)-pow(x,2));
        double Y = sqrt(pow(r1, 2)-pow(x,2));
        if (x >= r1) y_l = 0;
        else {
            y_l = Y;
            if (Y - y_l > 0) y_l++;
        }
        if (x == 0) cnt += y_h - y_l + 1;
        if (y_l == 0) cnt++;
        answer += y_h - y_l + 1;
    }

    answer -= cnt / 2;
    return answer * 4;
}

int main() {

    int r1, r2;
    cin >> r1 >> r2;

    cout << solution(r1, r2);

    return 0;
}