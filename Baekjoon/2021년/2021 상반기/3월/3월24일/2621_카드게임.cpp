#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair< char, int >  a , pair <char,int>  b){
    return a.second > b.second;
}
int main(void){
    int i,j,rule1=0,rule2=0,rule3=0,rule4=0,rule5=0,rule6=0,rule7=0,S,E;
    int card1,card2;
    vector <pair <char ,int > > card(5);
    for(i=0;i<5;i++){
        cin >> card[i].first >> card[i].second ;
        if(i!=0 && card[i].first==card[i-1].first) rule1 ++; //rule1 =4 면 5개 같은 카드
    }

    sort(card.begin(),card.end(),cmp);


    if(card[0].second == card[4].second+4 && rule1==4){
        cout << 900+card[0].second << "\n";
        return 0;
    }

    S=0;
    E=3;
    for(j=0;j<2;j++){
        rule3=0;
        if(card[S].second == card[E].second){
             cout << 800 + card[S].second << "\n";
             return 0;
        }
        S++;
        E++;
    }
    //rule3==4이면 3장의 숫자가 같을 때
     

    S=0;
    E=2;
    for(j=0;j<3;j++){
        if(card[S].second==card[E].second){
            if(S==0){
                if(card[3].second == card[4].second){
                    cout << (card[S].second * 10 + card[3].second) + 700 << "\n";
                    return 0;
                }
            }
            else if(S==1){
                if(card[0].second == card[4].second){
                    cout << (card[S].second * 10 + card[0].second) + 700 << "\n";
                    return 0;
                }
            }
            else if(S==2){
                if(card[0].second == card[1].second){
                    cout << (card[S].second * 10 + card[0].second) + 700 << "\n";
                    return 0;
                }
            }
        }          
        S++;
        E++;
    }
    if(rule1==4){
        cout << card[0].second + 600 << "\n";
        return 0;
    }
    if(card[0].second == card[4].second+4) {
        cout << card[0].second + 500 << "\n";
        return 0;
    }


    S=0;
    E=2;
    for(j=0;j<3;j++){
        if(card[S].second==card[E].second){
           
            cout << card[S].second + 400 << "\n";
            return 0;
        }
                   
        S++;
        E++;
    }

    if(card[0].second == card[1].second && card[2].second == card[3].second){
        cout << card[0].second * 10 + card[2].second + 300 << "\n";
        return 0;
    }

    if(card[0].second == card[1].second && card[3].second == card[4].second){
        cout << card[0].second * 10 + card[3].second + 300 << "\n";
        return 0;
    }

    if(card[1].second == card[2].second && card[3].second == card[4].second){
        cout << card[1].second * 10 + card[3].second + 300 << "\n";
        return 0;
    }

    S=0;
    E=1;
    for(j=0;j<4;j++){
        if(card[S].second==card[E].second){
           
            cout << card[S].second + 200 << "\n";
            return 0;
        }
                   
        S++;
        E++;
    }
    cout << card[0].second + 100 << "\n";
    return 0;
}