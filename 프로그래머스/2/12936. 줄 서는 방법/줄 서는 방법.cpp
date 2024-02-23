#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> answer, number;
vector<long long>board(21,1);
void recur(long long k);
int m;
vector<int> solution(int n, long long k) {
    board.push_back(0);
    board.push_back(1);
    int count = 2, pos =0;
    m = n;
    for(int i=2;i<=20;i++) board[i] = board[i-1] * i;
    for(int i=0;i<=n;i++) number.push_back(i);
    recur(k);
    return answer;
}

void recur(long long k){
    if(m==0) return;
    long long boarder = board[m] / m;     
    for(int i=1; i<=m; i++){
        if(k<= boarder * i){
            k -= boarder * (i-1);
            m--;
            answer.push_back(number[i]);
            number.erase(number.begin() + i);
            break;
        }
    }
    recur(k);
    return;
}