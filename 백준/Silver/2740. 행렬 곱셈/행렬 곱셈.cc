#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

        int n1, m1;
        cin >> n1 >> m1;
        vector<vector<int>>row(n1);

        for (int i = 0;i < n1;i++) {
                for (int j = 0;j < m1;j++) {
                        int num;
                        cin >> num;
                        row[i].push_back(num);
                }
        }
        int n, m;
        cin >> n >> m;
        vector<vector<int>>col(n);

        for (int i = 0;i < n;i++) {
                for (int j = 0;j < m;j++) {
                        int num;
                        cin >> num;
                        col[i].push_back(num);
                }
        }
        vector<vector<int>>answer(n1, vector<int>(m));
      
        for (int i = 0;i < n1;i++) {
                for (int j = 0;j < m;j++) { 
                        for (int k = 0;k < m1;k++) {
                                answer[i][j] += row[i][k] * col[k][j];
                        }
                }
        }

        for (auto e : answer) {
                for (auto k : e) {
                        cout << k << " ";
                }
                cout << endl;
        }

        return 0;
}