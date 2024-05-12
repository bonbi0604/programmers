#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

vector<int>v(100000,INT_MAX);
set<int>s;
int solution(int N, int number) {
    int cnt = 1;
    for(int i=N;i<v.size();i = i*10+N){ 
        v[i] = cnt++;
        s.insert(i);
    }
    for(int i=1;i<8;i++){
        vector<pair<int,int>>tmp;
        for(auto e : s){
            for(auto k : s){
                if(e+k <100000) tmp.push_back(make_pair(e+k, v[e]+v[k]));
                if(e>k) tmp.push_back(make_pair(e-k, v[e]+v[k]));
                if(e*k <100000) tmp.push_back(make_pair(e*k, v[e]+v[k]));
                if(e/k >0) tmp.push_back(make_pair(e/k, v[e]+v[k]));
            }
        }
        for(auto val : tmp){
            if(val.first >= 100000 || val.second >=9) continue;
            else{
                s.insert(val.first);
                v[val.first] = min(v[val.first], val.second);
            }
        }
    }
    if(v[number] >8) v[number] = -1;
    return v[number];
}
