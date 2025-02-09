#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>>v;
vector<bool>visited;
vector<int>ans;
int cnt = 0;
void dfs(int n);

int main() {
        int n, e, start;
        cin >> n >> e >> start;
        v.resize(n + 1);
        visited.resize(n + 1, false);
        ans.resize(n + 1, 0);
       
        for (int i = 0;i < e;i++) {
                int a, b;
                cin >> a >> b;
                v[a].push_back(b);
                v[b].push_back(a);
        }
        for (int i = 1;i <= n;i++) sort(v[i].rbegin(), v[i].rend());
        visited[start] = true;
        dfs(start);
        for (int i = 1;i <= n;i++) cout << ans[i] << "\n";
        return 0;
}

void dfs(int n) {
        ans[n] = ++cnt;
        for (auto e : v[n]) {
                if (!visited[e]) {
                        visited[e] = true;
                        dfs(e);
                }
        }
}