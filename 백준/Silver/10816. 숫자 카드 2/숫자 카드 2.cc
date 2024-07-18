#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        map<int, int>maps;
        int n,m;
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) {
	cin >> v[i];
	maps[v[i]]++;
        }
        cin >> m;
        vector<int>v2(m);
        for (int i = 0; i < m; i++) {
	int tmp;
	cin >> tmp;
	auto itor =maps.find(tmp);
	if (itor != maps.end()) cout << itor->second << " ";
	else cout << 0 << " ";
        }

}