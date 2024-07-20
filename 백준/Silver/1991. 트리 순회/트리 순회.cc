#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

static int n;
static int tree[26][2];
void pre(int now);
void in(int now);
void post(int now);
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> n;

        for (int i = 0; i < n; i++) {
	char node_char, left, right;
	cin >> node_char >> left >> right;
	int node = node_char - 'A';

	if (left == '.') tree[node][0] = -1;
	else tree[node][0] = left - 'A';
	if (right == '.') tree[node][1] = -1;
	else tree[node][1] = right - 'A';
        }

        pre(0);
        cout << endl;
        in(0);
        cout << endl;
        post(0);
        cout << endl;

        
        return 0;
}

void pre(int now) {
        if (now == -1) return;

        cout << (char)(now + 'A');
        pre(tree[now][0]);
        pre(tree[now][1]);
}
void in(int now) {
        if (now == -1) return;

        in(tree[now][0]);
        cout << (char)(now + 'A');
        in(tree[now][1]);
}
void post(int now) {
        if (now == -1) return;

        post(tree[now][0]);
        post(tree[now][1]);
        cout << (char)(now + 'A');
}