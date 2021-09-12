#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define endl '\n'
typedef long long ll;

using namespace std;

typedef struct{
    int a;
    int b;
    int used;
}info;

// struct compare{
//     bool operator()(info A,info B){
//         if(A.a==B.a) return A.b < B.b;
//         return A.a > B.a;
//     }
// };

bool cmp(info A, info B){
    if(A.a==B.a) return A.b > B.b;
    return A.a < B.a;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    int answer = 0;
    cin >> N >> M;

    vector<info> waiting(N);
    vector<info> bus(M);
    // priority_queue <info, vector<info>, compare> buspq;
    queue <info> tmpq;
    for(int i=0;i<N;i++) {
        cin >>waiting[i].a >> waiting[i].b ;
        waiting[i].used = 0;
    }
    sort(waiting.begin(),waiting.end(),cmp);
    for(int i=0;i<M;i++){
        cin>>bus[i].a >> bus[i].b;
        bus[i].used = 0;
    }
    sort(bus.begin(),bus.end(),cmp);
    if(waiting[0].a > bus[M-1].a){
        cout << "0\n";
        return 0;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(bus[j].used == 1) continue;
            if(bus[j].a >=waiting[i].a && bus[j].b <= waiting[i].b){
                answer ++;
                bus[j].used=1;
                waiting[i].used = 1;
                break;
            }
        }
    }
     for(int i=0;i<N;i++){
         if(waiting[i].used==1) continue;
        for(int j=0;j<M;j++){
            if(bus[j].used == 1) continue;
            if(bus[j].a >=waiting[i].a && bus[j].b <= waiting[i].b){
                answer ++;
                bus[j].used=1;
                waiting[i].used = 1;
                break;
            }
        }
    }

    cout << answer << endl;
    // for(int i=0;i<N;i++){
    //     cout << waiting[i].a << " , " << waiting[i].b << endl;
    // }
    // while(!buspq.empty()){
    //     nowBus = buspq.top();
    //     buspq.pop();
    //     cout << nowBus.a << " , " << nowBus.b << endl;
    // }
    // while(!waitpq.empty())
    // {
    //     nowWait = waitpq.top();
    //     waitpq.pop();
    //     while(!tmpq.empty()){
    //         busTmp = tmpq.front();
    //         tmpq.pop();
    //         if(busTmp.a>=nowWait.a) buspq.push(busTmp);
    //     }
    //     while(!buspq.empty()){
    //         nowBus = buspq.top();
    //         buspq.pop();
    //         if(nowBus.a >= nowWait.a && nowBus.b <= nowWait.b){
    //             answer ++;
    //             break;
    //         }
    //         if(nowBus.a >= nowWait.a){
    //             tmpq.push(nowBus);
    //         }
    //     }
    // }
 
    return 0;
}