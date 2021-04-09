#include <iostream>

using namespace std;

/*u+v u&v =v
3->9
36*/
int flag=0;
void findZoo(int start, int target){
    int i;
    if(flag==1) return;
    printf("start : %d, target : %d\n",start,target);


    for(i=1;i<=target;i++){
        if((start&i)==i){
            if((start+i)==target) {
                printf("(%d & %d) = %d : %d -> %d! \n",start,i,(start&i),start,start+i);
                flag=1;
                return;
            }
            else{
                printf("(%d & %d) = %d : %d -> %d! \n",start,i,(start&i),start,start+i);
                if(start+i<= target) findZoo(start+i,target);
            }
        }
    }
    return;
}

int main(void){

    findZoo(3,9);

    return 0;
}

/*
(1 & 1) = 1 : 1->2
(2 & 2) = 2 : 2->4
(3 & 1) = 1 : 3->4
(3 & 2) = 2 : 3->5
(3 & 3) = 3 : 3->6
(4 & 4) = 4 : 4->8
(5 & 1) = 1 : 5->6
(5 & 4) = 4 : 5->9
(5 & 5) = 5 : 5->10
(6 & 2) = 2 : 6->8
(6 & 4) = 4 : 6->10
(6 & 6) = 6 : 6->12
(7 & 1) = 1 : 7->8
(7 & 2) = 2 : 7->9
(7 & 3) = 3 : 7->10
(7 & 4) = 4 : 7->11
(7 & 5) = 5 : 7->12
(7 & 6) = 6 : 7->13
(7 & 7) = 7 : 7->14
(8 & 8) = 8 : 8->16
(9 & 1) = 1 : 9->10
(9 & 8) = 8 : 9->17
(9 & 9) = 9 : 9->18
*/