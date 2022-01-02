#include <iostream>
#include <vector>

using namespace std;

void printStar(int i,int j, int K){
    
    if((i/K)%3==1 && (j/K)%3==1) cout << " ";
    else{
        if(K==1) cout <<"*";
        else printStar(i,j,K/3);
    }
}

int main(void){
    int K;
    cin >> K;
    
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++) {
            printStar(i,j,K);
        }
        cout << endl;
    }
    

    return 0;
}
/*
00 01 02 03 04 05 06 07 08
10 11 12 13 14 15 16 17 18
20 21 22 23 24 25 26 27 28
30 31 32 33 34 35 36 37 38
40 41 42 43 44 45 46 47 48
50 51 52 53 54 55 56 57 58
60 61 62 63 64 65 66 67 68
70 71 72 73 74 75 76 77 78
80 81 82 83 84 85 86 87 88
(i/3)%3==1, (j/3)%3==1
i%3==1, j%3=1
빈칸 : 11 14 17
      31    47
      71 74 77
    
중심 빈칸 : 1,1
      33 34 35
      43 44 45
     53 54 55

*/