#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// 기울기를 이용한 풀이 (55.6점)
//long long solution(int w, int h) {
//    long long answer = 1;
//
//    if (w > h) { // 별의미 없습니다. 그냥 항상 직사각형 세워두는 느낌
//        int temp = 0;
//        temp = w;
//        w = h;
//        h = temp;
//    }
//
//    double x = double(h) / double(w); // x = 기울기
//    
//    double hight = 0; // x축으로 1칸 이동할 때, y점의 위치
//    long long postDiv = 0; // 이동하기 전의 점 위치
//    long long _answer = 0; // 잘린 사각형 갯수
//
//    for (int i = 0; i < w; i++) { // w만큼 한칸씩 계속 이동
//
//        hight += x; // 이동할때마다 높이 더해줌
//        double div = 0.0;
//        double mod;
//        mod = modf(hight, &div);
//
//        // 이상하게 99/10 의 경우 10번을 더해주면 mod ==0에 안걸려서 i == w-1을 넣어줌.
//        if (mod == 0 || i == w-1) { // 딱 맞아 떨어진다면(예 : 2*6 사각형), 올라간 높이만 더해줌
//            _answer += int(div) - postDiv; // 마지막 지점 - 이전 시작점
//            //if (i == w - 1) cout << "0_answer : " << _answer << endl;
//        }
//        else { // 나머지가 있다면(예 : 8*12 사각형), 올림해서 더해준다.
//            _answer += int(div) + 1 - postDiv; // 마지막 지점(소수점의 경우 오름) - 이전 시작점
//            //if (i == w - 1) cout << "x_answer : " << int(div) + 1 - postDiv << endl;
//        }
//        postDiv = int(div);
//    }
//    long long w_ = w;
//    long long h_ = h;
//    long long wh = w_ * h_;
//    answer = wh - _answer;
//
//    return answer;
//}

// 정답 코드 (풀이 방식보고 푼 것)
long long solution(int w, int h) {
    long long answer = 1;

    if (w > h) {
        int temp = w;
        w = h;
        h = temp;
    } // 항상 h>w 이게 해줌

    long long w_ = w;
    long long h_ = h;
    long long MAX;
    long long _answer = w_ * h_;

    while (1) {
        if (h % w == 0) {
            MAX = w;
            break;
        }
        int temp = h;
        h = w;
        w = temp % w;
    }

    answer = _answer - (w_ + h_ - MAX);

    return answer;
}

int main() {

    int w;
    int h;
    cin >> w >> h;

    cout << solution(w, h);

    return 0;
}