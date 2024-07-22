#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void tree(int x);
void changeVal(int s, long x);
long kakeru(int s, int e);

vector<long long>v;
static int  DIV = 1000000007;
int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, k, len, left_node, height = 0;
        cin >> n >> m >> k;
        len = n;

        while (len >= 1) {
	height++;
	len /= 2;
        }
        int length = pow(2, height + 1);
        left_node = length / 2 - 1;

        v.resize(length,1);
        for (int i = left_node + 1; i <= left_node + n; i++) cin >> v[i];
        tree(length - 1);


        for (int i = 0; i < m + k;i++) {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 1) {
	        changeVal(left_node + b, c);
	}
	else if(a==2){
	        cout << kakeru(left_node + b, left_node + c) << "\n";
	}
        }

        return 0;
}

void tree(int x) {
        while (x > 1) {
	v[x / 2] = v[x / 2] * v[x] % DIV;
	x--;
        }
}

void changeVal(int s, long x) {
        //s번째 수를 x로 바꾼다.
        v[s] = x;
        while (s > 1) {
	s /= 2;
	v[s] = (v[s * 2] % DIV) * (v[s * 2 + 1] % DIV)%DIV;
        }
}

long kakeru(int s, int e) {
        long ans = 1;
        while (e >= s) {
	if (s % 2 == 1) {
	        ans = ans * v[s] %DIV;
	        s++;
	}
	if (e % 2 == 0) {
	        ans = ans * v[e] %DIV;
	        e--;
	}
	s /= 2;
	e /= 2;
        }
        return ans;
}