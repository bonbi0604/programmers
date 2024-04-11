#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp{
    bool operator()(const pair<double, double>&a, const pair<double, double>&b){
        return a.first > b.first;
    }
};

int solution(vector<vector<int>> targets) {
    int answer = 1;
    priority_queue<pair<double,double>, vector<pair<double, double>>, cmp>pq;
    for(auto e : targets) pq.push(make_pair(e[0], e[1]));
    
    double a = pq.top().first + 0.5;
    double b = pq.top().second - 0.5;
    pq.pop();
    
    while(!pq.empty()){
        if(b >= pq.top().first+0.5){
            if(b >= pq.top().second-0.5){
                b = pq.top().second-0.5;
            }
            if(pq.top().first+0.5 >= a){
                a = pq.top().first+0.5;
            }
        }else{
            answer++;
            a = pq.top().first+0.5;
            b = pq.top().second-0.5;
        }
        pq.pop();
    }
    return answer;
}