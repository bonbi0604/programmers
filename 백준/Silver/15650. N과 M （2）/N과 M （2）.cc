#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
        cin.tie(NULL);
        cout.tie(NULL);
        int n,  m;
        cin >> n >> m;
        set<vector<int>>s;
        vector<int>v(n), zero;
        for (int i = 0; i < n; i++) {
	v[i] = i + 1;
        }
        for (int i = 0; i < m; i++) zero.push_back(1);

        do {
	vector<int>tmp;
	for (int i = 0; i < m; i++) {
	        tmp.push_back(v[i]);
	}
	sort(tmp.begin(), tmp.end());
	s.insert(tmp);
        } while (next_permutation(v.begin(), v.end()));

        for (auto e : s) {
	for (auto k : e) {
	        cout << k << " ";
	}
	cout << "\n";
        }

        return 0;
}

