#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

void munion(int a, int b);
int find(int a);
static vector<int>parent;

typedef struct  Edge {
        int s, e, v;
        bool operator > (const Edge& tmp) const {
	return v > tmp.v;
        }
}Edge;

int main() {
        int n, sum = 0;
        cin >> n;
        priority_queue<Edge, vector<Edge>, greater<Edge>>pq;

        for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	        char ch = cin.get();
	        if (ch == '\n') ch = cin.get();
	        int tmp = 0;
	        if (ch >= 'a' && ch <= 'z') tmp = ch - 'a' + 1;
	        else if (ch >= 'A' && ch <= 'Z') tmp = ch - 'A' + 27;
	        sum += tmp;
	        if (i != j && tmp != 0) pq.push(Edge{ i,j,tmp });
	}
        }
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        int useEdge = 0;
        int result = 0;

        while (!pq.empty()) {
	Edge now = pq.top();
	pq.pop();

	if (find(now.s) != find(now.e)) {
	        munion(now.s, now.e);
	        useEdge++;
	        result += now.v;
	}
        }
        if (useEdge != n - 1) {
	cout << -1 << endl;
        }
        else {
	cout << sum - result << endl;
        }
}

int find(int a) {
        if (a == parent[a]) return a;
        else return parent[a] = find(parent[a]);
}
void munion(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) parent[b] = a;
}