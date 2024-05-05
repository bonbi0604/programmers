#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<bool>visited;

bool cmp(pair<int, int>&a, pair<int,int>&b){
    return a.second < b.second;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, cnt = n-1;
    vector<vector<pair<int, int>>>v;
    v.resize(n);
    for(auto e : costs){ 
        v[e[0]].push_back(make_pair(e[1], e[2]));
        v[e[1]].push_back(make_pair(e[0], e[2]));
    }
    for(auto &e : v) sort(e.begin(), e.end(), cmp);
    
    visited.resize(n, false);
    visited[0] = true;
 
    while(cnt){
        int target = -1, cost = INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(auto e : v[i]){
                    if(e.second < cost && !visited[e.first]){
                        target = e.first;
                        cost = e.second;
                    }
                }
            }
        }
        for(auto &e : v){
            if(find(e.begin(), e.end(), pair<int, int>(target, cost)) != e.end()){
                auto iter = find(e.begin(), e.end(), pair<int, int>(target, cost));
                e.erase(iter);
                break;
            }
        }  
        if(target != -1 && cost != INT_MAX){
            visited[target] = true;
            answer += cost;
            cnt--;
        }
        
    }

    return answer;
}