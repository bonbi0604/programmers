#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long>>v(n+1, vector<long>(m+1));
    vector<pair<int,int>>ung;
    for(auto e : puddles) ung.push_back(make_pair(e[1], e[0]));
    v[1][1] = 1;
    
    for(int j=1;j<=n;j++){
        for(int i=1;i<=m;i++){
            if(i==1 && j==1) continue;
            if(find(ung.begin(), ung.end(), pair<int,int>(j,i)) != ung.end()){
                v[j][i] = 0;
                continue;
            }
                v[j][i] = (v[j][i-1]%1000000007 + v[j-1][i]%1000000007)%1000000007;
        }
    }
    return v[n][m];
}