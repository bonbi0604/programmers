#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <deque>
#include <numeric>
#include <unordered_map>
using namespace std;

int Max = -1000000000;
int Min = 1000000000;

void sum_max(deque<int>v, vector<int>calculate,  int cnt);

int main() {
        int n;

        cin >> n;
        deque<int>v;
        vector<int> calculate(4);

        for (int i = 0; i < n; i++) {
	int number;
	cin >> number;
	v.push_back(number);
        }
        for (int i = 0; i < 4; i++) cin >> calculate[i];

        sum_max(v, calculate, n-1);
        cout << Max << endl;
        cout << Min << endl;
        return 0;
}

void sum_max(deque<int>v, vector<int>calculate, int cnt) {
        if (cnt==0) {
	Max = max(Max, v.front());
	Min = min(Min, v.front());
	return;
       }

        vector<int>tmp = calculate;

        int a = v.front();
        v.pop_front();
        int b = v.front();
        v.pop_front();


        for (int i = 0; i < 4; i++) {
	if (tmp[i] > 0) {
	        tmp[i]--;
	        if (i == 0) {
		v.push_front(a + b);
		sum_max(v, tmp, cnt - 1);
		v.pop_front();
		
	        }
	        if (i == 1) {
		v.push_front(a - b);
		sum_max(v, tmp, cnt - 1);
		v.pop_front();
	        }

	        if (i == 2) {
		v.push_front(a * b);
		sum_max(v, tmp, cnt - 1);
		v.pop_front();
	        }
	        if (i== 3) {
		if (a * b < 0) v.push_front(-1 * abs(a) / abs(b));
		else v.push_front(a / b);
		sum_max(v, tmp, cnt - 1);
		v.pop_front();
	        }
	        tmp[i]++;
	}
        }
        v.push_front(b);
        v.push_front(a);

        return;
}