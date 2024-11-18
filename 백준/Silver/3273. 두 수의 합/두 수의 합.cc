#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <queue>
#include <numeric>
using namespace std;


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n, k, ans = 0;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> k;

        sort(v.begin(), v.end());
        int s = 0, e = v.size() - 1;

        while (s < e) {
	if (v[s] + v[e] > k) {
	        e--;
	}
	else if (v[s] + v[e] < k) {
	        s++;
	}
	else {
	        ans++;
	        s++;
	}
        }
        cout << ans << endl;
        
        return 0;
}
