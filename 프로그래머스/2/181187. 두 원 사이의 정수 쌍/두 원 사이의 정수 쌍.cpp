#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0, r = long(r1)*r1, rr = long(r2)*r2;
    
    for(long long i =1;i<r2;i++){
        long long big = sqrt(rr - i*i);
        long long small = sqrt(r - i*i);
        if(i < r1){
            if(small*small + i*i == r) answer++;
            answer += (big-small);
        }else{
            answer += big;
        }
    }
    answer *=4;
    answer = answer + 4*(r2-r1) + 4;
    return answer;
}