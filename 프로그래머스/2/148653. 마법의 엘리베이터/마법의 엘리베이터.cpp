#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey){
        if(storey %10 >5){
            answer = answer + (10-storey%10);
            storey = storey + (10-storey%10);
        }else if(storey %10==5){
            answer+=5;
            if((storey /10)%10 >=5) storey +=5;   
        }
        else answer = answer + storey%10;
        storey /=10;
    }
    return answer;
}