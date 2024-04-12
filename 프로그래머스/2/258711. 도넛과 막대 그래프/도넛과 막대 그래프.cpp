#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
vector<vector<int>>v(1000001);
int donut = 0, makdae = 0, both = 0,rep = -1, fir;
void dfs(int start_node);

vector<int> solution(vector<vector<int>> edges) {
    vector<int>answer(4);
    set<int>s;
    map<int, int>m;
    int top = -1;
    for(auto &e : edges){ 
        v[e[0]].push_back(e[1]);
        m[e[1]]++;
        s.insert(e[0]);
    }
    for(auto e : s){
        if(m.find(e) == m.end() && v[e].size() >=2){
            rep = e;
            break;
        }
    }
    for(auto start_node : v[rep]){
        fir = start_node;
        dfs(start_node);
    }  
    answer[0] = rep;
    answer[1] = donut;
    answer[2] = makdae;
    answer[3] = both;
    return answer;
    
}

void dfs(int start_node){
    if(v[start_node].size() >1){ both++; return;}
    if(v[start_node].empty()){ makdae++; return;}
    if(v[start_node][0] == fir){ donut++; return;}
    if(v[start_node].size()==1){
        for(auto e : v[start_node]){
            if(e == fir){
                donut++;
                return;
            }
            dfs(e);
        }
    }
    return;
}








