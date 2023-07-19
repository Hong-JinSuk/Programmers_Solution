#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//bool isSquare(int row, int col, int Max, vector<vector<int>> board) {
//    for (int i = row; i < row + Max; i++) {
//        for (int j = col; j < col + Max; j++) {
//            if (board[i][j] == 0) return false;
//        }
//    }
//    return true;
//}
//
//int solution(vector<vector<int>> board) {
//    int Max, board_row = board.size(), board_col = board[0].size();
//    Max = min(board_col, board_row);
//   
//    for (int cnt = Max; cnt > 0; cnt--) {
//        for (int col = 0; col <= board_col - cnt; col++) {
//            for (int row = 0; row <= board_row - cnt; row++) {
//                if (isSquare(row, col, cnt, board)) return cnt * cnt;
//            }
//        }
//    }
//
//    return 0;
//}

int Board[1005][1005] = { 0 };

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int Max, board_row = board.size(), board_col = board[0].size();
   
    for (int col = 0; col < board_col; col++) {
        for (int row = 0; row < board_row; row++) {
            if (board[row][col] == 0) continue;
            else {
                // Board에 쓸 row와 col / Board의 가로세로 첫번재는 모두 0으로두고 시작
                int row_ = row + 1, col_ = col + 1; 
                if (Board[row_ - 1][col_ - 1] == 0) {
                    Board[row_][col_] = 1;
                    answer = max(answer, Board[row_][col_]);
                }
                else {
                    // 왼쪽대각, 위, 아래 중 가장작은거보다 1크게 해줌.
                    Board[row_][col_] = min(min(Board[row_ - 1][col_], Board[row_][col_ - 1]), Board[row_ - 1][col_ - 1]) + 1;
                    answer = max(answer, Board[row_][col_]);
                }
            }
        }
    }


    return answer * answer;
}

int main() {

    vector<vector<int>> board = { {0,0,0,1,1,1},{0,0,0,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1 }, { 1,1,1,1,1,1 } };

    cout << solution(board);

    return 0;
}