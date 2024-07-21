#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

static vector<long> tree;
long getSum(int s, int e);
void changeVal(int index, long val);
void setTree(int i);

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, k;
        cin >> n >> m >> k;
        int treeheight = 0;
        int len = n;

        while (len != 0) {
	len /= 2;
	treeheight++;
        }

        int treesize = int(pow(2, treeheight + 1));
        tree.resize(treesize);
        int leftnodestartindex = treesize / 2 - 1;

        for (int i = leftnodestartindex + 1; i <= leftnodestartindex + n; i++) {
	cin >> tree[i];
        }
        setTree(treesize - 1);

        for (int i = 0; i < m + k; i++) {
	long a, s, e;
	cin >> a >> s >> e;

	if (a == 1) {
	        changeVal(leftnodestartindex + s, e);
	}
	else if (a == 2) {
	        s = s + leftnodestartindex;
	        e = e + leftnodestartindex;
	        cout << getSum(s, e) << "\n";

	}
        }

        return 0;
}

long getSum(int s, int e) {
        long partSum = 0;
        while (s <= e) {
	if (s % 2 == 1) {
	        partSum += tree[s];
	        s++;
	}
	if (e % 2 == 0) {
	        partSum += tree[e];
	        e--;
	}
	s /= 2;
	e /= 2;

        }
        return partSum;
}
void changeVal(int index, long val) {
        long diff = val - tree[index];

        while (index > 0) {
	tree[index] = tree[index] + diff;
	index /= 2;
        }
}

void setTree(int i) {
        while (i != 1) {
	tree[i / 2] += tree[i];
	i--;
        }
}