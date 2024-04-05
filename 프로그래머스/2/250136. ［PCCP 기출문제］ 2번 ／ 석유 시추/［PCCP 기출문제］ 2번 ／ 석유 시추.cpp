#include <string>
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
vector<vector<int>>v;
vector<vector<bool>>visited;
void search(int n);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int row, col;
map<int, vector<int>>m;

int solution(vector<vector<int>> land) {
    int answer = 0;
    v = land;
    row = land.size();
    col = land[0].size();
    visited.resize(row, vector<bool>(col, false));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++) if(land[i][j] == 0) visited[i][j] = true;
    }
    for(int i=0;i<col;i++) search(i);

    for(int i=0;i<m.size();i++){
        int sum = accumulate(m[i].begin(), m[i].end(), 0);
        answer = max(answer, sum);
    }
    return answer;
}
void search(int n){
    queue<pair<int, int>>q;
    set<int>s;
    for(int i=0;i<row;i++){
        s.clear();
        int cnt =0;
        if(!visited[i][n]){
            q.push(make_pair(i,n));
            s.insert(n);
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y] = true;
                q.pop();
                cnt++;
                for(int j=0;j<4;j++){
                    int ddx = x + dx[j];
                    int ddy = y + dy[j];
                    if(ddx < 0 || ddy <0 || ddx >= row || ddy >= col) continue;
                    if(!visited[ddx][ddy]){
                        s.insert(ddy);
                        q.push(make_pair(ddx,ddy));
                        visited[ddx][ddy] = true;
                    }
                }
            }
        }
        for(auto& k : s) m[k].push_back(cnt);
    }   
    return;
}