#include <string>
#include <vector>

using namespace std;

int cnt_one(int n){
    int one=0;
    while(n){
        if(n%2==1) one++;
        n/=2;
    }
    return one;
}

int solution(int n) {
    int answer = 0;
    answer = cnt_one(n);
    
    for(int i=n+1;;i++){
        if(answer == cnt_one(i)) return i;
    }
}