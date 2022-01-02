#include<iostream>
#include<algorithm>

using namespace std;
bool comp(pair<double, double> A, pair<double, double> B){
    if(A.second==B.second) return A.first<B.first;
    return A.second < B.second;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,ans=0;
    pair<double,double> timetable[100000];
    double endTime=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> timetable[i].first >> timetable[i].second;
    }
    sort(timetable, timetable+N, comp);
    for(int i=0;i<N;i++){
        if(timetable[i].first>=endTime){
            ans++;
            endTime = timetable[i].second;
        }
    }
    cout << ans << "\n";
    return 0;
}