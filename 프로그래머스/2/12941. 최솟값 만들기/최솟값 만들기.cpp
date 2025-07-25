#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B){
    long long answer = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), less<int>());
    for(int i=0;i<A.size();i++){
        answer = answer + A[i] * B[i];
    }
    
    return answer;
}