#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[5001];

int solution(int n) {
    int answer = 0;

    dp[0] = 1;
    for (int i = 2; i <= n; i+=2) {
        dp[i] += dp[i - 2] * 3;
        for (int j = i - 2; j >= 0; j -= 2) {
            dp[i] += dp[j-2] * 2;
        }
        if (dp[i] > 1000000007) dp[i] %= 1000000007;
    }
    answer = dp[n] % 1000000007;
    return answer;
}

int main() {

    int n;
    cin >> n;
    cout << solution(n);

}