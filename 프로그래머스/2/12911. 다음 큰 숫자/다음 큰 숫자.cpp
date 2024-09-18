#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0, pos,zero=0,one=0,po=1;
    string str = "", tmp;
    while(n){
        str = str + to_string(n%2);
        n/=2;
    }
    if(str.find("10")==string::npos) str += "0";
    pos = str.find("10");
    str[pos] = '0';
    str[pos+1] = '1';
    for(int i=0;i<pos;i++){
        if(str[i]=='0') zero++;
        else one++;
    }
    
    for(int i=0;i<pos;i++){
        if(one){
            str[i] = '1';
            one--;
        }else{
            str[i] = '0';
            zero--;
        }
    }
    
    reverse(str.begin(), str.end());
    for(int i=str.length()-1;i>=0;i--){
        answer = answer + (str[i]-'0')*po;
        po*=2;
    }
    return answer;
}