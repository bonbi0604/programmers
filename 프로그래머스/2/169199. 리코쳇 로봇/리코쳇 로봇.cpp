#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <climits>
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
using namespace std;
vector<vector<char>>v;
vector<vector<bool>>visited;
queue<tuple<int,int,int>>qq;
int bfs();
int solution(vector<string> board) {
    v.resize(board.size()+2, vector<char>(board[0].length()+2,'D'));
    visited.resize(board.size()+2, vector<bool>(board[0].length()+2,true));
    int start= -1, end = -1, answer = 0;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].length();j++){
            v[i+1][j+1] = board[i][j];
            if(v[i+1][j+1] != 'D') visited[i+1][j+1] = false;
            if(v[i+1][j+1] == 'R'){
                start = i+1;
                end = j+1;
                visited[start][end] = true;
                qq.push(make_tuple(start,end,0));
            }
        }
    }
    answer =bfs();
    return answer == INT_MAX ? -1 : answer;
}
int bfs(){
    while(!qq.empty()){
        tuple<int,int,int>tmp = qq.front();
        int x = get<0>(tmp);
        int y = get<1>(tmp);
        int cnt = get<2>(tmp);
        if(v[x][y] == 'G') return cnt;
        qq.pop();
        for(int i=0;i<4;i++){
            if(v[x+dx[i]][y+dy[i]] =='D') continue;
            int ddx = x, ddy = y;

            while(v[ddx+dx[i]][ddy+dy[i]] !='D'){
                ddx +=dx[i];
                ddy +=dy[i];
                
            }
            if(!visited[ddx][ddy]){ 
                visited[ddx][ddy] = true;
                qq.push(make_tuple(ddx, ddy, cnt+1));
            }
        }
    }
    return INT_MAX;
}