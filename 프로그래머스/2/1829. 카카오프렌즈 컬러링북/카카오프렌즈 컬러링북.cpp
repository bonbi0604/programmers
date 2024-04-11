#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> v = picture;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    auto range = [&](int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    };

    auto search = [&](int x, int y) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visited[x][y] = true;
        cnt++;

        while (!q.empty()) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if (range(nx, ny) && !visited[nx][ny] && v[nx][ny] == v[x][y]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
        return cnt;
    };

    int number_of_area = 0;
    int max_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visited[i][j]) {
                max_area = max(search(i, j), max_area);
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_area;
    return answer;
}