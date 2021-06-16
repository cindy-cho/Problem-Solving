
#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		int T2,num;
		cin >> T2;
		
		cin >> Answer;
		for(int i=1;i<T2;i++){
            cin >> num;
            Answer = Answer ^ num;
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}