#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>

using namespace std;

int Size(int n, int k) {
    int Size_ = 0;
    while (1) {
        if (n / k == 0) break;
        n = n / k;
        Size_++;
    }
    return Size_; // 계산에 필요한 진수
}

int solution(int n, int k) {
    int answer = 0;
    int KK = Size(n, k);

    string n_k = "";
    for (int i = KK; i > -1; i--) { // k진수로 바꿔줌
        n_k += to_string(int(n / pow(k, i)));
        int Pow = int(n / pow(k, i)) * int(pow(k, i));
        n = n - Pow;
    }

    vector<string> sosu;
    istringstream ss(n_k);
    string stringbuffer;

    while (getline(ss, stringbuffer, '0'))
        if (stringbuffer != "") sosu.push_back(stringbuffer);
    
    for (int i = 0; i < sosu.size(); i++) {

        if (sosu[i] == "2" || sosu[i] == "3") {
            answer++;
            continue;
        }

        for (int j = 2; j < sqrt(stol(sosu[i])); j++) {
            if (stol(sosu[i]) % j == 0) break;
            if (j == int(sqrt(stol(sosu[i])))) answer++;
        }
    }

    return answer;
}

int main() {

    int n = 437674;
    int k = 3;

    cout << solution(n, k);

	return 0;
}