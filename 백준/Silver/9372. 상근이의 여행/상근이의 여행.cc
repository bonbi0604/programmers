#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <numeric>
#include <set>

using namespace std;

typedef struct edge {
        int s, e;
}edge;

vector<int>parent;
void munion(int a, int b);
int find(int a);

int main() {
        queue<edge>q;
        int test_case;
        cin >> test_case;

        while (test_case--) {
	int country, airplane, answer = 0;
	cin >> country >> airplane;
	parent.resize(country + 1, 0);
	for (int i = 0; i <= country; i++) parent[i] = i;
	for (int i = 0; i < airplane; i++) {
	        int first, second;
	        cin >> first >> second;
	        edge now;
	        if (first >= second) {
		now.s = second;
		now.e = first;
	        }
	        else {
		now.e = second;
		now.s = first;
	        }
	        if (find(now.s) != find(now.e)) {
		answer++;
		munion(now.s, now.e);
	        }
	}
	cout << answer << endl;

        }

        return 0;
}
int find(int a) {
        if (parent[a] != a) {
	return parent[a] = find(parent[a]);
        }
        else {
	return a;
        }
}

void munion(int a, int b) {
        a = find(a);
        b = find(b);
        if (parent[b] != a) parent[b] = a;
}

