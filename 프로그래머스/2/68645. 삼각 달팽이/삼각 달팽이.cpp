#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[2] = {0,1};
int dy[2] = {1,0};

vector<int> solution(int n) {
    vector<vector<int>>v(n, vector<int>(n,-1));
    vector<int> answer;
    int k = n;
    int sad = 200;
    int pos_x = 0, pos_y = 0, number = 1, recur = n*n; 
    bool check = true;
    
        while(recur--){
            if(v[pos_x][pos_y] == -1) v[pos_x][pos_y] = number++;

        if(check){
            if(pos_x + dy[0] < k ){
                pos_x +=dy[0];
                pos_y +=dx[0];
        }
        else{
            if(pos_y + dx[1] < k && v[pos_x + dx[0]][pos_y +dx[1]] == -1){
                pos_x +=dy[1];
                pos_y +=dx[1];
            }
            else check = false;
        }     
    }else{
        if(v[pos_x -1][pos_y -1] == -1){
                pos_x--;
                pos_y--;
        }
        else {
            k--;
            check = true;

        }
    }
}

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}
