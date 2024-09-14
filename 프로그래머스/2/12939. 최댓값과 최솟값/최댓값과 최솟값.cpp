#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<int>v;
    while(getline(ss, answer, ' ')){
        v.push_back(stoi(answer));
    } 
    answer = "";
    answer = answer + to_string(*min_element(v.begin(), v.end())) + " " +to_string(*max_element(v.begin(), v.end()));
    return answer;
}