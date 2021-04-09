#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void) {
	int N,i;
    
    cin >> N;
    cin.ignore();
    
 //   vector < pair <int, int > > user;
    string input;
    string ans;
    int t1, t2;
    int ans1=0, ans2=1439;
    for(i=0;i<N;i++) {
        getline(cin,input);
        t1 = stoi(input.substr(0,2))*60 + stoi(input.substr(3,2));
        t2 = stoi(input.substr(8,2))*60 + stoi(input.substr(11,2));
       
        if(ans1<t1) ans1=t1;
        if(ans2>t2) ans2=t2;
    }
    
    if(ans1>ans2) cout << "-1\n";
    else{
        if(ans1/60 < 10) cout<< "0" <<  ans1/60 << ":";
        else cout << ans1/60 << ":";
        if(ans1%60 < 10) cout << "0" << ans1%60 << " ~ ";
        else cout << ans1%60 << " ~ ";    
        if(ans2/60 < 10) cout<< "0" <<  ans2/60 << ":";
        else cout << ans2/60 << ":";
        if(ans2%60 < 10) cout << "0" << ans2%60 << "\n";
        else cout << ans2%60 << "\n";          
    }
    
	return 0;
}