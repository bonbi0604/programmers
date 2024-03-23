#include <string>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;
vector<char>v;
vector<bool>visited;
int ans = INT_MAX;
void search(string add, string name, int pos, int cnt);
int solution(string name) {
    int answer = 0;
    string tmp="";
    visited.resize(name.length(), false);
    for(int i=0;i<name.length();i++) if(name[i] =='A') visited[i] = true;
    for(int i=0;i<name.length();i++) tmp +="A";
    v = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    search(tmp,name,0,0);
    return answer = ans;
}
void search(string add, string name, int pos, int cnt){
    string s = add;
    int w = 0, len = name.length();
    for(int i=0;i<v.size();i++){
        if(!visited[pos] && name[pos]==v[i]){
            w = min(i, 26-i);
            s[pos] = v[i];
            visited[pos]= true;
            break;
        }
    }
    if(s==name){
        ans = min(ans, cnt+w);
        return;
    }
    int position, plus;
    for(int i=0;i<len-1;i++){
        if(pos-i>=0) position=pos-i;
        else position=len-i+pos;
        
        if(pos+i<len) plus = pos+i;
        else plus = pos+i-len;

        
        if(!visited[position]){
            search(s, name, position, cnt + w + i);
            visited[position] = false;
        }
        
        if(!visited[plus]){
            search(s, name, plus, cnt + w + i);
            visited[plus] = false;
        }
    }
    return;   
}