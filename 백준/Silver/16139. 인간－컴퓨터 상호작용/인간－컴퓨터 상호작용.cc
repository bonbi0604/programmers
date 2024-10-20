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
        vector<int>v(s.length() + 1,0);

        for (int i = 0; i < n; i++) {
	fill(v.begin(), v.end(), 0);
	char ch;
	int a, b;
	cin >> ch >> a >> b;

	for (int j = 1; j <= s.length(); j++) {
	        if (s[j-1] == ch) {
		v[j] = v[j - 1] + 1;
	        }
	        else {
		v[j] = v[j - 1];
	        }
	}
	cout << v[b+1] - v[a] << "\n";

        }
        
        return 0;
}
