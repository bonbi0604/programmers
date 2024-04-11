#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

long long gcd(long long a, long long b);
double lcm(long long a, long long b);
vector<string> solution(vector<vector<int>> line) {
    vector<string>answer;
    set<pair<long,long>>s;
    for(long long i=0;i<line.size()-1;i++){
        for(long long j=i+1;j<line.size();j++){
            vector<double>v1, v2;
            for(int k=0;k<3;k++){
                v1.push_back(line[i][k]);
                v2.push_back(line[j][k]);
            }
            if(v1[0]*v2[1] - v1[1]*v2[0] ==0) continue;
            double x = (v1[1]*v2[2] - v1[2]*v2[1])/(v1[0]*v2[1]-v1[1]*v2[0]);
            double y = (v1[2]*v2[0] - v1[0]*v2[2])/(v1[0]*v2[1]-v1[1]*v2[0]);
            if(x - long(x)==0 && y-long(y)==0) s.insert(make_pair(x, y));
        }
    }
    long xleft, xright, yup, ydown, row, col, x, y,pos=0;
    set<pair<long,long>>::iterator iter = s.begin();
    xleft = xright = iter->first;
    yup = ydown = iter->second;
    
    for(auto e : s){
        xleft = min(xleft, e.first);
        xright = max(xright, e.first);
        yup = max(yup, e.second);
        ydown = min(ydown, e.second);
    }
    if(xleft <0 && xright <0) row = abs(xleft)-abs(xright)+1;
    else row = xright - xleft+1; 
    if(ydown <0 && yup <0) col = abs(ydown)-abs(yup)+1;
    else col = yup - ydown+1;
    
    answer.resize(col);
    for(long long i=0;i<col;i++){
        string str = "";
        for(long long j=0;j<row;j++) str+=".";
        answer[i] = str;
    }
    for(auto e : s) answer[yup-e.second][e.first-xleft] = '*';
    return answer;
}
long long gcd(long long a, long long b){
    long long tmp;
    while(b !=0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
double lcm(long long a, long long b){
    return (double(a)*b)/gcd(a,b);
}