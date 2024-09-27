#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int>v;
void recur(int n, int m);

int main() {
        cin.tie(NULL);
        cout.tie(NULL);
        int n,  m;
        cin >> n >> m;
        recur(n, m);
        return 0;
}

void recur(int n, int m) {        
        if (m ==0) {
	for (auto e : v) {
	        cout << e << " ";
	}
	cout << "\n";
	return;
        }
        for (int i = 1; i <= n; i++) {
	v.push_back(i);
	recur(n, m - 1);
	v.pop_back();
        }
}

