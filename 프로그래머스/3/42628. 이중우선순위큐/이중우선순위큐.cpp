#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};

vector<int> solution(vector<string> operations) {
    priority_queue<int>desc;
    priority_queue<int, vector<int>, cmp>asc;
    vector<int> answer;
    int size = 0;
    
    for(auto e : operations){
        stringstream ss(e);
        string ins, value;
        if(e[0] == 'I'){
            size++;
            ss >> ins >> value;
            if(value[0]!='-'){
                desc.push(stoi(value));
                asc.push(stoi(value));
            }
            else{
                value = value.substr(1, value.back());
                desc.push(-1*stoi(value));
                asc.push(-1*stoi(value));
            }   
        }
        if(e == "D 1"){
            if(desc.size() + asc.size() >size) desc.pop();
        }
        if(e == "D -1"){
            if(desc.size() + asc.size() >size) asc.pop();
        }
        
        if(asc.size() + desc.size() == size){
            while(!desc.empty()) desc.pop();
            while(!asc.empty()) asc.pop();
            size = 0;
        }
    }
    
    if(desc.size() + asc.size() == size){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(desc.top());
        answer.push_back(asc.top());
    }    
    return answer;
}