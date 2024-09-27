#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <map>
using namespace std;

int main() {

        cin.tie(NULL);
        cout.tie(NULL);
        map<int, int>m;
        int n, total=0, Max = -1, bean=0, cnt = 2;
        cin >> n;
        vector<int>v;
        for (int i = 0; i < n; i++) {
	int num;
	cin >> num;
	m[num]++;
	if (m[num] > Max) Max = m[num];
	total += num;
	v.push_back(num);
        }

        for (auto e : m) {
	if (cnt == 0) break;
	if (e.second == Max) {
	        cnt--;
	        bean = e.first;
	}
        }
        sort(v.begin(), v.end());
        cout << int(round(double(total)/n)) << "\n";
        cout << v[n / 2] << endl;
        cout << bean << endl;
        cout << abs(v[n - 1] - v[0]) << endl;
       


        return 0;
}