#include <string>
#include <vector>
#include <cmath>
#include <tuple>
#include <iostream>

using namespace std;


void chunk(string expression, vector<long long>& num, vector<char>& giho) {

    int cnt = 0, index = 0;
    for (int i = 0; i < expression.size(); i++) {
        cnt++;
        if (int(expression[i]) >= 48 && int(expression[i]) <= 57) { // 숫자 x
            if (i == expression.size() - 1) 
                num.push_back(stol(expression.substr(index, cnt)));
            continue;
        }
        else {
            giho.push_back(expression[index+cnt-1]);
            num.push_back(stol(expression.substr(index, --cnt)));
            index += cnt + 1;
            cnt = 0;
        }
    }
    return;
}

int calculate(int operand1, int operand2, char Operator) {
    switch (Operator) {
    case '*':
        return operand1 * operand2;
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    default:
        return 0;
    }
}

void Pri(vector<tuple<char, char, char>>& Operator) {
    vector<char> Giho = { '*','+','-' };
    for (char i : Giho) {
        for (char j : Giho) {
            for (char k : Giho) {
                if (i != j && i != k && j != k) {
                    Operator.push_back({ i,j,k });
                }
            }
        }
    }
}

long long solution(string expression) {
    long long answer = 0;

    vector<tuple<char, char, char>> Operator;
    Pri(Operator);

    for (int i = 0; i < Operator.size(); i++) { // 우선순위 만큼
        vector<long long> num;
        vector<char> Giho;
        chunk(expression, num, Giho);
        int index;
        for (index = 0; index < Giho.size(); index++) { 
            if (get<0>(Operator[i]) == Giho[index]) {
                num[index] = calculate(num[index], num[index + 1], Giho[index]);
                num.erase(num.begin() + index + 1);
                Giho.erase(Giho.begin() + index);
                index--;
            }
        }
        for (index = 0; index < Giho.size(); index++) { 
            if (get<1>(Operator[i]) == Giho[index]) {
                num[index] = calculate(num[index], num[index + 1], Giho[index]);
                num.erase(num.begin() + index + 1);
                Giho.erase(Giho.begin() + index);
                index--;
            }
        }
        for (index = 0; index < Giho.size(); index++) { 
            if (get<2>(Operator[i]) == Giho[index]) {
                num[index] = calculate(num[index], num[index + 1], Giho[index]);
                num.erase(num.begin() + index + 1);
                Giho.erase(Giho.begin() + index);
                index--;
            }
        }
        answer = max(abs(num[0]), answer);
    }

    return answer;
}



int main() {

    string expression = "1*2-99*5"; // 48 ~ 57
    cout << solution(expression);

    return 0;
}