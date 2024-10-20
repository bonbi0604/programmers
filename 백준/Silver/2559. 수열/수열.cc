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
       
        int temp, n;
        cin >> temp >> n;
        vector<int>v(temp + 1), s(temp+1);
        for (int i = 1; i <= temp; i++) cin >> v[i];
        for (int i = 1; i <= temp; i++) {
	if (n >= i) {
	        s[i] = s[i - 1] + v[i];
	}
	else {
	        s[i] = s[i - 1] + v[i] - v[i - n];
	}
        }
        cout << *max_element(s.begin()+n, s.end()) << endl;
        
        return 0;
}
