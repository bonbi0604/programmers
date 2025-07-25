#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

void func(vector<int> numbers, long num, int index, int target);
int answer = 0;

int solution(vector<int> numbers, int target) {
    
    func(numbers, 0, 0, target);
    return answer;
}

void func(vector<int> numbers, long num, int index, int target){
    if(index == numbers.size()){
        if(num == target) answer ++;
        return ;
    }
    if(index +1 <= numbers.size()) func(numbers, num + numbers[index], index+1, target);
    if(index +1 <= numbers.size()) func(numbers, num - numbers[index], index+1, target);
    return;
}