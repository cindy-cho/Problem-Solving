#include<iostream>


using namespace std;
int main(void){
    
    int ans=0,now=0,isLaser;
    char current;
    int stack=0;
    while(1){
        scanf("%c",&current);
        //printf("stack : %d, ans : %d, now : %d\n",stack,ans,now);
        if(current=='(') {
            stack++;
            isLaser=-1;
        }
        else if(current==')'){
            stack--;    
            if(isLaser==-1) {
                isLaser=1;
                ans+=stack;
            }
            else ans++;
            
            
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}
