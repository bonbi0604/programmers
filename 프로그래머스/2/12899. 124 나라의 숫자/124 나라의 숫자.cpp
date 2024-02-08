#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int mok, na;
    mok = n;
    while(mok){
        n = mok;
        mok = n/3;
        na = n %3;
        if(n%3==0){
            mok--;
            na = 4;
        }
        n/=3;
        
        answer = to_string(na) + answer ;
    }
    
    
    
    
    return answer;
}