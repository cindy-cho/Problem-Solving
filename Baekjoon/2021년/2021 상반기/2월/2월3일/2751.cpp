#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

void quickSort(int left, int right);
vector<int> number;
int main(void){
    int N,i,value;
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d",&value);
        number.push_back(value);
    }
 
    quickSort(0,N-1);

    for(i=0;i<N;i++) printf("%d\n",number[i]);
    
    return 0;
}

void quickSort(int left, int right){
    if(left>=right) return;
    int pivot = (number[left] + number[right] + number[(left+right)/2])/3;

    int i=left,j=right;

    while(left<=right){
        while(number[left] < pivot) left++;
        while(number[right] > pivot) right--;

        if(left<=right){
            int temp;
            temp = number[left];
            number[left] = number[right];
            number[right] = temp;
            
            left++;
            right--;
        }

        quickSort(i,right);
        quickSort(left,j);

    }
}