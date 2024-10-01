#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>>v;

int main() {
        int n;
       cin >> n;
       v.resize(n);
       for (int i = 0; i < n; i++) {
               for (int j = 0; j <= i; j++) {
	        int tmp;
	        cin >> tmp;
	        v[i].push_back(tmp);
               }
       }

       for (int i = n - 2; i >= 0; i--) {
               for (int j = 0; j < v[i].size(); j++) {
	       v[i][j] = max(v[i + 1][j], v[i + 1][j + 1]) + v[i][j];
               }
       }

       cout << v[0][0];
        return 0;
}
