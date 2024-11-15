#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    sort(wallet.begin(), wallet.end(), greater<int>());
    int answer = 0;
    
    while(1){
        sort(bill.begin(), bill.end(), greater<int>());
        if(wallet[0] >= bill[0] && wallet[1] >= bill[1]) break;
        if(wallet[0] < bill[0] || wallet[1] < bill[0]) bill[0]/=2;    
        answer++;
    }
    
    return answer;
}