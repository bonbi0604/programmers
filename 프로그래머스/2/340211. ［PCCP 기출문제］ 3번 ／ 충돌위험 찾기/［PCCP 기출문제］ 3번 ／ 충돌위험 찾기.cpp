#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <numeric>
using namespace std;
int v[101][101] = {0,};
int answer = 0;

class obj {
public:
    int x, y;
    obj() : x(-1), y(-1) {}
    queue<pair<int, int>> q;
        void move() {
        if(q.empty()) return;
        int destx = q.front().first;
        int desty = q.front().second;
        v[x][y]--;
        if(x != destx){
            if(x > destx) x--;
            else if(x < destx) x++;
        }else{
            if(y > desty) y--;
            else if(y < desty) y++;
        }
        v[x][y]++;
        if (x == destx && y == desty) q.pop();
    }
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<obj> ob;
    set<pair<int,int>>s;
    for (int i = 0; i < routes.size(); i++) {
        int start = routes[i][0];
        obj currentObj;
        currentObj.x = points[start - 1][0];
        currentObj.y = points[start - 1][1];
        v[currentObj.x][currentObj.y]++;
        if(v[currentObj.x][currentObj.y] >1) s.insert({currentObj.x, currentObj.y});
        for (int j = 1;j < routes[i].size(); j++) {
            int end = routes[i][j] - 1;
            currentObj.q.push({points[end][0], points[end][1]});
        }
        ob.push_back(currentObj);
    }
    answer += s.size();
    s.clear();
    while (1) {
        bool check = false;
        set<pair<int, int>> s;
        for (auto& currentObj : ob) {    
            if (!currentObj.q.empty()) {
                currentObj.move();
                s.insert({currentObj.x, currentObj.y});
                check = true;
            }else{
                if(currentObj.x != -1 && currentObj.y != -1){
                v[currentObj.x][currentObj.y]--;
                    currentObj.x = -1;
                    currentObj.x = -1;
                }
            }
        }
        for(auto e : s){
            if(v[e.first][e.second] >1){
                answer++;
            } 
        }
        if (!check) break;
    }
    return answer;
}
