#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char>st;
    //x번 반복
    for(int i=0;i<s.length();i++){
        char ch;
        bool check = true;
        for(char c : s){
            if(c == '('  || c == '{' || c== '[' ) st.push(c);
            else{
                if(c== ')' && st.top() == '(') st.pop();
                else if(c== '}' && st.top() == '{') st.pop();
                else if(c== ']' && st.top() == '[') st.pop();
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check && st.empty()) answer++;
        ch = s[0];
        s = s.substr(1, s.length()-1) + ch;
    }
    return answer;
}