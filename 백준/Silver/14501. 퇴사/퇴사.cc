#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n;
vector<int> v, t, p;
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        v.resize(n + 2);
        t.resize(n + 1);
        p.resize(n + 1);

        for (int i = 1; i <= n; i++) {
	cin >> t[i] >> p[i];
        }
        for (int i = n; i > 0; i--) {
	if (i + t[i] > n + 1) v[i] = v[i + 1];
	else {
	        v[i] = max(v[i + 1], v[i + t[i]] + p[i]);
	}
        }
        cout << v[1] << endl;
       
        return 0;
}