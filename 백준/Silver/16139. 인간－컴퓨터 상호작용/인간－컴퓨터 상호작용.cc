#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n;
        string s;
        bool check = false;
        cin >> s >> n;
        vector<vector<int>>v(27, vector<int>(s.length() + 1, 0));


        for (int i = 0; i < 27; i++) {
	char ch = 'a' + i;
	for (int j = 1; j <= s.length(); j++) {
	        if (s[j - 1] == ch) {
		v[i][j] = v[i][j - 1] + 1;
	        }
	        else {
		v[i][j] = v[i][j - 1];
	        }
	}
        }
        

        for (int i = 0; i < n; i++) {
	char ch;
	int a, b;
	cin >> ch >> a >> b;

	cout << v[ch-'a'][b + 1] - v[ch-'a'][a] << "\n";
        }
        return 0;
}
