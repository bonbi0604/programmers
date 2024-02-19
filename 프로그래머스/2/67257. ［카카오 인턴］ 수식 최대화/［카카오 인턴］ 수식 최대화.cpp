#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <stack>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    //후위 표기법으로 풀기
    long long answer = 0;
    vector<tuple<char,char,char>>rank;
    stack<char>st;
    
    rank.push_back({'-','+','*'});
    rank.push_back({'+','-','*'});
    rank.push_back({'-','*','+'});
    rank.push_back({'*','-','+'});
    rank.push_back({'+','*','-'});
    rank.push_back({'*','+','-'});
    
    for(int i=0;i<rank.size();i++){
        long long sum =0;
        vector<pair<bool,string>>v;
        stringstream ss(expression);
        string number = "";
        stack<long long>number_stack;
        map<char, int>m;
        m[get<0>(rank[i])] = 0;
        m[get<1>(rank[i])] = 1;
        m[get<2>(rank[i])] = 2;
        
        for(char c; ss >> c;){
            if(isdigit(c)) number += c;
            else{
                v.push_back(make_pair(true,number));
                number = "";
                if(st.empty()) st.push(c);
                else{
                    while(!st.empty() && m[st.top()] > m[c]){
                    v.push_back(make_pair(false, to_string(st.top())));
                    st.pop();
                    }
                    st.push(c);
                }
            }
        }   
        if(number.length()>0) v.push_back(make_pair(true, number));
        while(!st.empty()){ 
            v.push_back(make_pair(false, to_string(st.top()))); 
            st.pop();
        }
        
        for(int i=0;i < v.size();i++){
            if(v[i].first) number_stack.push(stol(v[i].second));
            else{
                long a,b;
                a = number_stack.top();
                number_stack.pop();
                b = number_stack.top();
                number_stack.pop();
                if(v[i].second == "42") number_stack.push(a*b);
                if(v[i].second == "43") number_stack.push(a+b);
                if(v[i].second == "45" && i+1 < v.size() && v[i+1].second !="45" ) number_stack.push(b-abs(a));
                else if(v[i].second == "45" && i+1 < v.size() && v[i+1].second =="45" ) {number_stack.push(-(abs(a)+abs(b)));}
                else if(v[i].second =="45") number_stack.push(b-abs(a));
            }
        }
        while(!number_stack.empty()){sum += number_stack.top(); number_stack.pop();}
        answer = max(answer, abs(sum));

    }
    
    return answer;
}