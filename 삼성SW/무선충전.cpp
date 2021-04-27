#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int A[2]={0,0},B[2]={9,9};
    int M;
    int i,j,k;
    int BCCount=0;
    int MAP[10][10];
    int x,y,c,p;
    int tmpx,tmpy;
    int sum;
    int sumA,sumB,sumAidx,sumBidx;
    int max1,max2;
    int maxA,maxB,maxAidx,maxBidx;
    int BC[8][3];
    int Adir[100],Bdir[100];
    int dir[5][2]={{0,0},{-1,0},{0,1},{1,0},{0,-1}}; // 정지, 상, 우, 하, 좌
    vector<int> tmp(4);

    cin >> T;

    for(int testCase=0;testCase<T;testCase++){
        sum = 0;
        sumA = 0;
        sumB = 0;
        for(i=0;i<10;i++) for(j=0;j<10;j++) MAP[i][j] = 0; //지도 초기화
        cin >> M >> BCCount;
        for(i=0;i<M;i++) cin >> Adir[i];
        for(i=0;i<M;i++) cin >> Bdir[i];
        for(k=0;k<BCCount;k++){
            cin >> x >> y >> c >> p;
            // cout << "\n";
            x--;
            y--;
            BC[k][0]=y;
            BC[k][1]=x;
            BC[k][2]=c;
            MAP[y][x] = p;
            for(i=0;i<c+1;i++){
                tmpy=y-(c-i);
                tmpx=x-i;
                if(tmpy<0) continue;
                for(j=0;j<(i+1)*2-1;j++){ //i=0 j=0~1, i=1 j=0~3
                    if(tmpy==y && tmpx==x || tmpx<0 || tmpx>10) {
                        tmpx++;
                        continue;
                    }
                    if(MAP[tmpy][tmpx]==0) MAP[tmpy][tmpx] = p;
                    else MAP[tmpy][tmpx]= -1;
                    tmpx++;
                }
            }
            for(i=1;i<c+1;i++){
                tmpy=y+i;
                tmpx=x-(c-i);
                if(tmpy>=10) continue;
                for(j=0;j<(c-i)*2+1;j++){ //i=0 j=0~1, i=1 j=0~3
                    if(tmpx<0 || tmpx>10){
                        tmpx++;
                        continue;
                    }
                    if(MAP[tmpy][tmpx]==0) MAP[tmpy][tmpx] = p;
                    else MAP[tmpy][tmpx]= -1;
                    tmpx++;
                }
            }
            // for(int i=0;i<10;i++){
            //     for(int j=0;j<10;j++){
            //         printf("%4d",MAP[i][j]);
            //     }
            //     cout << endl;
            // }         
        }
        
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         printf("%4d",MAP[i][j]);
        //     }
        //     cout << endl;
        // }    

        if(MAP[A[0]][A[1]]!=-1) sumA = MAP[A[0]][A[1]];
        else{
            for(i=0;i<BCCount;i++){
                if((abs(BC[i][0]-A[0])+abs(BC[i][1]-A[1]))<=BC[i][2]){//거리 안에 들어가면
                    if(sumA<MAP[BC[i][0]][BC[i][1]]) sumA=MAP[BC[i][0]][BC[i][1]];
                }
            }
        }
        if(MAP[B[0]][B[1]]!=-1) sumB = MAP[B[0]][B[1]];
        else{
            for(i=0;i<BCCount;i++){
                if((abs(BC[i][0]-B[0])+abs(BC[i][1]-B[1]))<=BC[i][2]){//거리 안에 들어가면
                    if(sumB<MAP[BC[i][0]][BC[i][1]]) sumB=MAP[BC[i][0]][BC[i][1]];
                }
            }
        }

        // cout << "\nSumA : " << sumA << " SumB : "<< sumB << " SUM : ";
        sum = sumA + sumB;
        // cout << sum << endl;

        for(k=0;k<M;k++){
            A[0] = A[0]+dir[Adir[k]][0];
            A[1] = A[1]+dir[Adir[k]][1];
            B[0] = B[0]+dir[Bdir[k]][0];
            B[1] = B[1]+dir[Bdir[k]][1];
            // printf("dirA :(%d)(%d, %d), A: (%d, %d)\n",Adir[i],dir[Adir[i]][0],dir[Adir[i]][1],A[0],A[1]);
            if(A[0]==B[0] && A[1]==B[1]){ //같은 위치에 있다면 sumA를 max1, sumB를 max2
                if(MAP[A[0]][A[1]]!=-1){
                    sumA=MAP[A[0]][A[1]]/2;
                    sumB=sumA;
                }
                else{
                    sumA=0;
                    sumB=0;
                    for(i=0;i<BCCount;i++){
                        if((abs(BC[i][0]-A[0])+abs(BC[i][1]-A[1]))<=BC[i][2]){//거리 안에 들어가면
                            if(sumA<MAP[BC[i][0]][BC[i][1]]) sumA=MAP[BC[i][0]][BC[i][1]];
                            else if(sumB<MAP[BC[i][0]][BC[i][1]]) sumB=MAP[BC[i][0]][BC[i][1]];
                        }
                    }
                }
                sum += sumA + sumB;
            }
            else{
                maxA=0;
                maxB=0;
                sumA=0;
                sumB=0;
                
                for(int i=0;i<BCCount;i++){
                    if((abs(BC[i][0]-A[0])+abs(BC[i][1]-A[1]))<=BC[i][2] && (abs(BC[i][0]-B[0])+abs(BC[i][1]-B[1]))<=BC[i][2]){ //두 개가 같은 기지국일 때
                        if(maxA<MAP[BC[i][0]][BC[i][1]]){
                            maxA=MAP[BC[i][0]][BC[i][1]];
                            maxAidx=i;
                        }
                        else if(maxB<MAP[BC[i][0]][BC[i][1]]){
                            maxB=MAP[BC[i][0]][BC[i][1]];
                            maxBidx=i;
                        }
                    }
                    else if((abs(BC[i][0]-A[0])+abs(BC[i][1]-A[1]))<=BC[i][2]){
                        if(sumA<MAP[BC[i][0]][BC[i][1]]) {
                            sumA = MAP[BC[i][0]][BC[i][1]];
                            sumAidx = i;
                        }
                    }
                    else if((abs(BC[i][0]-B[0])+abs(BC[i][1]-B[1]))<=BC[i][2]){
                        if(sumB<MAP[BC[i][0]][BC[i][1]]){
                            sumB = MAP[BC[i][0]][BC[i][1]];
                            sumBidx = i;
                        }
                    }
                }

                // printf("K : %d, maxA : %d, maxB : %d, sumA : %d, sumB ; %d\n",k,maxA,maxB,sumA,sumB);
                tmp[0] = maxA;
                tmp[1]= maxB;
                tmp[2] = sumA;
                tmp[3]= sumB;
                sort(tmp.begin(),tmp.end());
                
                
                    
                sum += tmp[3] + tmp[2];
                sumA = tmp[3];
                sumB = tmp[2];
                

            }
            // else{
            //     if(MAP[A[0]][A[1]]!=-1) sumA = MAP[A[0]][A[1]];
            //     else{
            //         for(i=0;i<BCCount;i++){
            //             if((abs(BC[i][0]-A[0])+abs(BC[i][1]-A[1]))<=BC[i][2]){//거리 안에 들어가면
            //                 if(sumA<MAP[BC[i][0]][BC[i][1]]) sumA=MAP[BC[i][0]][BC[i][1]];
            //             }
            //         }
            //     }
            //     if(MAP[B[0]][B[1]]!=-1) sumB = MAP[B[0]][B[1]];
            //     else{
            //         for(i=0;i<BCCount;i++){
            //             if((abs(BC[i][0]-B[0])+abs(BC[i][1]-B[1]))<=BC[i][2]){//거리 안에 들어가면
            //                 if(sumB<MAP[BC[i][0]][BC[i][1]]) sumB=MAP[BC[i][0]][BC[i][1]];
            //             }
            //         }
            //     }

            //     sum += sumA + sumB;
            // }

            // cout << "SumA : " << sumA << " SumB : "<< sumB << " SUM : " << sum << endl;
        }
        
        cout << sum << endl;
    }
    return 0;
}