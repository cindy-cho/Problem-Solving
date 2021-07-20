// #include <iostream>
// #include <stdlib.h>
// #define endl '\n'
// using namespace std;

// int Answer;

// int main(int argc, char** argv)
// {
// 	int T, test_case,n,tt;
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
	
// 	cin >> T;
// 	for(test_case = 0; test_case  < T; test_case++)
// 	{

// 		Answer = 0;
//         cin >> n >> tt; // n: 비트수, 1<=tt<n
//         char *A, *B;
//         A = (char*)malloc(sizeof(char)*n);
//         B = (char*)malloc(sizeof(char)*n);
//         for(int i=0;i<n;i++) {
//             cin >> B[i];
//             A[i] = 'A';
//         }
//         if(tt>n-tt){
//             for(int i=1;i<=(n-tt);i++){
//                 A[tt+i]=B[i-1];
//                 A[i-1]=B[tt+i];
//             }
           
//         }
//         else{
//             for(int i=1;i<=tt;i++){
//                 A[tt+i-1]=B[i-1];
//                 A[n-tt-tt+i-1]=B[n-tt+i-1];
//             }
//             for(int i=tt+1;i<=n-tt;i++){
//                 if(B[i-1]=='0'){
//                     A[i-1+tt]='0';
//                     A[i-1-tt]='0';
//                 }
//             }
//             for(int i=tt+1;i<=n-tt;i++){
                
//                 if(B[i-1]=='1'){
//                     if(A[i-1-tt]=='A' && A[i-1+tt]=='A'){
//                         A[i-1+tt] = '1';
//                         A[i-1-tt]= '0';
//                     }
//                     else if(A[i-1-tt]=='0') A[i-1+tt] = '1';
//                     else A[i-1-tt]='1';
//                 }
//             }
//         }
//          for(int i=0;i<n;i++){
//                 if(A[i]=='A') A[i] = '0';
//             }
//         // cout << endl;
//         // cout << B << endl;       
// 		// Print the answer to standard output(screen).
// 		cout << "Case #" << test_case+1 << endl;
// 		cout << A << endl;
// 	}

// 	return 0;//Your program should return 0 on normal termination.
// }

#include <iostream>
// #include <stdlib.h>
#define endl '\n'
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case,n,tt;
    char A[50000],B[50000];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        cin >> n >> tt; // n: 비트수, 1<=tt<n
        for(int i=0;i<n;i++) {
            cin >> B[i];
            A[i] = 'A';
            if(B[i]=='0'){
                if(i-tt>=0) A[i-tt] = '0';
                if(i+tt<n) A[i+tt] = '0';
            }
        }
        
        for(int i=0;i<n;i++){
            if(B[i]=='1'){
                if(i-tt>=0 && i+tt<n){ // 두개 다 존재할 때
                    if(A[i-tt]=='A' && A[i+tt]=='A'){
                        A[i-tt]='0';
                        A[i+tt]='1';
                    }
                    else if(A[i-tt]=='0') A[i+tt]='1';
                    else if(A[i+tt]=='0') A[i-tt]='1';
                }
                else if(i-tt>=0){ //앞에만 존재할 때
                    A[i-tt]='1';
                }
                else if(i+tt<n){ //뒤에만 존재할 때
                    A[i+tt]='1';
                }
            }
        }
        for(int i=0;i<n;i++) if(A[i]=='A') A[i]= '0';
      
		cout << "Case #" << test_case+1 << endl;
		for(int i=0;i<n;i++) cout <<A[i];
        cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}