#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

bool cmp(string a, string b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        set<string>s;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
	string str;
	cin >> str;
	s.insert(str);
        }
        vector<string>v;
        for (auto e : s) v.push_back(e);
        sort(v.begin(), v.end(), cmp);
        for (auto e : v) cout << e << "\n";

        return 0;
}
