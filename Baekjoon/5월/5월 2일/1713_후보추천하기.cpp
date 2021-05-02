#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct{
    int id;
    int recommend;
    int time;
}candidate;

bool cmp(candidate A, candidate B){
    if(A.id < B.id) return true;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,R,S=0,Input;
    int flag=1;
    int minR,minT,minId;
    cin >> N >> R;
    vector<candidate> frame(N);
    for(int i=0;i<R;i++){
        cin >> Input;
        if(S<N){
            flag = 1;
            for(int j=0;j<S;j++){
                if(frame[j].id==Input){
                    flag = -1;
                    frame[j].recommend ++;
                    break;
                }
            }
            if(flag==1){
                S++;
                frame[S-1].id=Input;
                frame[S-1].recommend=1;
                frame[S-1].time=i;
            }
        }
        else{
            minR = R;
            flag = 1;
            for(int j=0;j<S;j++){
                if(frame[j].id==Input){
                    // cout << "같아서 추천수 증가함 : " << frame[j].id << endl;
                    flag = -1;
                    frame[j].recommend ++;
                    break;
                }
                if(minR > frame[j].recommend) minR = frame[j].recommend;
            }
            if(flag == 1){
                minT = -1;
                for(int j=0;j<S;j++){
                    if(frame[j].recommend == minR){
                        // cout << "여기에 들어옴 : " << 
                        if(minT==-1){
                            minT=frame[j].time;
                            minId=j;
                        }
                        else{
                            if(minT > frame[j].time){
                                minT = frame[j].time;
                                minId=j;
                            }
                        }
                    }
                }
                frame[minId].id = Input;
                frame[minId].time = i;
                frame[minId].recommend = 1;
            }
        }

        // for(int j=0;j<S;j++){
        //     cout << frame[j].id << "," << frame[j].recommend << "," << frame[j].time << endl;
        // }
        // cout << endl << endl;
    }

    sort(frame.begin(),frame.end(),cmp);

    for(int i=0;i<N;i++) cout << frame[i].id << " ";
    return 0;
}