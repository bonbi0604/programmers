#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n, k, cnt = 0;
        cin >> n >> k;
        vector<int>v(n);
        for (int i = n-1; i >=0; i--) {
	cin >> v[i];
        }

        for (int i = 0; i < v.size(); i++) {
	if (v[i] <= k) {
	        cnt += (k / v[i]);
	        k -= v[i] * (k / v[i]);
	}
        }
        cout << cnt << endl;
        return 0;
}
