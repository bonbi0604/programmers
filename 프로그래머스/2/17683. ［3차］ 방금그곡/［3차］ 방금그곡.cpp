#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(pair<string, string> a, pair<string, string> b){
    return a.first.length() > b.first.length();
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    map<string, string>hash;
    hash["C"] = "a";
    hash["C#"] = "b";
    hash["D"] = "c";
    hash["D#"] = "d";
    hash["E"] = "e";
    hash["F"] = "f";
    hash["F#"] = "g";
    hash["G"] = "h";
    hash["G#"] = "i";
    hash["A"] = "j";
    hash["A#"] = "k";
    hash["B"] = "l";
    
    string input = "";
    vector<pair<string,string>>w, ans;
    for(int i=0;i<m.length();i++){
        if(m[i] == '#') continue;
        if(hash.find(m.substr(i,2)) != hash.end()) input += hash[m.substr(i,2)];
        else input +=hash[m.substr(i,1)]; 
    }

    for(int i=0;i<musicinfos.size();i++){
        vector<string>v;
        v.clear();
        string tmp, word="";
        stringstream ss(musicinfos[i]);
        while(getline(ss, tmp, ',')) v.push_back(tmp);

        int cnt = (stoi(v[1].substr(0,2)) - stoi(v[0].substr(0,2)))*60 + stoi(v[1].substr(3)) - stoi(v[0].substr(3));
        
        while(cnt){
            for(int i=0;i<v[3].length();i++){
                if(v[3][i] == '#') continue;
                if(hash.find(v[3].substr(i,2)) != hash.end()) word += hash[v[3].substr(i,2)];
                else word +=hash[v[3].substr(i,1)]; 
                cnt--;
                if(cnt ==0) break;
                }
            }
        w.push_back(make_pair(word, v[2]));
    }
    for(auto e : w){
        if(e.first.find(input) != string::npos){
            ans.push_back(pair(e.first, e.second));
        }
    }
    if(ans.size() ==0 ) return answer;
    
    stable_sort(ans.begin(), ans.end(), cmp);
    answer = ans[0].second;    
    return answer;
}