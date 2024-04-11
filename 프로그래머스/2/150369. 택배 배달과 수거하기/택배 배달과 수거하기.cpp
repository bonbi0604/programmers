#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<int>start, end;
    for(int i=0;i<deliveries.size();i++){
        start.push(deliveries[i]);
        end.push(pickups[i]);
    }
    int start_box = 0, end_box = 0, len = -1;
    
    while(!(start.empty() && end.empty())){
        while(!start.empty()){
            int num = start.top();
            if(num != 0) len = max(len, int(start.size()));
            start.pop();
            if(num + start_box <= cap) start_box += num;
            else{
                start.push(num-cap+start_box);
                start_box = cap;
                break;
            }
        }
        while(!end.empty()){
            int num = end.top();
            if(num != 0) len = max(len, int(end.size()));
            end.pop();
            if(num + end_box <= cap) end_box += num;
            else{
                end.push(num-cap+end_box);
                end_box = cap;
                break;
            }
        }
        answer += len*2;
        len = -1;
        start_box = end_box = 0;
    }
    answer = answer <0 ? 0 : answer;
    return answer;
}