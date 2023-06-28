#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
bool isvisited[8];
char kakao[8] = { 'A','C','F','J','M','N','R','T' };
//char kakao[4] = { 'A','C','F','J'};
string photo;
int answer;

void Search(int Len, vector<string> data, string photo) {

	if (Len == sizeof(kakao)) {
		for (int i = 0; i < data.size(); i++) {
			char F = data[i][0];
			char S = data[i][2];
			int f = photo.find(F);
			int s = photo.find(S);
			int FS = abs(f - s) - 1;
			char giho = data[i][3];
			int dist = data[i][4] - '0';
			
			if (giho == '=' && FS != 0) return;
			if (giho == '<' && FS >= dist) return;
			if (giho == '>' && FS <= dist) return;
		}
		//cout << photo << endl;
		answer++;
		return;
	}

	
	for (int i = 0; i < sizeof(kakao); i++) {
		if (isvisited[i]) continue;
		isvisited[i] = true;
		photo += kakao[i];
		Search(Len + 1, data, photo);
		photo.erase(photo.size() - 1);
		isvisited[i] = false;
	}

}

int solution(int n, vector<string> data) {
	photo = "";
	answer = 0;
	fill(isvisited, isvisited + 8, false);
	Search(0, data, photo);
	return answer;

}

int main() {

	int n;
	cin >> n;
	vector<string> Data = { "N~F=0", "R~T>2" };
	cout<< solution(n, Data);
}