#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
using namespace std;

// board_len�� �迭 board�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char Triple(vector<string> Tik) {
    int X = 0, O = 0;
    if (Tik[1][1] != '.') {
        char Center = Tik[1][1];
        
        // �밢�� üũ
        if (Tik[0][0] == Center && Tik[2][2] == Center) {
            if (Center == 'X') X++;
            else O++;
        }
        if (Tik[0][2] == Center && Tik[2][0] == Center) {
            if (Center == 'X')X++;
            else O++;
        }
        // �� �Ʒ�
        if (Tik[0][1] == Center && Tik[2][1] == Center) {
            if (Center == 'X')X++;
            else O++;
        }
        if (Tik[1][0] == Center && Tik[1][2] == Center) {
            if (Center == 'X')X++;
            else O++;
        }
    }
    char guSok_1 = Tik[0][0];
    char guSok_2 = Tik[2][2];
    if (guSok_1 != '.') {
        if (guSok_1 == Tik[0][1] && guSok_1 == Tik[0][2]) {
            if (guSok_1 == 'X')X++;
            else O++;
        }
        if (guSok_1 == Tik[1][0] && guSok_1 == Tik[2][0]) {
            if (guSok_1 == 'X')X++;
            else O++;
        }
    }
    if (guSok_2 != '.') {
        if (guSok_2 == Tik[1][2] && guSok_2 == Tik[0][2]) {
            if (guSok_2 == 'X')X++;
            else O++;
        }
        if (guSok_2 == Tik[2][1] && guSok_2 == Tik[2][0]) {
            if (guSok_2 == 'X')X++;
            else O++;
        }
    }
    if (O == 1 && X == 1) return'F';
    else if (O == 1 && X == 0) return 'O';
    else if (O == 2 && X == 0) return 'O';
    else if (O == 0 && X == 1) return 'X';
    else if (O == 0 && X == 0) return 'R';
}

int solution(vector<string> board) {

    vector<string> Tik;
    int X = 0, O = 0;
    // split
    for (int i = 0; i < board.size(); i++) {
        string str = board[i];
        for (char x : str) {
            if (x == 'X') X++;
            else if (x == 'O') O++;
        }
        Tik.push_back(str);
    }
    //cout << Tik[1][1] << endl;
    // �⺻���� O�� X�� ���� ���� üũ
    if (O - X != 0 && O - X != 1) {
        return 0;
    }
    else {
        if (Triple(Tik) == 'X' && O == X) return 1;
        else if (Triple(Tik) == 'O' && O == X + 1) return 1;
        else if (Triple(Tik) == 'R') return 1;
        else return 0;
    }
}

int main() {

    vector<string> board  = { "OOO", "...", "XXX" };
    cout << solution(board);

    return 0;

}