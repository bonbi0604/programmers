#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    string s = number;
    while(k){
        if(s[idx] < s[idx+1]){
            s.erase(idx,1);
            k--;
            if(idx >0) idx--;
        }else idx++;  
        if(idx >= s.length() && k >0){
            s.erase(s.length()-k,k);
            break;
        }
    }
    answer = s;
    return answer;
}