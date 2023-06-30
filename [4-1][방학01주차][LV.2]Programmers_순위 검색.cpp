#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<string>

using namespace std;

void ssplit(vector<string> data, vector<string> Split[]) {

	for (int i = 0; i < data.size(); i++) {
		istringstream ss(data[i]);
		string stringBuffer;

		while (getline(ss, stringBuffer, ' ')) {
			if (stringBuffer == "and") {
				continue;
			}
			Split[i].push_back(stringBuffer);
		}
	}

	return;
}

vector<int> solution(vector<string> info, vector<string> query) {
	
	vector<int> answer;
	int Answer;
	int info_size = info.size();
	int query_size = query.size();

	vector<string>* Split_info = new vector<string>[info_size];
	vector<string>* Split_query = new vector<string>[query_size];

	ssplit(query, Split_query);
	ssplit(info, Split_info);
	
	for (int q = 0; q < query_size; q++) { // 질문을 하자..
		bool* iswrong = new bool[info_size];
		for (int i = 0; i < info_size; i++) {
			iswrong[i] = false;
		}
		Answer = 0;
		for (int i = 0; i < info_size; i++) { // 모든 사람들에게~
			for (int k = 0; k < 5; k++) { // 질문의 갯수는 5개
				if (Split_query[q][k] == "-") continue; // - 는 넘어가~
				if (k == 4) { // 숫자는 크거나 같으면 된다.
					if (stoi(Split_info[i][k]) >= stoi(Split_query[q][k])) continue;
				}
				if (Split_query[q][k] != Split_info[i][k]) { // 조건이 안맞으면
					iswrong[i] = true; // 이사람은 글렀음.
					break;
				}
			}
		}
		for (int i = 0; i < info_size; i++) {
			if (!iswrong[i]) Answer++;
		}
		answer.push_back(Answer);
	}

	return answer;
}

int main() {

	vector<string> Info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
	vector<string> Query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };

	vector<int> answer = solution(Info, Query);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}