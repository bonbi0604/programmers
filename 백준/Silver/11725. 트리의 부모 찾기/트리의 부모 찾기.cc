#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

void dfs(int node);
vector<int>parent;
vector<bool>visited;
vector<vector<int>>v;
int main() {
        
        ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int n;
        cin >> n;
        v.resize(n + 1);
        parent.resize(n + 1,0);
        visited.resize(n + 1, false);
        n--;
        
        while (n--) {
	int a, b;
	cin >> a >> b;
	v[a].push_back(b);
	v[b].push_back(a);
        }

        dfs(1);
        for (int i = 2; i < parent.size(); i++) cout << parent[i] << "\n";

}

void dfs(int node) {
        visited[node] = true;
        for (auto e : v[node]) {
	if (!visited[e]) {
	        parent[e] = node;
	        dfs(e);
	}
        }
        return;
}