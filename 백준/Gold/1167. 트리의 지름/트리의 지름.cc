#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
vector < vector<pair<int, int>>>v;
vector<bool>visited;
long ans = 0, tmp = 0;
void dfs(int node, int distance);


int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n;
        cin >> n;
        v.resize(n + 1);
        visited.resize(n + 1, false);

        for (int i = 1; i <= n; i++) {
	int start_node, other_node=0, distance=0;
	cin >> start_node;
	while(true) {
	        cin >> other_node;
	        if (other_node != -1) cin >> distance;
	        else break;
	        v[start_node].push_back(make_pair(other_node, distance));
	}
        }
        dfs(1, 0);
        fill(visited.begin(), visited.end(), false);
        dfs(tmp, 0);
        cout << ans << endl;

        return 0;
}

void dfs(int node, int distance) {
        visited[node] = true;
        if (distance > ans) {
	ans = distance;
	tmp = node;
        }
        for (pair<int, int>e : v[node]) {
	if (!visited[e.first]) {
	        dfs(e.first, distance + e.second);
	}
        }
        ans = max(ans, tmp);
        return;
}