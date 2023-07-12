#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// ���⸦ �̿��� Ǯ�� (55.6��)
//long long solution(int w, int h) {
//    long long answer = 1;
//
//    if (w > h) { // ���ǹ� �����ϴ�. �׳� �׻� ���簢�� �����δ� ����
//        int temp = 0;
//        temp = w;
//        w = h;
//        h = temp;
//    }
//
//    double x = double(h) / double(w); // x = ����
//    
//    double hight = 0; // x������ 1ĭ �̵��� ��, y���� ��ġ
//    long long postDiv = 0; // �̵��ϱ� ���� �� ��ġ
//    long long _answer = 0; // �߸� �簢�� ����
//
//    for (int i = 0; i < w; i++) { // w��ŭ ��ĭ�� ��� �̵�
//
//        hight += x; // �̵��Ҷ����� ���� ������
//        double div = 0.0;
//        double mod;
//        mod = modf(hight, &div);
//
//        // �̻��ϰ� 99/10 �� ��� 10���� �����ָ� mod ==0�� �Ȱɷ��� i == w-1�� �־���.
//        if (mod == 0 || i == w-1) { // �� �¾� �������ٸ�(�� : 2*6 �簢��), �ö� ���̸� ������
//            _answer += int(div) - postDiv; // ������ ���� - ���� ������
//            //if (i == w - 1) cout << "0_answer : " << _answer << endl;
//        }
//        else { // �������� �ִٸ�(�� : 8*12 �簢��), �ø��ؼ� �����ش�.
//            _answer += int(div) + 1 - postDiv; // ������ ����(�Ҽ����� ��� ����) - ���� ������
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

// ���� �ڵ� (Ǯ�� ��ĺ��� Ǭ ��)
long long solution(int w, int h) {
    long long answer = 1;

    if (w > h) {
        int temp = w;
        w = h;
        h = temp;
    } // �׻� h>w �̰� ����

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