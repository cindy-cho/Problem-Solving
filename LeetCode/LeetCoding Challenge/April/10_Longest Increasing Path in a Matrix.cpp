// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].

// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

// Input: matrix = [[1]]
// Output: 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
private:
    int ans;
    int c;
    int r;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> vst;
    vector<vector<int>> matrixCpy;

public:

    static bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
        return a.first < b.first;
    }

    void findPath(int x,int y){
        int tmpX,tmpY;
        for(int i=0;i<4;i++){
            tmpX = x+dir[i][0];
            tmpY = y+dir[i][1];
            if(tmpX>=0 && tmpX<r && tmpY>=0 && tmpY<c && matrixCpy[tmpX][tmpY]>matrixCpy[x][y] && vst[tmpX][tmpY]<vst[x][y]+1) {
                vst[tmpX][tmpY] = vst[x][y]+1;
                findPath(tmpX,tmpY);
            }
        }

        if(ans<vst[x][y]) ans = vst[x][y];            
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ans = 0;
        r = matrix.size();
        c = matrix[0].size();
        vst.resize(r, vector<int> (c,1));
        matrixCpy.resize(r,vector<int> (c));
        vector < pair < int , pair <int ,int >>> order(r*c);

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                matrixCpy[i][j] = matrix[i][j];
                order[i*c+j].first = matrix[i][j];
                order[i*c+j].second.first = i;
                order[i*c+j].second.second = j;
            }
        }

        sort(order.begin(),order.end(),cmp);

        for(int i=0;i<r*c;i++){
            if(vst[order[i].second.first][order[i].second.second]==1) {
                findPath(order[i].second.first,order[i].second.second);   
            }
        }

        return ans;
    }
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> matrix{{9,9,4},{6,6,8},{2,1,1}};

    Solution S;

    cout << S.longestIncreasingPath(matrix) << endl;

    
    return 0;
}
