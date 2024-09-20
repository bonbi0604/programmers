#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

long gcd(int a, int b){
    int tmp;
    while(b !=0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
long lcm(int a, int b){
    int tmp = gcd(a,b);
    return (a/tmp*b);
}

int solution(vector<int> arr) {
    int answer = 0;
    queue<int>q;
    sort(arr.begin(), arr.end());
    for(auto e : arr) q.push(e);
    
    while(q.size() !=1){
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();
        int tmp = lcm(a,b);
        q.push(tmp);
    }
    if(!q.empty()) answer = q.front();
    
    return answer;
}