#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> A, pair<int,int>B){
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int row,col,paper,wrongColored,minHeight,maxHeight,usedPaper,midHeight,curCol,ans;
    cin >> row >> col;
    minHeight = row;
    maxHeight = row;
    cin >> paper;
    cin >> wrongColored;
    vector<pair<int,int>> wrongPlace(wrongColored);
    for(int i=0;i<wrongColored;i++){
        cin >> wrongPlace[i].first >> wrongPlace[i].second;
        if(wrongPlace[i].first < minHeight) minHeight = wrongPlace[i].first;
    }
    sort(wrongPlace.begin(),wrongPlace.end(),cmp);
    while(minHeight <= maxHeight){
        // cout << "minHeight , maxHeight : " << minHeight << "," << maxHeight << endl;
        usedPaper = 0;
        curCol = wrongPlace[0].second;
        midHeight = (minHeight+maxHeight) / 2;
        // cout << "midHeight : " << midHeight << endl;
        for(int i=0;i<wrongColored;i++){
            if(wrongPlace[i].second <= curCol+midHeight-1) continue;
            else{
                usedPaper++;
                curCol += midHeight;
            }
        }
        if(usedPaper<=paper){
            ans = midHeight;
            maxHeight = midHeight-1;
        }
        else {
            
            minHeight = midHeight+1;
        }
    }
    cout << ans << "\n";
    return 0;
}