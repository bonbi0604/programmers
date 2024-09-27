#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string s = ""; // 전역 문자열

void rechange(int start, int len); // 재귀 함수 선언

int main() {
    int n;

    // EOF 처리. 파일 끝까지 계속 입력을 받음.
    while (cin >> n) {
        int length = static_cast<int>(pow(3, n)); // pow의 결과를 정수로 변환
        s = string(length, '-'); // 길이에 맞춰 문자열 초기화

        // 칸토어 집합 변환 시작
        rechange(0, length);

        // 결과 출력
        cout << s << endl;
        s = ""; // 다시 초기화 (다음 입력 대비)
    }

    return 0;
}

// 칸토어 집합 재귀적 변환 함수
void rechange(int start, int len) {
    if (len == 1) return; // 길이가 1일 경우 재귀 종료

    int third = len / 3; // 1/3 크기 계산
    // 중간 구간을 공백으로 채움
    for (int i = start + third; i < start + 2 * third; i++) {
        s[i] = ' ';
    }

    // 좌측과 우측 구간에 대해 재귀 호출
    rechange(start, third); // 좌측 구간
    rechange(start + 2 * third, third); // 우측 구간
}