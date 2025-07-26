#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    int start = 0, end = 1, sum=0;
    vector<int>v(n+1);
    for(int i=0;i<=n;i++) v[i] = i;
    
    while(start <= n){
        if(end > n){
            sum -= v[start++];
            continue;
        }
        if(sum <= n){
            if(sum == n) answer++;
            sum += v[end++];
        }else sum -= v[start++];
    }
    
    return answer;
}