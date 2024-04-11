#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    string name = "ACFJMNRT";    
    vector<int>v {0,1,2,3,4,5,6,7};
    do{
        bool check = true;
        string tmp ="";
        for(auto e : v) tmp += name[e];
        for(auto str : data){
            char a, b, condition;
            a = str[0];
            b = str[2];
            condition = str[3];
            int num = str[4]-'0';
            
            int a_pos, b_pos, len;
            a_pos = tmp.find(a);
            b_pos = tmp.find(b);
            len = abs(a_pos-b_pos);
            if(condition=='='){
                if(len-1!=num) check = false;
            }else if(condition=='<'){
                if(len > num) check =false;
            }else if(condition=='>'){
                if(len <= num+1){ check =false;
                }
            }
            if(!check) break;
        }
        if(check) answer++;
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}