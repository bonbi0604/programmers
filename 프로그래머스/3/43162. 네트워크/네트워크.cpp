#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
vector<int>flag;
vector<bool>visited;
vector<vector<int>>v;

int find(int a){
    if(a == flag[a]) return a;
    else return flag[a] = find(flag[a]);
}
void unionfunc(int a, int b){
    a = find(a);
    b = find(b);
    if( a!=b) flag[b] = a;
}
void dfs(int a);
int solution(int n, vector<vector<int>> computers) {
    v.resize(n+1);
    flag.resize(n+1);
    visited.resize(n+1, false);
    for(int i=1;i<=n;i++) flag[i] = i;
    
    //연결리스트로 만들기 (1부터시작~n)
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(i==j) continue;
            if(computers[i][j] == 1){
                v[i+1].emplace_back(j+1);
                }
            }
        }
    for(int i=1;i<v.size();i++) dfs(i);
    set<int>s;
    for(auto e : flag) s.insert(e);
    s.erase(0);
    return s.size();
}
void dfs(int a){
    visited[a] = true;
    
    for(auto e : v[a]){
        if(!visited[e]){
            //union find 실행
            unionfunc(a,e);
            visited[e] = true;
            dfs(e);
        }
    }
    return;
}