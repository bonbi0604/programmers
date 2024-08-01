#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n;
vector<int> a, l, r;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        a.resize(n);

        for (int i = 0; i < n; i++) cin >> a[i];

        l.resize(n);
        l[0] = a[0];
        int result = l[0];

        for (int i = 1; i < n; i++) {
	l[i] = max(a[i], l[i - 1] + a[i]);
	result = max(result, l[i]);
        }

        r.resize(n);
        r[n - 1] = a[n - 1];

        for (int i = n - 2; i >= 0; i--) {
	r[i] = max(a[i], r[i + 1] + a[i]);
        }

        for (int i = 1; i < n - 1; i++) {
	int temp = l[i - 1] + r[i + 1];
	result = max(result, temp);
        }
        cout << result << "\n";
       
        return 0;
}