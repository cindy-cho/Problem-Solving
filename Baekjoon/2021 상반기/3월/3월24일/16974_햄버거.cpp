#include<iostream>

using namespace std;

long long burger[55][2];
void findLayer(int N, long long X, long long meat, long long layer){
    // cout << N << "," << X << "," << meat << "," << layer << endl;

    layer = layer + 1;
    if(layer==X){   
        cout << meat << "\n";
        return;
    }

    if(layer + burger[N-1][0] > X){
     
        findLayer(N-1,X,meat,layer);
        return ;
    }

    layer = layer + burger[N-1][0];
    meat = meat + burger[N-1][1];
    if(layer==X){
       
        cout << meat << "\n";
        return;
    }

    layer = layer + 1;
    meat = meat + 1;
    if(layer==X){
        
        cout << meat << "\n";
        return;
    }

    if(layer + burger[N-1][0] > X){
       
        findLayer(N-1,X,meat,layer);
        return ;
    }

    layer = layer + burger[N-1][0];
    meat = meat + burger[N-1][1];
    if(layer==X){
       
        cout << meat << "\n";
        return;
    }

    layer = layer + 1;
    if(layer==X){
       
        cout << meat << "\n";
        return;
    }
    

}
int main(void){
    int N, i;
    long long X;
    cin >> N >> X;
    burger[0][0]=1;
    burger[0][1]=1;
    for(i=1;i<=50;i++){
        burger[i][1] = burger[i-1][1] + 1 + burger[i-1][1];
        burger[i][0] = 1 + burger[i-1][0] + 1 + burger[i-1][0] + 1;
        // cout << i << " 번째 버거 " << burger[i][1] << "," << burger[i][0] << endl;
    }

    findLayer(N,X,0,0);

    return 0;
}

