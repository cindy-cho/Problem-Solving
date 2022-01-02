#include<iostream>
#include<vector>

#define endl '\n'
typedef long long ll;

using namespace std;

vector<int> arr;
ll answer;
void printArr(int n){
    for(int i=0;i<n;i++) cout << arr[i] << " " ;
    cout << endl;
}
void mergeSort(int start,int end, int total){
    if(total>2){
        mergeSort(start, start+total/2, total/2);
        mergeSort(start+total/2, end, end-start-total/2);
    }
    if(total==1) return;
    vector<int> tmp(total);
    int first = start, second = start+total/2, firstEnd = start+total/2, secondEnd = end;
    for(int i=0;i<total;i++){
        if(first == firstEnd){
            tmp[i] = arr[second++];
            continue;
        }
        if(second == secondEnd){
            tmp[i] = arr[first++];
            continue;
        }
        if(arr[first] <= arr[second]){
            tmp[i] = arr[first++];
        }
        else{
            answer += (firstEnd - first);
            // cout << "Change : " << arr[first] << " < - > " << arr[second] << endl;
            tmp[i] = arr[second++];
        }
    }
    int tmpIdx=0;
    for(int i=start;i<end;i++){
        arr[i] = tmp[tmpIdx++];
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr.resize(n);
    answer = 0;
    for(int i=0;i<n;i++) cin >> arr[i];
    mergeSort(0,n,n);
    // printArr(n);
    cout << answer << endl;

    return 0;
}