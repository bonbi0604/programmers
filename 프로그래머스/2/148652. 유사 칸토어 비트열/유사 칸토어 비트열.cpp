#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int number, answer=0;
void dfs(int cnt, long long l, long long r, long long idx, int cur_value);
int solution(int n, long long l, long long r) {
    number = n;
    dfs(0,l-1,r-1,0,1);
    return answer;
}
void dfs(int cnt, long long l, long long r, long long idx, int cur_value){
    if(cnt == number){
        if( l <= idx && idx <= r)answer += cur_value;
        return;
    }
        if(cur_value == 1){
            for(int i=0;i<5;i++){
                if(idx*5+i >r || i==2) continue;
                dfs(cnt+1, l, r, idx*5+i, 1);
            }
        }
    return;
}