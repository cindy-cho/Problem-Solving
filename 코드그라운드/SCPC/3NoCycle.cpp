
#include <iostream>
#define endl '\n'
using namespace std;

int Answer;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T, test_case;
    int N,M,K;
    int A,B;
    int maps[500][500];

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N >> M >> K;
		Answer = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++) maps[i][j]=9;
        }
        for(int i=0;i<M;i++){
            cin >> A >> B; //A->B
            maps[A-1][B-1]= 0; //A->B
        }
        for(int i=0;i<K;i++){
            cin >> A >> B; //A ? B
            if(maps[A-1][B-1]==0 && maps[B-1][A-1]==0) continue;
            if(maps[A-1][B-1]==0) maps[B-1][A-1]=2;
            else if(maps[B-1][A-1]==0) maps[A-1][B-1]=2;
            else{
                maps[A-1][B-1]=2;
                maps[B-1][A-1]=2;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}