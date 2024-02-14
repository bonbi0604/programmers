#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int row, col, total = 0;
vector<vector<bool>>visited;
vector<vector<char>>m;
vector<int> answer;
queue<pair<int, int>>q;


void bfs(int i, int j, int tot);
bool range(int i, int j);

vector<int> solution(vector<string> maps) {
    
    row = maps.size();
    col = maps[0].length();
    visited.resize(row+2, vector<bool>(col+2, false));
    m.resize(row+2, vector<char>(col+2,'X'));
    bool check = false;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            m[i+1][j+1] = maps[i][j];
            if(m[i+1][j+1] != 'X') visited[i+1][j+1] = true;
            if(m[i+1][j+1] !='X') check = true;
        }
    }
    if(!check){answer.push_back(-1); return answer;}

    
    
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(visited[i][j]){
                visited[i][j] = false;
                total += (m[i][j]-'0');
                bfs(i,j, m[i][j]-'0');
                answer.push_back(total);
                total = 0;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

void bfs(int i, int j, int tot){
    if(visited[i][j+1]) q.push(make_pair(i,j+1));
    if(visited[i][j-1]) q.push(make_pair(i,j-1));
    if(visited[i+1][j]) q.push(make_pair(i+1,j));
    if(visited[i-1][j]) q.push(make_pair(i-1,j));
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        if(!visited[x][y]) q.pop();
        else{
            q.pop();
            visited[x][y] = false;
            bfs(x,y, tot+ (m[x][y]-'0'));
            total += (m[x][y]-'0');
        }
    }
    
    return;
}