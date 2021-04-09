#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int i,j,t,n,m,val;
    int leftboxPos, rightboxPos;
    int leftSpecialPos, rightSpecialPos;
    int leftMost, prevLeftMost, leftCount;
    int rightMost, prevRightMost,rightCount;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        vector <int> box;
        vector <int> special;
        leftboxPos=-1;
        leftSpecialPos=-1;
        scanf("%d %d",&n,&m);
        for(j=0;j<n;j++){
            scanf("%d",&val);
            if(val<0) leftboxPos=j;
            box.push_back(val);
        } 
        for(j=0;j<m;j++){
            scanf("%d",&val);
            if(val<0) leftSpecialPos=j;
            special.push_back(val);
        }
        rightboxPos=leftboxPos+1;
        rightSpecialPos=leftSpecialPos+1;

        leftMost=0;
        if(leftboxPos!=-1){
            prevLeftMost=0;
            leftCount=0;
            //while(leftboxPos>=0 && leftSpecialPos>=0){
        //     if(box[leftboxPos]<special[leftSpecialPos])
            //}
        }
        rightMost=0;
        int R, Rcount;
        if(rightboxPos!=box.size()){
            prevRightMost=0;
            rightCount=0;
            for(j=rightboxPos;j<n;j++){
                if(box[j]<special[rightSpecialPos]) rightCount++;
                else{
                    Rcount=0;
                    R= rightSpecialPos;
                    while(R<m-1 && R<=rightSpecialPos+rightCount){
                        if(special[R+1]-special[R]==1) Rcount ++;
                        else break;
                        R++;
                    }
                    prevRightMost = R;
                }
            }
        }

        cout << leftMost + rightMost << endl;
    }

    return 0;
}