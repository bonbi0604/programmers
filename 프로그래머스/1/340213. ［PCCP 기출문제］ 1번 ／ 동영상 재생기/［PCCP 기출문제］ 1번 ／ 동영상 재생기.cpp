#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int time =0;

    time = stoi(video_len.substr(0,2)) * 60 + stoi(video_len.substr(3,2));
    int start_time = stoi(op_start.substr(0,2)) * 60 + stoi(op_start.substr(3,2));
    int end_time = stoi(op_end.substr(0,2)) * 60 + stoi(op_end.substr(3,2));
    int pos_time = stoi(pos.substr(0,2)) * 60 + stoi(pos.substr(3,2));
    
    for(int i=0;i<commands.size();i++){
        if(start_time <= pos_time && pos_time < end_time){
            pos_time = end_time;
        }
        if(commands[i] == "prev"){
            if(pos_time <10) pos_time =0;
            else pos_time -= 10;
        }else{
            if(pos_time + 10 > time){
                pos_time = time;
            }else{
                pos_time +=10;
            }
        }
        if(start_time <= pos_time && pos_time < end_time){
            pos_time = end_time;
        }
        
    }
    int mm = pos_time/60;
    int ss = pos_time - mm*60;
    if(mm <10){
        answer = answer + "0" +to_string(mm) + ":";
    }else answer = answer + to_string(mm) + ":";
    
    if(ss <10){
        answer = answer + "0" +to_string(ss);
    }else answer = answer + to_string(ss);
    
    
    
    return answer;
}