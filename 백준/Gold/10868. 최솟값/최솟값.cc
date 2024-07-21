#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;

void make_tree(int n);
int findValue(int s, int e);

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, len, height = 0, left_node;
        cin >> n >> m;
        len = n;

        while (len > 0) {
	height++;
	len /= 2;
        }

        int tree_size = int(pow(2, height + 1));
        v.resize(tree_size);
        fill(v.begin(), v.end(), 2100000000);
        left_node = tree_size / 2 - 1; //(2^k-1 번째 index참조)

        for (int i = left_node + 1; i <= left_node + n; i++) {
	cin >> v[i];
        }

        make_tree(tree_size - 1);

        for (int i = 0; i < m; i++) {
	int s, e;
	cin >> s >> e;
	cout << findValue(left_node + s, left_node + e) << "\n";
        }

        return 0;
}

void make_tree(int n) {
        while (n > 1) {
	if (v[n / 2] > v[n]) v[n / 2] = v[n];
	n--;
        }
}

int findValue(int s, int e) {
        int tmp = 2100000000;
        while (e >= s) {
	if (s % 2 == 1) {
	        tmp = min(tmp, v[s]);
	        s++;
	}
	if (e % 2 == 0) {
	        tmp = min(tmp, v[e]);
	        e--;
	}
	s /= 2;
	e /= 2;
        }
        return tmp;
}