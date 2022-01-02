#include <stdio.h>
int diff(char *a, char *b){
    return (int)(*a-*b+1);
}
    
int main(){
    char ch1, ch2;
    printf("두 문자를 입력 : ");
    scanf("%c %c",&ch1, &ch2);
    printf("두 문자의 차이 ==> %d\n",diff(&ch1,&ch2));
    return 0;
}