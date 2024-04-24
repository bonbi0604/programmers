#include <iostream>
#include <queue>

using namespace std;

void bfs();

static int Sender[] = { 0,0,1,1,2,2 };
static int Receiver[] = { 1,2,0,2,0,1 };
// a, b의 용량만 있으면 C의 용량이 고정되므로 2개로만 체크 가능

static bool visited[201][201];
static bool answer[201];
static int now[3];

int main() {
        cin >> now[0] >> now[1] >> now[2];
        bfs();

        for (int i = 0; i < 201; i++) {
	if (answer[i]) cout << i << " ";
        }
}

void bfs() {
        queue<pair<int, int>>q;
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        answer[now[2]] = true;

        while (!q.empty()) {
	pair<int, int>p = q.front();
	q.pop();
	int a = p.first;
	int b = p.second;
	int c = now[2] - a - b;
	//c는 전체 물의 양에서 a, b를 뺀 것
	
	for (int k = 0; k < 6; k++) {
	        int next[] = { a,b,c };
	        next[Receiver[k]] += next[Sender[k]];
	        next[Sender[k]] = 0;


	        //대상 물통의 용량보다 물이 많아 넘칠 때
	        if (next[Receiver[k]] > now[Receiver[k]]) {
		next[Sender[k]] = next[Receiver[k]] - now[Receiver[k]];
		next[Receiver[k]] = now[Receiver[k]];
	        }

	        if (!visited[next[0]][next[1]]) {
		visited[next[0]][next[1]] = true;
		q.push(make_pair(next[0], next[1]));
		if (next[0] == 0) answer[next[2]] = true;
	        }

	}
        }
}