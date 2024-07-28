#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n, mod = 1000000000;
long long d[1000001];
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> n;
        d[1] = 0;
        d[2] = 1;

        for (int i = 3; i <= n; i++) {
	d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
        }
        cout << d[n];
     
        
        return 0;
}