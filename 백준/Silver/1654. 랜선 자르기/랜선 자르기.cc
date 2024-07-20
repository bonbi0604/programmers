#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        long long k, n;
        cin >> k >> n;
        vector<long long>len(k);
        for (int i = 0; i < k; i++) cin >> len[i];
        sort(len.begin(), len.end());
        long long s = 1, e =len[k-1];
        long long ans = 0, tmp=0;
        while (e >= s) {
	long long count = 0, mid = (e + s) / 2;
	if (mid == 0) break;
	for (int i = 0; i < k; i++) {
	        count += len[i] / mid;
	} 
	if (count < n) e = mid - 1;
	else {
	        ans = max(ans, mid);
	        s = mid + 1;
	}
        }
        if (ans == 0) ans = tmp;

        cout << ans << endl;
        return 0;
}