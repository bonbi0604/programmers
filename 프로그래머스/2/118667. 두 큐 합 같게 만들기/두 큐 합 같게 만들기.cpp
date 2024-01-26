#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum1 = 0, sum2 = 0, top = -1, len;
    len = max(queue1.size(), queue2.size()) *4;
    vector<pair<long, long>>v;  
    queue<long>q1, q2;
    for(auto k : queue1){sum1 += k; q1.push(k);}
    for(auto k : queue2){sum2 += k; q2.push(k);}
    while(len--){
        if(sum1 > sum2){
            top = q1.front();
            q2.push(top);
            q1.pop();
            sum1 -= top;
            sum2 += top;
        }else if(sum1 < sum2){
            top = q2.front();
            q1.push(top);
            q2.pop();
            sum2 -= top;
            sum1 += top;
        }else break;  
        answer++;
        if((sum1+sum2)%2!=0 || q1.empty() || q2.empty()) return -1;
    }
    if(len == -1) answer = -1;
    return answer;
}