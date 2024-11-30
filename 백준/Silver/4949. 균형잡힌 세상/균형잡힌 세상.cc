#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        while (1) {
	string s;
	getline(cin, s);
	if (s.length() == 1 && s[0] == '.') break;
	stack<char>st;
	bool token = true;
	for (int i = 0; i < s.length(); i++) {
	        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
		st.push(s[i]);
	        }
	        if (s[i] == ')') {
		if (st.empty() || st.top() != '(') {
		        token = false;
		}
		else if (st.top() == '(') st.pop();
	        }
	        else if (s[i] == '}') {
		if (st.empty() || st.top() != '{') {
		        token = false;
		}
		else if (st.top() == '{') st.pop();
	        }
	        else if (s[i] == ']') {
		if (st.empty() || st.top() != '[') {
		        token = false;
		}
		else if (st.top() == '[') st.pop();
	        }
	}

	if (!st.empty() || !token)  cout << "no\n";
	else cout << "yes\n";
	while (!st.empty()) st.pop();
        }
        
        return 0;

}