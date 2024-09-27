#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
void hanoi(int n, int to, int tmp, int from);
void bad(int n, int to, int tmp, int from);

int main() {
        int N;
        cin >> N;
        bad(N, 3, 2, 1);
        cout << cnt << endl;
        hanoi(N, 3, 2, 1);
        return 0;
}

void bad(int n, int to, int tmp, int from) {
        cnt++;
        if (n == 1) {
	return;
        }
        bad(n - 1, tmp, to, from);
        bad(n - 1, to, from, tmp);
        
}

void hanoi(int n, int to, int tmp, int from) {
        cnt++;
        if (n == 1) {
	cout << from << " " << to << "\n";
	return;
        }
        
        hanoi(n - 1, tmp,to,from);
        cout << from << " " << to << "\n";
        hanoi(n - 1, to,from,tmp);
        return;
}