#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        cin >> m;
        for (int i = 0; i < m; i++) {
	//index번호를 기준으로 줍시다.
	int target, s = 0, e = n - 1;
	bool check = false;
	cin >> target;

	while (e>=s) {
	        int mid = (s + e) / 2;
	        if (v[mid] == target) {
		check = true;
		break;
	        }
	        else if (v[mid] > target) {
		e = mid - 1;
	        }
	        else if (v[mid] < target) {
		s = mid + 1;
	        }
	}
	if (check) cout << 1 << " ";
	else cout << 0 << " ";
        }


        return 0;
}

