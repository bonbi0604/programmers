#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
        int n;
        cin >> n;

        unordered_map<string, int>m;
        vector<string>v;
        
        for (int i = 0; i < n; i++) {
	string name, status;
	cin >> name >> status;
	if (status == "enter") m[name] = 1;
	else m[name] = 0;
        }

        for (auto e : m) {
	if (e.second == 1) {
	        v.push_back(e.first);
	}
        }
        sort(v.begin(), v.end(), greater<string>());
        for (auto e : v) cout << e << "\n";



        return 0;
}