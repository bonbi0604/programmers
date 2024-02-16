#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long>v(1001,0);
    for(int i=0;i<weights.size();i++) v[weights[i]]++;
    
    int start = 100;
    while(start <=1000){
        if(v[start] == 0){start++; continue;}
        long long end = start+1, cnt = 0, same =0;
        while(end <=1000){
            bool check = false;
            if(v[end] == 0){end++; continue;}
            if(start *2 == end*2 || start *3 == end*3 || start*4 == end*4){check = true; }
            if(start *3 == end*2 || start *3 == end*3 || start*3 == end*4){check = true; }
            if(start *4 == end*2 || start *4 == end*3 || start*4 == end*4){check = true; }
            if(check) cnt += v[start] * v[end];
            end++;
        }
        answer += cnt + (v[start]*(v[start]-1)/2);
        start++;
    }
    return answer;
}
