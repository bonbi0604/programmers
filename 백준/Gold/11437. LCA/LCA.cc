#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>>v;
vector<int>depth;
vector<int>parent;
vector<bool>visited;
int lca(int a, int b);
void bfs(int node);

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        v.resize(n + 1);
        depth.resize(n + 1);
        parent.resize(n + 1);
        visited.resize(n + 1,false);

        for (int i = 0; i < n - 1; i++) {
	//양 방향 저장
	int s, e;
	cin >> s >> e;
	v[s].push_back(e);
	v[e].push_back(s);
        }
        bfs(1); //깊이 구하기
        cin >> m;

        for (int i = 0; i < m; i++) {
	int a, b;
	cin >> a >> b;
	int LCA = lca(a, b);
	cout << LCA << "\n";
        }
        return 0;
}

int lca(int a, int b) {
        if (depth[a] < depth[b]) {
	int temp = a;
	a = b;
	b = temp;
	//값은 반드시 a>b이어야함.
        }
        while (depth[a] != depth[b]) {
	a = parent[a];
        }
        while (a != b) {
	a = parent[a];
	b = parent[b];
        }
        return a;
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
		q.push(next);
		visited[next] = true;
		parent[next] = now;
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