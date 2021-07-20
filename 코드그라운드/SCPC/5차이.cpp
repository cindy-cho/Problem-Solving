
#include <iostream>
#include <vector>
#include <list>
#define endl '\n'
using namespace std;

int Answer;

typedef struct{
    int arrive;
    int diff; // diff = start - arrive
}info;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int T, test_case,q_case;
    int N,K;
    int OP,p1,p2,p3;
    int diff,diff2;
    bool flag,anFlag,flag2,anFlag2;
    list <info> :: iterator it;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        
        cin >> N >> K; //변수 N, 명령 K
        vector<list<info>> NN(N);
        info tmp;
        cout << "Case #" << test_case+1 << endl;
        for(q_case=0;q_case<K;q_case++){
            cin >> OP;
            if(OP==1){
                cin >> p1 >> tmp.arrive >> tmp.diff;
                p1--;
                tmp.arrive--;
                NN[p1].push_back(tmp);
            }
            else if(OP==2){
                cin >> p1 >> p2;
                p1--;
                p2--;
                flag = false;
                anFlag=false;
                flag2 = false;
                anFlag2=false;
                for(it = NN[p1].begin();it!=NN[p1].end();it++){
                    // cout << (*it).arrive << "," << (*it).diff << endl;
                    if((*it).arrive==p2 && flag==false) {
                        diff= (*it).diff;
                        anFlag=true;
                        flag=true;
                    }
                    else if((*it).arrive==p2){
                        if((*it).diff!=diff){
                            anFlag=false;
                        }
                    }
                }
                for(it = NN[p2].begin();it!=NN[p2].end();it++){
                    // cout << "2222\n";
                    // cout << (*it).arrive << "," << (*it).diff << endl;
                    if((*it).arrive==p1 && flag2 == false){
                        diff2 = (*it).diff;
                        anFlag2 = true;
                        flag2=true;
                    }
                    else if((*it).arrive==p1){
                        if((*it).diff!=diff2){
                            anFlag2 = false;
                        }
                    }
                }
                diff2 *= -1;
                // cout << diff << "," << diff2 << endl;
                if(flag==false && flag2==false) cout << "NC" << endl;
                else if(flag==true && anFlag==true && flag2==false) cout << diff << endl;
                else if(flag2==true && anFlag2==true && flag==false) cout << diff2 << endl;
                else if(flag==true && anFlag==true && flag2==true && anFlag2==true && diff==diff2) cout << diff << endl;
                else cout << "CF" << endl;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
	}

	return 0;//Your program should return 0 on normal termination.
}