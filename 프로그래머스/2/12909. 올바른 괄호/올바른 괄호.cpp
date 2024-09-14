#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s){
    bool answer = true;
    stack<char>st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
        if(st.top()==')'){
            st.pop();
            if(st.size() == 0 || st.top() != '('){
                return false;
            }
            st.pop();
        }
    }
    answer = st.size()==0 ? true : false;
    return answer;
}