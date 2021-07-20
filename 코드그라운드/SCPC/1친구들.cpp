#include <iostream>
#define endl '\n'

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T, test_case,N,tmp;
    int level;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> tmp;
            if(i+tmp>=N){
                Answer++;
            }
        }
    
        
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}