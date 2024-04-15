#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    string from, to;
    map<string, int>point, mapping;
    map<int, string>re;
    map<string, vector<int>>arr;
    vector<int>v(friends.size());
    
    for(int i=0;i<friends.size();i++){ 
        mapping[friends[i]] = i;
        re[i] = friends[i];
        arr[friends[i]].resize(friends.size());
    }
    for(auto e : mapping){
        int k = mapping[e.first];
        arr[e.first][k] = -1;
    }
    
    for(auto e : gifts){
        stringstream ss(e);
        ss >> from >> to;
        arr[from][mapping[to]]++;
        point[from]++;
        point[to]--;
    }
    
    for(auto e : arr){
        for(int i=0;i<e.second.size();i++){
            if(e.second[i] == -1) continue;
            else{
                if(e.second[i] > arr[re[i]][mapping[e.first]]){
                    v[mapping[e.first]]++;
                    e.second[i] = -1;
                    arr[re[i]][mapping[e.first]] = -1;
                    continue;
                }
                if(e.second[i] < arr[re[i]][mapping[e.first]]){
                    v[mapping[re[i]]]++;
                    e.second[i] = -1;
                    arr[re[i]][mapping[e.first]] = -1;
                    continue;
                }
                if(e.second[i] == arr[re[i]][mapping[e.first]]){
                    if(point[e.first] > point[re[i]]){ 
                        v[mapping[e.first]]++;
                        e.second[i] = -1;
                        arr[re[i]][mapping[e.first]] = -1;
                    }
                    else if(point[e.first] < point[re[i]]){
                        v[mapping[re[i]]]++;
                        e.second[i] = -1;
                        arr[re[i]][mapping[e.first]] = -1;
                    }
                    else if(point[e.first] == point[re[i]]){
                        e.second[i] = -1;
                        arr[re[i]][mapping[e.first]] = -1;
                    }
                }
            }
        }
    }

    
    int answer = *max_element(v.begin(), v.end());
    return answer;
}