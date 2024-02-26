#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<char>>m;
vector<vector<bool>>visited;
vector<vector<int>>cnt;
queue<pair<int,int>>q;
void bfs(int x, int y);

int solution(vector<string> maps) {
    int start_x, start_y, end_x, end_y, lever_x, lever_y, answer=INT_MAX, lever_cnt = 0;
    m.resize(maps.size()+2, vector<char>(maps[0].length()+2,'X'));
    cnt.resize(maps.size()+2, vector<int>(maps[0].length()+2, -1));
    visited.resize(maps.size()+2, vector<bool>(maps[0].length()+2, true));
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            m[i+1][j+1] = maps[i][j];
            if(m[i+1][j+1] !='X'){
                cnt[i+1][j+1] = INT_MAX;
                visited[i+1][j+1] = false;
            }
            if(m[i+1][j+1] == 'S'){
                cnt[i+1][j+1] = 0;
                start_x = i+1;
                start_y = j+1;
            }
            if(m[i+1][j+1] == 'E'){
                end_x = i+1;
                end_y = j+1;
            }
            if(m[i+1][j+1] == 'L'){
                lever_x = i+1;
                lever_y = j+1;
            }
        }
    }
    visited[start_x][start_y] = true;
    q.push(make_pair(start_x, start_y));
    bfs(start_x, start_y);
    lever_cnt = cnt[lever_x][lever_y];
 
    /////////////////////////////////////////////////////////////////////////////////////////////////
    cnt.clear();
    visited.clear();
    cnt.resize(maps.size()+2, vector<int>(maps[0].length()+2, -1));
    visited.resize(maps.size()+2, vector<bool>(maps[0].length()+2, true));
    
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].length();j++){
            if(m[i+1][j+1] !='X'){
                cnt[i+1][j+1] = INT_MAX;
                visited[i+1][j+1] = false;
            }
        }
    }
    cnt[lever_x][lever_y] = lever_cnt;
    visited[lever_x][lever_y] = true;
    q.push(make_pair(lever_x, lever_y));
    bfs(lever_x, lever_y);
    
    answer = cnt[end_x][end_y]==INT_MAX ? -1: cnt[end_x][end_y];
    return answer;
}
void bfs(int x, int y){
    
        while(!q.empty()){
            q.pop();
            int ddx, ddy;
                for(int i=0;i<4;i++){
                    ddx = x + dx[i];
                    ddy = y + dy[i];
                    if(m[ddx][ddy] !='X' && !visited[ddx][ddy]){
                        visited[ddx][ddy] = true;
                        q.push(make_pair(ddx, ddy));
                        cnt[ddx][ddy] = min(cnt[x][y] + 1, cnt[ddx][ddy]);
                    }
                }

            ddx = q.front().first;
            ddy = q.front().second;
            bfs(ddx, ddy);
        }
    return;
}