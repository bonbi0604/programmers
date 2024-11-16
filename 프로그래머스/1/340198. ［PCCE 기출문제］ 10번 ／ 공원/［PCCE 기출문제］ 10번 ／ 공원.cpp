#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    vector<vector<int>>v(park.size(), vector<int>(park[0].size()));
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[i].size();j++){
            if(park[i][j] != "-1") v[i][j] = 0;
            else v[i][j] = 1;
        }
    }
    
    for(int i=1;i<v.size();i++){
        for(int j=1;j<v[i].size();j++){
            if(v[i][j] ==0) continue;
            v[i][j] = min(min(v[i-1][j-1], v[i][j-1]), v[i-1][j]) + 1;
        }
    }
    
    int M = -1;
    for(int i=0;i<v.size();i++){
        M = max(*max_element(v[i].begin(), v[i].end()), M);
    }
    sort(mats.begin(), mats.end(), greater<int>());
    for(int i=0;i<mats.size();i++){
        if(M >= mats[i]){
            answer = mats[i];
            break;
        }
    }

    
    return answer;
}