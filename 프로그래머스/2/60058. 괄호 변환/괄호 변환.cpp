#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string recur(string s);
string solution(string p) {
    string answer = "";
    answer = recur(p);
    return answer;
}

string recur(string s){
    if(s=="") return s;
    string u,v, tmp="";
    stack<char>st;
    bool vcheck = true, ucheck = true;
    int left =0, right = 0, pos;
    
    for(int i=0;i<s.length();i++){
        if(s[i] == '(') left++;
        else right++;
        
        if(left == right){
            pos = i;
            break;
        }
    }
    u = s.substr(0,pos+1);
    v = s.substr(pos+1);
    // u, v 분리
    
    // 올바른 u,v 판단
    for(auto e : u){
        if(e=='(') st.push(e);
        else{ 
            if(st.empty()){ucheck = false; break;}
            else st.pop();
        }
    }
    while(!st.empty()) st.pop();
    
    if(ucheck) u = u + recur(v);
    else{
        tmp += "(";
        tmp = tmp + recur(v);
        tmp +=")";
        for(int i=1;i<u.length()-1;i++){
            if(u[i] == '(') tmp+=")";
            else tmp +="(";
        }
    }
    if(ucheck) tmp = u + tmp;
    return tmp;
}