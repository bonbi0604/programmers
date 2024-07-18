#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

void dfs(int node);
vector<bool>visited;
int n,answer = 0;
int deleteNode = 0;
vector<vector<int>>v;
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n;
        cin >> n;
        v.resize(n);
        visited.resize(n);
        int root = 0;

        for (int i = 0; i < n; i++) {
	int p;
	cin >> p;
	if (p != -1) {
	        v[i].push_back(p);
	        v[p].push_back(i);
	}
	else root = i;
        }
        cin >> deleteNode;
        if (deleteNode == root) cout << 0 << "\n";
        
        else {
	dfs(root);
	cout << answer << "\n";
	}
}

void dfs(int node) {
        visited[node] = true;
        int cnode = 0;
        for (auto e : v[node]) {
	if (!visited[e] && e != deleteNode) {
	        cnode++;
	        visited[e] = true;
	        dfs(e);
	}
        }
        if (cnode == 0) answer++;
        return;
}