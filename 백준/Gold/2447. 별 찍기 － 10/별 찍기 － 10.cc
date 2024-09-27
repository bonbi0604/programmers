#include <iostream>
#include <vector>
using namespace std;

void drawStars(vector<vector<char>>& board, int x, int y, int n) {
        if (n == 1) {
	board[x][y] = '*';
	return;
        }

        int div = n / 3;
        // 3x3 블록에서 각 구역에 대해 재귀적으로 호출
        for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	        // 중간 부분(1,1)일 경우 공백으로 처리
	        if (i == 1 && j == 1) continue;
	        drawStars(board, x + i * div, y + j * div, div);
	}
        }
}

int main() {
        int N;
        cin >> N;

        // N x N 크기의 배열 초기화 (공백으로 채우기)
        vector<vector<char>> board(N, vector<char>(N, ' '));

        // 패턴 그리기 시작
        drawStars(board, 0, 0, N);

        // 결과 출력
        for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	        cout << board[i][j];
	}
	cout << endl;
        }

        return 0;
}