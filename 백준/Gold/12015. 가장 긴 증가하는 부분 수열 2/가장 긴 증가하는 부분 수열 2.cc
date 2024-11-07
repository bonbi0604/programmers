#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
vector<int>v, ans;

int b2search(int n) {
        int start=0, end=ans.size(), mid;

        while (start < end) {
	mid = (start + end) / 2;
	if (ans[mid] >= n) {
	        end = mid;
	}
	else {
	        start = mid + 1;
	}
        }
        return end;
}


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
	cin >> v[i];
        }
        ans.push_back(v[0]);

        for (int i = 0; i < n; i++) {
	if (v[i] > ans.back()) {
	        ans.push_back(v[i]);
	}
	else {
	        int tmp = b2search(v[i]);
	        ans[tmp] = v[i];
	}
        }
        cout << ans.size() << endl;
        return 0;
}
