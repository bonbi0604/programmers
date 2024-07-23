#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>>v;
vector<int>depth;
int kmax;
int parent[21][100001];
vector<bool>visited;
int lca(int a, int b);
void bfs(int node);

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        v.resize(n + 1);

        for (int i = 0; i < n - 1; i++) {
	int s, e;
	cin >> s >> e;
	v[s].push_back(e);
	v[e].push_back(s);
        }
        depth.resize(n + 1);
        visited.resize(n + 1);
        int tmp = 1;
        kmax = 0;

        while (tmp <= n) {
	//최대 가능 깊이 구하기
	tmp <<= 1;
	kmax++;
        }
        bfs(1);
        for (int i = 1; i <= kmax; i++) {
	for (int j = 1; j <= n; j++) {
	        parent[i][j] = parent[i - 1][parent[i - 1][j]];
	}
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	int ans = lca(a, b);
	cout << ans << "\n";
        }
        return 0;
}
int lca(int a, int b) {
        if (depth[a] > depth[b]) {
	int tmp = a;
	a = b;
	b = tmp;
        }
        for (int k = kmax; k >= 0; k--) {
	if (pow(2, k) <= depth[b] - depth[a]) {
	        if (depth[a] <= depth[parent[k][b]]) {
		b = parent[k][b];
	        }
	}
        }
        for (int k = kmax; k >= 0 && a != b; k--) {
	if (parent[k][a] != parent[k][b]) {
	        a = parent[k][a];
	        b = parent[k][b];
	}
        }
        int lca = a;
        if (a != b) lca = parent[0][lca];
        return lca;
}

void bfs(int node) {
        queue<int>q;
        q.push(node);
        visited[node] = true;
        int level = 1;
        int now_size = 1;
        int cnt = 0;

        while (!q.empty()) {
	int now = q.front();
	q.pop();
	for (int next : v[now]) {
	        if (!visited[next]) {
		visited[next] = true;
		q.push(next);
		parent[0][next] = now;
		depth[next] = level;
	        }
	}
	cnt++;
	if (cnt == now_size) {
	        cnt = 0;
	        now_size = q.size();
	        level++;
	}
        }
}