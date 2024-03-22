#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define LIMIT 10000000
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i = begin; i<=end; i++){
        if(i==1){answer.push_back(0); continue;}
        if(i<=LIMIT){
            if(i%2==0){answer.push_back(i/2); continue;}
            if(i%2==1){
                bool prime = true;
                int remain = 0;
                for(int j=2;j<=sqrt(i);j++){
                    if(i%j==0){
                        prime = false;
                        remain = i/j;
                        break;
                    }
                }
                if(prime) answer.push_back(1);
                else answer.push_back(remain);
            }
        }
        else{
            long long box =1;
            bool check = true;
            for(long long j=2;j*j<=i;j++){
                if(i%j==0) box = j;
                if(i%j==0 && i/j <=LIMIT){
                    answer.push_back(i/j);
                    check = false;
                    break;
                }
            }
            if(check){
                answer.push_back(box);
            }
        }
    }
    return answer;
}