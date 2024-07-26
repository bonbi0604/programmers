#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, m, k;
long d[202][202];


int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> n >> m >> k;
        for (int i = 0; i <= 200; i++) {
	for (int j = 0; j <= i; j++) {
	        if (j == 0 || j == i) d[i][j] = 1;
	        else {
		d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
		if (d[i][j] > 1000000000) d[i][j] = 1000000001;
	        }
	}
        }
        if (d[n + m][m] < k) {
	cout << -1;
        }
        else {
	while (!(n == 0 && m == 0)) {
	        if (d[n - 1 + m][m] >= k){ cout << "a";
	        n--;
	        }
	        else {
		cout << "z";
		k -= d[n - 1 + m][m];
		m--;
	        }
	}
        }
        
        return 0;
}