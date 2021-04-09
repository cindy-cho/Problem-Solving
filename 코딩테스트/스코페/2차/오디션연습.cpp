#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,i,j,start,max=0,currentTime;
    int intTargetTime;
    string targetTime,input;
    cin >> N >> targetTime;
    intTargetTime = stoi(targetTime.substr(0,2))*3600 + stoi(targetTime.substr(3,2))*60 + stoi(targetTime.substr(6,2));
   
    vector<int> playLists(N);

    cin.clear();
    for(i=0;i<N;i++){
        cin >> input;
        playLists[i] = stoi(input.substr(0,2))*60 + stoi(input.substr(3,2));
    }
    
    for(i=0;i<N;i++){
        currentTime = 0;
        for(j=i;j<N-1;j++){
            currentTime+=playLists[j];
            if(currentTime >= intTargetTime) break;
        }

        if(max < (j-i+1)){
            start = i;
            max = j-i+1;
        }
    }

    cout << max << " " << start+1 << "\n";

    return 0;
}

/*
7 00:05:48
02:14
03:34
02:34
03:45
05:43
01:34
02:33



음악의 최대개수 , 가장빠른위치
2 1*/