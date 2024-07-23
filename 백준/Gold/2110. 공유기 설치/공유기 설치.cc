#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m;
        cin >> n >> m;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int s = 0, e = v[n - 1], dis = 0;

        while (e >= s) {
	int mid = (s + e) / 2;
	int cnt = 1, cur = v[0];

	for (int i =1; i < n; i++) {
	        if (v[i] -mid >= cur) {
		cnt++;
		cur = v[i];
	        }
	}
	if (cnt >= m) {
	        s = mid + 1;
	        dis = mid;
	}
	else e = mid - 1;
        }
        
        cout << dis << endl;
        return 0;
}