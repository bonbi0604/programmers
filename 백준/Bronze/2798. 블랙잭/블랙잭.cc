#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n,m,total = 0;
vector<int>v;

int main() {
        cin >> n >> m;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 2; i++) {
	for (int j = i + 1; j < n - 1; j++) {
	        for (int k = j + 1; k < n; k++) {
		if (v[i] + v[j] + v[k] <= m) {
		        total = max(total, v[i] + v[j] + v[k]);
		}
		else break;
	        }
	}
        }
        cout << total;
        return 0;
}