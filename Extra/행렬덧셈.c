#include<stdio.h>

#define row 4
#define col 3

void addMatrix(const int A[][col], const int B[][col], int C[][col]);
void multiMatrix(const int A[][col], const int B[][col], int C[][col]);
void transpose(const int A[][col], int B[][row]);
void printMatrix(const int A[][col]);
void printMultiMatrix(const int A[][col]);

int main(void){

    int A[row][col] = {{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
    int B[row][col] = {{4,3,2},{4,3,2},{4,3,2},{4,3,2}};
    int C[row][col] = {0}; // A+B 저장
    int D[col][col] = {0}; // D(A의 transpose값) * B값 저장

    printf("Matrix A\n");
    printMatrix(A);
    printf("Matrix B\n");
    printMatrix(B);

    addMatrix(A,B,C);
    printf("Matrix C = A + B\n");
    printMatrix(C);

    multiMatrix(A,B,D);
    printf("Matrix D = D(Transposed A) * B\n");
    printMultiMatrix(D);

    return 0;
    
}

void addMatrix(const int A[][col], const int B[][col], int C[][col]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiMatrix(const int A[][col], const int B[][col], int C[][col]){
    int D[col][row] = {0}; // A transpose값 저장
    transpose(A,D);

    int i,j,k;

    for(i=0;i<col;i++){
        for(j=0;j<col;j++){
            C[i][j] = 0;
            for(k=0;k<row;k++){
                C[i][j] += D[i][k] * B[k][j];
            }
        }
    }
}

void transpose(const int A[][col], int B[][row]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            B[j][i] = A[i][j];
        }
    }
}

void printMatrix(const int A[][col]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void printMultiMatrix(const int A[][col]){
    int i,j;
    for(i=0;i<col;i++){
        for(j=0;j<col;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}