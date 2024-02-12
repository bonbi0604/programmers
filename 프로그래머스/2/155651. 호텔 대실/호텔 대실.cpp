#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    string tmp1, tmp2;
    vector<pair<string, string>>start, end;
    vector<pair<int,int>>vmin;

    for(auto k : book_time){
        int cnt =0;
        for(auto str : k){
            stringstream ss(str);
            getline(ss, tmp1, ':');
            getline(ss, tmp2, ':');
            if(cnt%2==0) start.push_back(make_pair(tmp1, tmp2));
            else{
                if(stoi(tmp2)+10 >=60){
                    int hour, min;
                    hour = stoi(tmp1) + 1;
                    min = stoi(tmp2) -50;
                    end.push_back(make_pair(to_string(hour), to_string(min)));
                }
                else {
                    tmp2 = to_string(stoi(tmp2)+10);
                    end.push_back(make_pair(tmp1, tmp2));
                }
            }
            cnt++;
            }
        }
    
    for(int i=0;i<start.size();i++){
        int start_minute = stoi(start[i].first) * 60 + stoi(start[i].second);
        int end_minute = stoi(end[i].first) * 60 + stoi(end[i].second); 
        vmin.push_back(make_pair(start_minute, end_minute));
        //cout << start_minute <<" " << end_minute << endl;
    }
    sort(vmin.begin(), vmin.end());
    
    vector<vector<pair<int, int>>>v;
    

    for(auto k : vmin){
        bool check = true;
            for(int i=0;i<v.size();i++){
                if(k.first >= v[i].back().second){
                    v[i].push_back(make_pair(k.first,k.second));
                    check = false;
                    break;
                    }
            }
            if(check){
            vector<pair<int,int>>tmp;
            tmp.push_back(make_pair(k.first, k.second));
            v.push_back(tmp);
            }
        }
    answer = v.size();
    return answer;
}