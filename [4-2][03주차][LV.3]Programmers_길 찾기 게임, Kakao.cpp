#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;

struct  Node
{
    int number = 0; // 노드번호
    int x = 0, y = 0; // 위치
    int left = 0, right = 0; // 다음 자식
};

Node Tree[10001];
int root = 0;

void preorrder(int Root, vector<int>& answer) {
    if (Root == 0) return;
    answer.push_back(Root);
    int left = Tree[Root].left;
    int right = Tree[Root].right;
    preorrder(left, answer);
    preorrder(right, answer);
    return;
}

void postorder(int Root, vector<int>& answer) {
    if (Root == 0) return;
    int left = Tree[Root].left;
    int right = Tree[Root].right;
    postorder(left, answer);
    postorder(right, answer);
    answer.push_back(Root);

    return;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for (int i = 0; i < nodeinfo.size(); i++) {
        int node = i + 1, x = nodeinfo[i][0], y = nodeinfo[i][1];
        pq.push({ y,{x,node} }); // 높은 Level 순
    }
    
    auto Root = pq.top(); pq.pop();
    root = Root.second.second;
    Tree[root].number = root;
    Tree[root].x = Root.second.first;
    Tree[root].y = Root.first;
    // 트리 만듬
    while (!pq.empty()) {
        int cur_root = root;
        auto cur = pq.top(); pq.pop();
        int cur_x = cur.second.first, cur_y = cur.first;
        int cur_num = cur.second.second;
        while (1) {
            if (cur_x < Tree[cur_root].x) {
                if (Tree[cur_root].left == 0) {
                    Tree[cur_root].left = cur_num;
                    Tree[cur_num].number = cur_num;
                    Tree[cur_num].x = cur_x;
                    Tree[cur_num].y = cur_y;
                    break;
                }
                else cur_root = Tree[cur_root].left;
            }
            else {
                if (Tree[cur_root].right == 0) {
                    Tree[cur_root].right = cur_num;
                    Tree[cur_num].number = cur_num;
                    Tree[cur_num].x = cur_x;
                    Tree[cur_num].y = cur_y;
                    break;
                }
                else cur_root = Tree[cur_root].right;
            }
        }
    }
    vector<int> pre;
    preorrder(root, pre);
    vector<int> post;
    postorder(root, post);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}

int main() {

    vector<vector<int>> nodeinfo = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3}, {8,6},{7,2},{2,2} };
    
    vector<vector<int>> answer = solution(nodeinfo);
    for (int i = 0; i < 2; i++) {
        vector<int> Answer = answer[i];
        for (auto Root : Answer) {
            cout << Root << " ";
        }
        cout << endl;
    }
    return 0;
}