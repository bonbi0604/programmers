#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b){
    return a.second < b.second;
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int>answer;
    vector<pair<int, int>>v, len;
    int start = 0, end = -1, n = sequence.size();
    long sum = 0;
    while(1){
        if(end < n){
            if(sum < k) sum = sum + sequence[++end];
            else if(sum == k){
                v.push_back(make_pair(start, end));
                sum = sum + sequence[++end];    
            }else sum = sum - sequence[start++];
        }
        else{
            while(start != end){
                sum = sum - sequence[start++];  
                if(sum== k) v.push_back(make_pair(start, end));
            }
            if(start == end) break;
        }
    }
    for(int i=0;i<v.size();i++) len.push_back(make_pair(i, v[i].second - v[i].first));
    stable_sort(len.begin(), len.end(), cmp);
    answer.push_back(v[len[0].first].first);
    answer.push_back(v[len[0].first].second);
    return answer;
}