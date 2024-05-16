#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

typedef tuple<int, int,int>edge;
static int n,m;
static vector<long>mdistance;
static vector<edge>edges;

int main(){
    cin >> n >> m;
    mdistance.resize(n+1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX);
    
    for(int i=0;i<m;i++){
        int start, end, time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start, end, time));
    }
    
    mdistance[1] = 0;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);
            
            if(mdistance[start] != INT_MAX && mdistance[end] > mdistance[start]+time){
                mdistance[end] = mdistance[start] + time;
            }
        }
    }
    bool mcycle = false;
    
    for(int i=0;i<m;i++){
            edge medge = edges[i];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);
            
            if(mdistance[start] != INT_MAX && mdistance[end] > mdistance[start]+time){
                mcycle = true;
            }
    }
    if(!mcycle){
        for(int i=2;i<=n;i++){
            if(mdistance[i] == INT_MAX) cout << -1 << endl;
            else cout << mdistance[i] << endl;
        }
    }else cout << -1 << endl;
}