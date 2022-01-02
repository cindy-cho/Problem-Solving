// #include <iostream>

// using namespace std;


// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N,M,i,j,k,flag=0,ans=0,tmpi,tmpj,check;
//     char map[1000][1000];
//     int dir[3][2]={{0,1},{1,0},{1,1}};
//     cin >> N >> M ;
//     for(i=0;i<N;i++){
//         for(j=0;j<M;j++){
//             scanf("%c",&map[i][j]);
//             if(map[i][j]=='1') flag= 1;
//         }
//     }
//     if(flag==0) cout << "0\n";
//     else{
//         flag=1;
//         while(1){
//             flag=0;
//             for(i=0;i<N;i++){
//                 for(j=0;j<M;j++){
//                     if(map[i][j]=='1'){
//                         check = 0;
//                         for(k=0;k<3;k++){
//                             tmpi=i+dir[k][0];
//                             tmpj=j+dir[k][1];
//                             if(tmpi<N && tmpj<M && map[tmpi][tmpj]=='1'){
//                                 check++;
                                
//                             }
//                         }
//                         if(check==3) flag=1;
//                         else map[i][j]='0';
//                     }
//                 }
//             }

//             // cout << "\n" ;
//             // cout << "ans: " << ans << ",  flag : " << flag << ",  N : " << N << " , M : " << M << "\n";
//             // for(i=0;i<N;i++){
//             //     for(j=0;j<M;j++) cout << map[i][j];
//             //     cout << "\n";
//             // }

//             if(flag==1) ans++;
//             N--;
//             M--;

//             if(N<1) break;
//             if(M<1) break;
//             if(flag!=1) break;
//         }
     
//      cout << (ans+1)*(ans+1) << "\n";

//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){
    int N,M,i,j,k,flag=0,check,tmpi,tmpj,ans=0;
    int dir[3][2]={{1,1},{1,0},{0,1}};
    cin >> N >> M;
    vector <string> data(N);
    vector <vector <int> > map(N, vector<int> (M));
    cin.ignore();
    for(i=0;i<N;i++) getline(cin,data[i]);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(data[i][j]=='1'){
                flag=1;
                map[i][j]=1;
            }
            else map[i][j]=0;
        }
    }
    if(flag==0) cout << "0\n";
    else{
        flag=1;
        while(1){
            flag=0;
            for(i=0;i<N;i++){
                for(j=0;j<M;j++){
                    if(map[i][j]==1){
                        check = 0;
                        for(k=0;k<3;k++){
                            tmpi=i+dir[k][0];
                            tmpj=j+dir[k][1];
                            if(tmpi<N && tmpj<M && map[tmpi][tmpj]==1){
                                check++;
                                
                            }
                        }
                        if(check==3) flag=1;
                        else map[i][j]=0;
                    }
                }
            }

            // cout << "\n" ;
            // cout << "ans: " << ans << ",  flag : " << flag << ",  N : " << N << " , M : " << M << "\n";
            // for(i=0;i<N;i++){
            //     for(j=0;j<M;j++) cout << map[i][j];
            //     cout << "\n";
            // }

            if(flag==1) ans++;
            N--;
            M--;

            if(N<1) break;
            if(M<1) break;
            if(flag!=1) break;
    }
    cout << (ans+1)*(ans+1) << "\n";
    }
 
    return 0;
}