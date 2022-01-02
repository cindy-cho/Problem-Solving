#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T,W,idx=0,cnt=0,input,tree=1,len,total=0;
    int tree1=0,tree2=0;
    list <pair<int,int>> lt;
    cin >> T >> W;
    vector <int> plum(T);
    for(int i=0;i<T;i++){
        cin >> input;
        if(tree!=input){
            total+=cnt;
            if(tree==1) {
                tree1+=cnt;
                lt.push_back({cnt,1});
            }
            else {
                tree2+=cnt;
                lt.push_back({cnt,2});
            }
            plum[idx]=cnt;
            
            idx++;
            cnt=1;
            
            tree= input;
        }
        else cnt++;
    }
    total+=cnt;
    if(input==1) {
        tree1+=cnt;
        lt.push_back({cnt,1});
    }
    else {
        tree2+=cnt;
        lt.push_back({cnt,1});
    }
    cout << "tree 1,2 : " << tree1 << "," << tree2 << endl;
    list<pair<int,int>>::iterator iter,next,prev;
    if(lt.size()==W+1){
        cout << "total : " << total << "\n";
    }
    iter = lt.begin();

    while(lt.size()>W+1){

    }
    
    cout << total << "\n";
    
    return 0;
}

// #include<iostream>
// #include<queue>
// #include<vector>

// using namespace std;

// struct cmp{
//     bool operator()(pair<int,int> A, pair<int,int> B){
//         return A.first > B.first ;
//     }
// };

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int T,W,input,idx=0,cnt=0,tree=1;
//     int tree1=0,tree2=0,move=0;
//     priority_queue <pair<int,int>, vector<pair<int,int>>,cmp> pqA;
//     priority_queue <pair<int,int>, vector<pair<int,int>>,cmp> pqB;

//     cin >> T >> W;
//     vector<int> plum(T,0);
//     for(int i=0;i<T;i++){
//         cin >> input;
//         if(tree!=input){
//             if(tree==1){
//                 pqA.push({cnt,idx});
//                 tree1+=cnt;
//             }
//             else {
//                 pqB.push({cnt,idx});
//                 tree2+=cnt;
//             }
//             plum[idx]=cnt;
//             idx++;
//             cnt=1;
//             tree= input;
//         }
//         else cnt++;
//     }
//     if(input==1) {
//         pqA.push({cnt,idx});
//         tree1+=cnt;
//     }
//     else {
//         pqB.push({cnt,idx});
//         tree2+=cnt;
//     }
//     plum[idx]=cnt;
//     for(int i=0;i<=idx;i++) cout << plum[i] << " " ;
//     cout << endl;
//     cout<< " tree1 : << " << tree1 << "," << "tree2: " << tree2 << endl;

//     while(!pqA.empty()){
//         cout << pqA.top().first << "," << pqA.top().second << " // ";
//         pqA.pop();
//     }
//     cout << endl;
//     while(!pqB.empty()){
//         cout << pqB.top().first << "," << pqB.top().second << " // ";
//         pqB.pop();
//     }
//     cout << endl;
    
//     return 0;
// }

// // #include<iostream>
// // #include<list>

// // using namespace std;

// // int main(void){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
// //     int T,W,move,len;
// //     cin >> T >> W;
// //     list <int> lt;
// //     int tree=1, input, cnt=0;
// //     int tree1=0,tree2=0;
// //     int tree1Min, tree2Min, target, update;
// //     int treefront=1;
// //     for(int i=0;i<T;i++){
// //         cin >> input;
// //         if(input!=tree){
// //             lt.push_back(cnt);
// //             tree = input;
// //             cnt = 1;
// //         }
// //         else cnt++;
// //     }
// //     lt.push_back(cnt);

// //     list<int>::iterator iter;
// //     iter = lt.begin();
// //     tree1Min = T;
// //     tree2Min = T;
// //     len = lt.size();
// //     for(int i=0;i<len;i++, iter++){
// //         if(i%2==0) {
// //             tree1+=*iter;
// //             if(tree1Min>*iter) tree1Min=*iter;
// //         }
// //         else{
// //             tree2+=*iter;
// //             if(tree2Min>*iter) tree2Min=*iter;
// //         } 
// //         cout << *iter << " ";
// //     }
// //     cout << "\n" <<  tree1 << "," << tree2 << " , move : " << len-1 << endl;
// //     len = lt.size();
// //     // while(len>W)
// //     // {
// //         if(tree1 - tree1Min < tree2 - tree2Min){ //tree1에서 하나 삭제하는 것이 이득
// //             iter = lt.begin();
// //             target = tree1Min;
// //             for(int i=0;i<len;i++,iter++){
// //                 if(i%2==0) {
// //                     if(*iter==target) {
// //                         iter=(lt.erase(iter));
// //                         if(i!=0){
// //                             update = *iter;
// //                             iter--;
// //                             cout << update << endl;
// //                             (*iter) = update;
// //                         }
// //                         cout << *iter << endl;
// //                     }
// //                 }
// //                 // cout << *iter << " ";
// //             }
// //         }
// //         else { //tree2에서 삭제하는 것이 이득
// //             iter = lt.begin();
// //             target = tree1Min;
// //             for(int i=0;i<len;i++,iter++){
// //                 if(i%2==0) {
// //                     if(*iter==target) {
// //                         iter=(lt.erase(iter));
// //                         if(i!=len-1){
// //                             update = *iter;
// //                             iter--;
// //                             cout << update << endl;
// //                             (*iter) = update;
// //                         }
// //                         cout << *iter << endl;
// //                     }
// //                 }
// //                 // cout << *iter << " ";
// //             }
// //         }
// //         len = lt.size();
// //     // }
    
// //     return 0;
// // }
