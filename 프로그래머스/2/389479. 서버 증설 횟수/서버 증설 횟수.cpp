#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int>v(players.size());
    for(int i=0;i<players.size();i++){
        v[i] = players[i]/m;
    }
    
    for(int i=0;i<v.size();i++){
        int score = v[i];
        if(score){
            answer += score;
            for(int j=i;j<i+k;j++){
                if(j >= v.size()) break;
                (v[j] - score) > 0 ? v[j]-=score : v[j]=0;
            }
        }
    }
    return answer;
}