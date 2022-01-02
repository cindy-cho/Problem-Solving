#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr+3);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    return 0;
}