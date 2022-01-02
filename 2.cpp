#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;
	vector<pair<int,int>> carSales(N);
	for(int i=0;i<N;i++) {
		cin >> carSales[i].first;
		carSales[i].second = i;
	}
	sort(carSales.begin(),carSales.end());
	for(auto sales:carSales){
		cout << sales.second+1 << " ";
	}
	return 0;
}