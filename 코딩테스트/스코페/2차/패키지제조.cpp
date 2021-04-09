#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    stack <int> s;
    int N,  Q, i, j, upper, lower, stage, stopFlag;
    cin >> N >> Q ;

    vector < vector < int > > dataSet(N+1, vector<int> (N+1,0));
    for(i=0;i<N-1;i++){
        cin >> upper >> lower;
        dataSet[lower][0] ++;
        dataSet[lower][dataSet[lower][0]]=upper;
    }
    for(i=0;i<Q;i++){
        stopFlag = 1;
        cin >> upper >> lower;
        s.push(lower);
        
        while(!s.empty() && stopFlag){
            lower = s.top();
            s.pop();
        
            for(j=1;j<=dataSet[lower][0];j++){
                if(dataSet[lower][j]==upper){
                    cout << "yes\n";
                    stopFlag = -1;
                    break;
                }
                else s.push(dataSet[lower][j]);
            }
        }

        if(stopFlag==1) cout << "no\n";
    }
    return 0;
}

// #include<iostream>

// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N,  Q, i, j, upper, lower, stage, flag;
//     cin >> N >> Q ;

//     int map[50005]={0,};

//     for(i=0;i<N-1;i++){
//         cin >> upper >> lower;
//         if()
//         map[lower] = upper;
//     }
//     for(i=0;i<Q;i++){
//         cin >> upper >> lower;
//         flag=-1;
//         while(map[lower]!=0){
//             if(map[lower]==upper){
//                 flag=1;
//                 break;
//             }
//             lower=map[lower];
//         }
//         if(flag==1) cout << "yes\n";
//         else cout << "no\n";

//     }
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<stack>
// #include<map>
// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N,  Q, i, j, upper, lower, stage, flag;
//     cin >> N >> Q ;

//     map <int, int> package;

//     for(i=0;i<N-1;i++){
//         cin >> upper >> lower;
//         package[lower] = upper;
//     }
//     for(i=0;i<Q;i++){
//         cin >> upper >> lower;
//         flag=-1;
//         while(package.count(lower)){
//             if(package[lower]==upper){
//                 flag=1;
//                 break;
//             }
//             lower=package[lower];
//         }
//         if(flag==1) cout << "yes\n";
//         else cout << "no\n";

//     }
//     return 0;
// }

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     stack <int> s;
//     int N,  Q, i, j, upper, lower, stage, stopFlag;
//     cin >> N >> Q ;

//     vector < vector < int > > dataSet(N+1, vector<int> (N+1,0));
//     for(i=0;i<N-1;i++){
//         cin >> upper >> lower;
//         dataSet[upper][0] ++;
//         dataSet[upper][dataSet[upper][0]]=lower;
//     }
//     for(i=0;i<Q;i++){
//         stopFlag = 1;
//         cin >> upper >> lower;
//         s.push(upper);
        
//         while(!s.empty() && stopFlag){
//             upper = s.top();
//             s.pop();
//             // if(upper == lower){
//             //     cout << "yes\n";
//             //     break;
//             // }
//             for(j=1;j<=dataSet[upper][0];j++){
//                 if(dataSet[upper][j]==lower){
//                     cout << "yes\n";
//                     stopFlag = -1;
//                     break;
//                 }
//                 else s.push(dataSet[upper][j]);
//             }
//         }

//         if(stopFlag==1) cout << "no\n";
//     }
//     return 0;
// }