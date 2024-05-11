#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    return a < b;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int,int>>v;
    for(auto e : routes) v.push_back(make_pair(e[0],e[1]));
    vector<bool>visited(v.size(), false);
    sort(v.begin(), v.end(), cmp);
    
    for(int i=0;i<v.size();i++){
        int start, end;
        if(!visited[i]){
            start = v[i].first;
            end = v[i].second;
            visited[i] = true;
        }else continue;
        
        for(int j=i+1;j<v.size();j++){
            if(!visited[j] && v[j].first >= start && v[j].second <=end){
                start = v[j].first;
                end = v[j].second;
                visited[j] = true;
                continue;
            }
            if(!visited[j]){
                if(v[j].second >= start && v[j].second <= end) visited[j] = true;
                if(v[j].first >=start && v[j].first <= end) visited[j] = true;
            }
        }
        answer++;
    }

    return answer;
}