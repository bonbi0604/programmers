#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int time = 0, cnt = 0, pos =0, answer = health;
    time = attacks[attacks.size()-1][0];
    
    for(int i=1;i<=time;i++){
        if(i != attacks[pos][0]){
            cnt++;
            if(cnt == bandage[0]){
                if(answer + bandage[1] + bandage[2] >=health) answer = health;
                else answer += bandage[1] + bandage[2];
                cnt = 0;
            }else{
                if(answer + bandage[1] >= health) answer = health;
                else answer +=bandage[1];
            }
        }else{
            answer -= attacks[pos][1];
            pos++;
            cnt = 0;
            if(answer <=0) return -1;
        }
    }
    return answer;
}