#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<bool>>visited;

void discover(int n, int cnt);
void come(int i, int j);
int answer = 0;

int solution(int n) {
    visited.resize(n, vector<bool>(n, false));
    discover(0,n);
    return answer;
}
void come(int i, int j){
    visited[i][j] = true;
    for(int k=0;k<visited.size();k++) visited[i][k] = true;
    for(int k=0;k<visited.size();k++) visited[k][j] = true;

    for(int k=0;k<visited.size();k++){
        if(i-k>=0 && j-k >=0) visited[i-k][j-k] = true;
        if(i-k>=0 && j+k <visited.size()) visited[i-k][j+k] = true;
        if(i+k <visited.size() && j-k>=0) visited[i+k][j-k] = true;
        if(i+k <visited.size() && j+k <visited.size()) visited[i+k][j+k] = true;
    }
}
void discover(int n, int cnt){
    if(cnt ==0){answer++;return;}
    vector<vector<bool>>tmp = visited;
    tmp = visited;
    for(int i=0;i<visited.size();i++){
        if(!visited[n][i]){
            come(n,i);
            discover(n+1,cnt-1);
            visited = tmp;
        }
    }   
    return;
}