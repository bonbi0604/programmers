#include <string>
#include <vector>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    //9시 58분 -> 10시 08분
    // 958 -> 1008
    // 9, 58 
    // 10 08
    for(int i=0;i<schedules.size();i++){
        int count = startday;
        int hour, min;
        hour = schedules[i]/100;
        min = schedules[i]%100;
        bool check = true;
        for(int j=0;j<7;j++){
            int tar_hour, tar_min;
            tar_hour = timelogs[i][j]/100;
            tar_min = timelogs[i][j]%100;
            if(count !=6 && count!=7 && hour*60+min+10 < tar_hour*60+tar_min){
                check = false;
                break;
            }
            count = (count)%7+1;
        }
        if(check) answer++;
    }
    return answer;
}