#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, k;
int v[1001][1001];

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> n >> k;
        for (int i = 0; i <= n; i++) {
	v[i][0] = i;
	v[i][0] = 1;
	v[i][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
	for (int j = 1; j < i; j++) {
	        v[i][j] = (v[i - 1][j - 1] + v[i - 1][j])%10007;
	}
        }
        cout << v[n][k] << endl;

        return 0;
}