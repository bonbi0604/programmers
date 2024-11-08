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
vector<vector<int>>v;
string str = "";
void dc(int x1, int y1, int size);

int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n;
        cin >> n;
        v.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
	string s;
	cin >> s;
	for (int j = 0; j < n; j++) {
	        v[i][j] = s[j]-'0';
	}
        }
        dc(0,0,n);
        cout << str << endl;
        return 0;
}

void dc(int x, int y, int size) {
        if (size == 1) {
	string tmp = "";
	for (int i = x; i < x+size; i++) {
	        for (int j = y; j < y+size; j++) {
		tmp += to_string(v[i][j]);
	        }
	}
	str = str + tmp;
	return;
        }
        for (int i = x; i < x+size; i++) {
	for (int j = y; j < y+size; j++) {
	        if (v[x][y] != v[i][j]) {
		str += "(";
		dc(x,y, size/2);
		dc(x, y + size/2, size / 2);
		dc(x + size / 2, y, size / 2);
		dc(x + size / 2, y + size / 2, size / 2);
		str += ")";
		return;
	        }
	}
        }
        str = str + to_string(v[x][y]);
        return;
}