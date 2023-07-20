#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MineCraft
{
    int dia = 0;
    int iron = 0;
    int stone = 0;
    int weight = 0;
};

bool com(MineCraft a, MineCraft b) {
    return a.weight > b.weight;
}

// pick : °î±ªÀÌ °¹¼ö, minerals : ±¤¹° ¼ø¼­
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    vector<MineCraft> minecraft_weight;
    int picks_size = picks[0] + picks[1] + picks[2];

    while(picks_size!=0 && !minerals.empty()){
        int count = 0;
        MineCraft minecraft;
        for (int j = 0; j < 5; j++) {
            count++;
            if (minerals[j] == "diamond") {
                minecraft.dia += 1;
                minecraft.iron += 5;
                minecraft.stone += 25;
                minecraft.weight += 25;
            }
            else if (minerals[j] == "iron") {
                minecraft.dia += 1;
                minecraft.iron += 1;
                minecraft.stone += 5;
                minecraft.weight += 5;
            }
            else {
                minecraft.dia += 1;
                minecraft.iron += 1;
                minecraft.stone += 1;
                minecraft.weight += 1;
            }
            
            // °î±ªÀÌ¸¦ 5¹ø ¾²°Å³ª ¸ðµÎ ÄºÀ» ¶§, ³Ö¾îÁÜ.
            if (count == 5 || count == minerals.size()) {
                minecraft_weight.push_back(minecraft);
                break;
            }
        }
        minerals.erase(minerals.begin(), minerals.begin() + count);
        picks_size--;
    }

    // weight ±âÁØÀ¸·Î ³»¸²Â÷¼ø
    sort(minecraft_weight.begin(), minecraft_weight.end(), com);
    
    for (const auto& Mine : minecraft_weight) {
        if (picks[0] > 0) {
            picks[0]--;
            answer += Mine.dia;
        }
        else if (picks[1] > 0) {
            picks[1]--;
            answer += Mine.iron;
        }
        else if (picks[2] > 0) {
            picks[2]--;
            answer += Mine.stone;
        }
    }

    return answer;
}

// °î±ªÀÌ¸¦ °í¸£¸é ±×°É·Î 5°³¸¦ Ä³¾ßµÈ´Ù.
int main() {

    vector<string> minerals = { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" };
    vector<int> picks = { 0,1,1 };

    /*for (int i = 0; i < minerals.size(); i++) {
        cout << minerals[i] << endl;
    }*/
    cout << solution(picks, minerals);

    return 0;
}