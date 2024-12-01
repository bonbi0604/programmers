#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;


int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n, cnt=0;
        cin >> n;
        vector<int>v(n), tmp;
        unordered_map<int, int>m;
        set<int>s;
        for (int i = 0; i < n; i++) {
	cin >> v[i];
	s.insert(v[i]);
        }
        for (auto e : s) tmp.push_back(e);
        sort(tmp.begin(), tmp.end());
        for(int i=0;i<tmp.size();i++){
	m.insert({ tmp[i], cnt++ });
        }
        for (int i = 0; i < v.size(); i++) {
	cout << m[v[i]] << ' ';
        }
        return 0;
}
