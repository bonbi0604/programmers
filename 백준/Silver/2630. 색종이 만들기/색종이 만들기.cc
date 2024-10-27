#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int white = 0, black = 0;
void recur(vector<vector<int>>v, int k, int x, int y);

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;

        vector<vector<int>>v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	        cin >> v[i][j];
	}
        }
        recur(v, n,0,0);
        cout << white << endl;
        cout << black << endl;
       
        return 0;
}
void recur(vector<vector<int>>v, int k, int x, int y) {
        if (k == 1) {
	if (v[x][y] == 0) white++;
	else black++;
	return;
        }
        bool check = false;
        for (int i = x; i < x+k; i++) {
	for (int j = y; j < y+k; j++) {
	        if (v[i][j] != v[x][y]) {
		check = true;
		break;
	        }
	}
        }
        if (check) {
	recur(v, k / 2, x, y);
	recur(v, k / 2, x+k/2, y);
	recur(v, k / 2, x, y+k/2);
	recur(v, k / 2, x+k/2, y+k/2);
        }
        else {
	if (v[x][y] == 0) white++;
	else black++;
        }
        return;
}