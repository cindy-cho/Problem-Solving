#include<iostream>

using namespace std;

int main(void){
    int t,i,j,k,n,flag,answered;
    int black[4]={0,};
    int coloring[16][4]={ {0, 0, 0, 0}, {-1, 0, 0, -1}, {-1, -1, 0, 0}, {0, -1, -1, 0}, {0, 0, -1, -1}, 
                          {-2, -1, 0, -1}, {-1, -1, -1, -1}, {-1, 0, -1, -2}, {-1, -2, -1, 0}, 
                        {-1, -1, -1, -1}, {0, -1, -2, -1},{-1, -1, -2, -2}, {-2, -2, -1, -1}, 
                        {-2, -1, -1, -2 }, {-1, -2, -2, -1}, {-2, -2, -2, -2} };

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d %d %d %d %d",&n,&black[0],&black[1],&black[2],&black[3]);
        answered=-1;
        for(j=0;j<16;j++){
            flag = 0;
            for(k=0;k<4;k++){
                if(black[k]+coloring[j][k]>=0 && black[k]-(n-2)<=(coloring[j][k]*-1)) flag++;
            }

            if(flag==4){
                cout <<"YES" <<endl;
                answered=1;
                break;
            }
        }
        if(answered==-1) cout << "NO" <<endl;
    }
    return 0;
}