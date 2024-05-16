#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string>v;
vector<bool>visited;
int answer = 0;
int diff_alphabet(string now, string target){
    int num = max(now.length(), target.length());
    int count = 0;
    for(int i=0;i<num;i++) if(now[i] != target[i]) count++;
    return count;
}
void dfs(string now, string target, int cnt);

int solution(string begin, string target, vector<string> words) {
    v = words;
    visited.resize(words.size(), false);
    dfs(begin, target, 0);
    return answer;
}

void dfs(string now, string target, int cnt){
    if(now == target){ 
        answer = cnt; 
        return;
    }
    int diff;
    for(int i=0;i<v.size();i++){
        diff = diff_alphabet(now, v[i]);
        if(diff >1 || visited[i]) continue;
        else{
            visited[i] = true;
            dfs(v[i], target, cnt+1);
            visited[i] = false;
        }
    }
    return;
}