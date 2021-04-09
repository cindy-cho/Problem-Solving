#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(void){
    int t,n,i,j,k,value,max,sPos;
    vector<int> deck;
    vector<int> newDeck;

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        deck.clear();
        newDeck.clear();
        for(j=0;j<n;j++){
            scanf("%d",&value); 
            deck.push_back(value);
        }
        max = deck[0];
        sPos = 0;
        
        for(j=1;j<n;j++){
            if(max<deck[j]){
                for(k=j-1;k>=sPos;k--){
                    newDeck.insert(newDeck.begin(),deck[k]);
                }
                sPos=j;
                max=deck[j];
            }
        }
        for(k=n-1;k>=sPos;k--) newDeck.insert(newDeck.begin(),deck[k]);
        for(j=0;j<n;j++) cout<<newDeck[j] << " ";
        cout << endl;
    }
    return 0;
}