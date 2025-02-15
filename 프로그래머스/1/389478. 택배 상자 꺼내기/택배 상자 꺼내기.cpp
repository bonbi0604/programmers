#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0, cnt = 1;
    vector<vector<int>>v;
    vector<int>tmp(w);
    int r = n%w==0? n/w : n/w+1;
    for(int i=0;i<r;i++){
        if(i%2==0){
            for(int j=0;j<w && cnt<=n;j++) tmp[j] = cnt++;
            v.push_back(tmp);
        }else{
            for(int j=w-1;j>=0 && cnt <=n;j--) tmp[j] = cnt++;
            v.push_back(tmp);
        }
        tmp.clear();
        tmp.resize(w);
    }
    for(int i=0;i<v.size();i++){
        for(int j=0;j<w;j++){
            if(v[i][j] == num){
                int k= i;
                while(v.size() > k && v[k][j] != 0){
                    answer++;
                    k++;
                }
            }
        }
    }
    return answer;
}