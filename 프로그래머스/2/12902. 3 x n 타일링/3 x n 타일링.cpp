#include <string>
#include <vector>
#include <iostream>
using namespace std;
long long answer =0, divv = 1000000007;
int solution(int n) {
    vector<long long>v2(2501,0);
    vector<long long>v(2501,0);
    v[1] = 3;
    v2[0] = 2;
    v2[1] = 8;
    for(long long i=2;i<v2.size();i++){
        v2[i] = ((v2[i-1]%divv+divv)*4 - v2[i-2]%divv)%divv;
    }
    for(int i=2;i<v2.size();i++){
        v[i] = ((v[i-1])%divv + (v2[i-1])%divv)%divv;
    }
    answer = v[n/2];
    return answer;
}