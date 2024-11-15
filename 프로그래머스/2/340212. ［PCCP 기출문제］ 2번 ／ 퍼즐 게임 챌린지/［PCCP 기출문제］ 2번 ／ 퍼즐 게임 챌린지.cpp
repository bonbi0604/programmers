#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = INT_MAX;
    vector<pair<int,int>>v;
    
    for(int i=0;i<diffs.size();i++){
        v.push_back({diffs[i], times[i]});
    }
    int s=1, e = *max_element(diffs.begin(), diffs.end());
    
    while(s<=e){
        int tmp = (s+e)/2;
        long long total = 0;
        
        for(int i=0;i<diffs.size();i++){
            if(tmp >= v[i].first){
                total += v[i].second;
            }else{
                total = total + (v[i].first-tmp)*(v[i].second + v[i-1].second) + v[i].second;
            }
            if(total > limit){
                break;
            }
        }
        if(total <= limit){
            answer = min(answer, tmp);
            e = tmp-1;
        }else s = tmp+1;
    }
    return answer;
}