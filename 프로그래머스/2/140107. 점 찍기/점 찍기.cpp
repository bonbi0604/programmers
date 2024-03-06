#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i=0;i<=d;i++){
        long long big = long(d)*long(d), small = long(i)*long(i);
        long long distance = sqrt(big-small);
        if(i%k == 0) answer = answer + distance/k + 1;
    }
    return answer;
}