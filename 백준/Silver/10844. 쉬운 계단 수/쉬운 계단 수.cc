#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n;
long long d[101][11];
long mod = 1000000000;
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        for (int i = 1; i <= 9; i++) d[1][i] = 1;

        for (int i = 2; i <= n; i++) {
	d[i][0] = d[i - 1][1];
	d[i][9] = d[i - 1][8];
	for (int j = 1; j <= 8; j++) {
	        d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1])%mod;
	}
        }
        long sum = 0;
        for (int i = 0; i < 10; i++) {
	sum = (sum + d[n][i]) % mod;
        }
        cout << sum << endl;
       
        return 0;
}