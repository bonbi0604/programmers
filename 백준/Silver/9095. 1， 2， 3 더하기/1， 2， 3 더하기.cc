#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
int answer = 0;
void search(int n, int tot);

int main() {
        int num;
        cin >> num;
        vector<int>v(num, 0);
        for (int i = 0; i < num; i++) cin >> v[i];
        for (int i = 0; i < num; i++) {
	search(v[i], 0);
	cout << answer << endl;
	answer = 0;
        }
        return 0;
}

void search(int n, int tot) {
        if (n == tot) {
	answer++;
	return;
        }
        else {
	for (int i = 1; i <= 3; i++) {
	        if(tot+i <=n) search(n, tot + i);
	}
        }
        return;
}