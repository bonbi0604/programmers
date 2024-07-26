#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

static int n, q;
long f[21], s[21];
bool visited[21] = { false, };



int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> n >> q;
        f[0] = 1;

        for (int i = 1; i <= n; i++) {
	f[i] = f[i - 1] * i;
        }
        if (q == 1) {
	long k;
	cin >> k;
	for (int i = 1; i <= n; i++) { // 결정하려는 순열의 자리
	        for (int j = 1, cnt = 1; j <= n; j++) {
		if (visited[j]) continue;
		if (k <= cnt * f[n - i]) {
		        //k가 현재 범위에 해당할 경우 현재 숫자 j를
		        // i번째 위치에 배치함.
		        //k가 현재 범위 내에 있는지 확인
		        //cnt * f[n-i] 는 현재 자리 이후에 남은 자리에 대한 가능한 모든 수열의 수
		        k -= ((cnt - 1) * f[n - i]);
		        //k를 현재 범위의 시작점으로 조정.
		        s[i] = j;
		        //i번째 위치에 숫자 j를 배치.
		        visited[j] = true;
		        break;
		}
		cnt++;
	        }
	}
	for (int i = 1; i <= n; i++) cout << s[i] << " ";
        }
        else {
	long k = 1;
	for (int i = 1; i <= n; i++) {
	        cin >> s[i];
	        long cnt = 0;
	        for (int j = 1; j < s[i]; j++) {
		if (visited[j])continue;
		else cnt++;
	        }
	        k += cnt * f[n - i];
	        visited[s[i]] = true;
	}
	cout << k << "\n";
        }
        

        return 0;
}