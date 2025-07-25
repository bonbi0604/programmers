#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<string>v;
    stringstream ss(s);
    while(getline(ss, answer, ' ')){
        v.emplace_back(answer);
    }
    vector<int>num;
    for(auto e : v) num.emplace_back(stoi(e));
    int max = *max_element(num.begin(), num.end());
    int min = *min_element(num.begin(), num.end());
    answer = "" + to_string(min) + " " + to_string(max);
    return answer;
}