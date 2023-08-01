#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>    
using namespace std;

//vector<int> Cpp;
//vector<int> Java;
//vector<int> Python;
//bool isB[50000];
//bool isF[50000];
//bool isJ[50000];
//bool isS[50000];
//bool isP[50000];
//bool isC[50000];
//int Score[50000];
//int index = 0;

//void info_Split(string str) {
//    istringstream ss(str);
//    string stringBuffer;
//    vector<string> x;
//    int cnt = 0;
//    while (getline(ss, stringBuffer, ' ')) {
//        if (stringBuffer != "") {
//            if (stringBuffer == "cpp") Cpp.push_back(index);
//            if (stringBuffer == "java") Java.push_back(index);
//            if (stringBuffer == "python") Python.push_back(index);
//        }
//        if (cnt == 1) {
//            if (stringBuffer == "backend") isB[index] = true;
//            else if (stringBuffer == "frontend") isF[index] = true;
//            else {
//                isB[index] = true;
//                isF[index] = true;
//            }
//        }
//        if (cnt == 2) {
//            if (stringBuffer == "junior") isJ[index] = true;
//            else if (stringBuffer == "senior") isS[index] = true;
//            else {
//                isJ[index] = true;
//                isS[index] = true;
//            }
//        }
//        if (cnt == 3) {
//            if (stringBuffer == "pizza") isP[index] = true;
//            else if (stringBuffer == "chicken") isC[index] = true;
//            else {
//                isP[index] = true;
//                isC[index] = true;
//            }
//        }
//        if (cnt == 4) {
//            Score[index] = stoi(stringBuffer);
//        }
//        cnt++;
//    }
//    index++;
//}
//void query_Split(string str, vector<int> &answer) {
//    istringstream ss(str);
//    string stringBuffer;
//    vector<string> x;
//    int cnt = 0;
//    vector<int> Index;
//    while (getline(ss, stringBuffer, ' ')) {
//        if (cnt==0) {
//            if (stringBuffer == "cpp") Index = Cpp;
//            else if (stringBuffer == "java") Index = Java;
//            else if (stringBuffer == "python") Index = Python;
//            else {
//                for (int j = 0; j < Cpp.size() + Java.size() + Python.size(); j++)
//                    Index.push_back(j);
//            }
//        }
//        if (stringBuffer == "-" || stringBuffer == "and") {
//            cnt++;
//            continue;
//        }
//        if (Index.size() == 0) break;
//        for (int i = 0; i < Index.size(); i++) {
//            if (cnt == 2) {
//                if (stringBuffer == "backend" && !isB[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//                else if (stringBuffer == "frontend" && !isF[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//            }
//            if (cnt == 4) {
//                if (stringBuffer == "junior" && !isJ[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//                else if (stringBuffer == "senior" && !isS[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//            }
//            if (cnt == 6) {
//                if (stringBuffer == "pizza" && !isP[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//                else if (stringBuffer == "chicken" && !isC[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//            }
//            if (cnt == 7) {
//                if (stoi(stringBuffer) > Score[Index[i]]) {
//                    Index.erase(Index.begin() + i);
//                    i--;
//                }
//            }
//        }
//        cnt++;
//    }
//    answer.push_back(Index.size());
//}
//vector<int> solution(vector<string> info, vector<string> query) {
//    vector<int> answer;
//
//    for (int i = 0; i < info.size(); i++) {
//        string str = info[i];
//        info_Split(str);
//    }
//    for (int i = 0; i < query.size(); i++) {
//        string str = query[i];
//        query_Split(str, answer);
//    }
//    return answer;
//}

map<string, map<string,map<string,map<string,vector<int>>>>> Info_tree;

int Binary_serach(vector<int> Time, int target) {
    int left = 0;
    int right = Time.size()-1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (Time[mid] >= target) {
            right = mid - 1;
        }
        else {
            left=mid + 1;
        }
    }

    return Time.size() - left;
}

void info_Split(string str) {
    istringstream ss(str);
    string stringBuffer;
    vector<string> x;
    while (getline(ss, stringBuffer, ' ')) {
        x.push_back(stringBuffer);
    }
    Info_tree[x[0]][x[1]][x[2]][x[3]].push_back(stoi(x[4]));
}
void query_Split(string str, vector<int> &answer) {
    vector<string> x;
    istringstream ss(str);
    string stringBuffer;
    while (getline(ss, stringBuffer, ' ')) {
        x.push_back(stringBuffer);
    }
    int Size = 0;
    for (auto& Lang : Info_tree) {
        if (x[0] == "-" || Lang.first == x[0]) {
            for (auto& Work : Lang.second) {
                if (x[2] == "-" || Work.first == x[2]) {
                    for (auto& Time : Work.second) {
                        if (x[4] == "-" || Time.first == x[4]) {
                            for (auto& Food : Time.second) {
                                if (x[6] == "-" || Food.first == x[6]) {
                                    for (int i = 0; i < Info_tree[Lang.first][Work.first][Time.first][Food.first].size(); i++) {
                                        //cout << "info_tree : " << Info_tree[Lang.first][Work.first][Time.first][Food.first][i] << ", x[7] : " << stoi(x[7]) << endl;
                                        //if (Info_tree[Lang.first][Work.first][Time.first][Food.first][i] >= stoi(x[7])) Size++;
                                    }
                                    sort(Food.second.begin(), Food.second.end());
                                    Size += Binary_serach(Food.second, stoi(x[7]));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    answer.push_back(Size);
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for (int i = 0; i < info.size(); i++) {
        info_Split(info[i]);
    }

    for (int i = 0; i < query.size(); i++) {
        query_Split(query[i], answer);
    }

    return answer;
}

int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

    vector<int> answer = solution(info, query);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    return 0;
}