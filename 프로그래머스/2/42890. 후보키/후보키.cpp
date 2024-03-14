#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    map<int, string>column;
    column[0] = "A";
    column[1] = "B";
    column[2] = "C";
    column[3] = "D";
    column[4] = "E";
    column[5] = "F";
    column[6] = "G";
    column[7] = "H";
    column[8] = "I";
    
    vector<string>ans;
    
    for(int idx =0; idx < relation[0].size();idx++){
        //조합을 만들기 위함
        vector<int>combination(relation[0].size(), 0);
        for(int i=0;i<=idx;i++) combination[i] = 1;
        sort(combination.begin(), combination.end());
        
        //조합 문 안
        do{
             //유일성 만족하는지 개수 세기
            set<string>s;
            s.clear();
            //1개부터~n개 선택시 각 컬럼의 값을 담기 위함. 
            vector<vector<string>>v;
            v.resize(relation.size(), vector<string>(relation[0].size()));
            //컬럼명을 지정해 주기 위한 string 만들기
            string str = "", tmp;
            for(int i=0;i<combination.size();i++){
                //조합에 해당하는 컬럼에 대해서
                if(combination[i] == 1){
                    for(int j=0;j<relation.size();j++){
                        v[j][i]+= relation[j][i];
                    }
                }else continue;
                str += column[i];
            }
            
            // 유니크 한지 set에 넣어보기
            for(int i=0;i<v.size();i++){
                string tmp = "";
                for(int j=0;j<v[i].size();j++){
                    if(v[i][j] !="") tmp += v[i][j];
                }
                s.insert(tmp);
            }
            
            if(s.size() == relation.size()){
                //유니크 하다면
                bool check = true;
                for(int i=0;i<ans.size();i++){
                    for(int j=0;j<ans[i].length();j++){
                        if(str.find(ans[i][j]) == string::npos){ check = true; break; }
                        else check = false;
                    }
                    if(!check)break;
                }
                if(check && str !="") ans.push_back(str);
            }
        }while(next_permutation(combination.begin(), combination.end()));
    }
    
    
    answer = ans.size();
    return answer;
}