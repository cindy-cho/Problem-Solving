#include<iostream>
#include<vector>
using namespace std;

vector <bool> used(10,false);
vector <int> answer(10);
void Combination(int N,int depth){
    if(depth==N) {
        //for(int i=0;i<ans.size();i++) cout << ans[i];
        for(int i=0;i<N;i++) cout << answer[i] <<" ";
        cout << endl;
        return;
    }

    for(int i=0;i<N;i++){
        if(!used[i]){
            answer[depth]=i+1;
            used[i]=true;
            Combination(N,depth+1);
            used[i]=false;
        }
    }

}
int main(void){
    int N;
    cin >> N;
    Combination(N,0);

    return 0;
}