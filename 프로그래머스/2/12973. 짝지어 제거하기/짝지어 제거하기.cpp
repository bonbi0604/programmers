#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s){
    int answer = 0;
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(st.empty()) st.push(s[i]);
        else{
            if(st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }
}
    answer = st.empty() ? 1 : answer;
    return answer;
}