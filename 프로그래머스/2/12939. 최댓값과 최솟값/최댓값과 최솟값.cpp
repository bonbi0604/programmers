#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "", tmp;
    long long a,b;
    vector<int>v;
    stringstream ss(s);
    while(getline(ss, tmp, ' ')) v.push_back(stoi(tmp));
    
    a = *max_element(v.begin(), v.end());
    b = *min_element(v.begin(), v.end());
    answer = to_string(b) + " " + to_string(a);
    return answer;
}