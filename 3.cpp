#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;
	int coronaToCorona=1, coronaToNotCorona=1000001;
	vector<vector<int>> COW(N, vector<int> (2));
	int lastCorona=-1, lastNotCorona=-1;
	int answer = 0;
	for(int i=0;i<N;i++){
		cin >> COW[i][0] >> COW[i][1];
		if(i>0){
			if(COW[i][1]==0){
				if(COW[i-1][1]==1){
					coronaToNotCorona = min(coronaToNotCorona, COW[i][0] - lastCorona);
				}
			}	
			else{ //Current Cow is Corona
				if(COW[i-1][1]==0){
					coronaToNotCorona = min(coronaToNotCorona, COW[i][0] - lastNotCorona);
				}
				else{ //before was Corona
					coronaToCorona = max(coronaToCorona, COW[i][0] - lastCorona);
				}
			}
		}
		if(COW[i][1]==0) lastNotCorona = COW[i][0] ;
		else lastCorona = COW[i][0];
	}
	
	if(coronaToNotCorona==1000001) {
		cout << "1\n"; // This means all Cows infected case
		return 0;
	}
	// cout << coronaToCorona << "," << coronaToNotCorona << endl;
	lastCorona = -1;
	for(int i=0;i<N;i++){
		if(COW[i][1] == 0) continue;
		if(lastCorona==-1) answer++;
		else{
			if( (COW[i][0]-lastCorona) >= coronaToNotCorona) answer++;
		}
		lastCorona = COW[i][0];
	}
	cout << answer << "\n";
	return 0;
}