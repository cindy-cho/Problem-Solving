#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N;
    scanf("%d",&N);

    vector < vector <string> > book(50);

    int i,j,m=0;
    string word;
    for(i=0;i<N;i++){
        cin >> word;
        book[word.length()-1].push_back(word);
        if( m < (word.length()-1)) m = word.length()-1;
    }

    for(i=0;i<m;i++) {
        if(book[i].size()>0){
            book[i].erase(unique(book[i].begin(),book[i].end()),book[i].end());
            sort(book[i].begin(),book[i].end());
            for(j=0;j<book[i].size();j++) cout << book[i][j] << endl;
        }
    }
    book[m].erase(unique(book[m].begin(),book[m].end()),book[m].end());
    sort(book[m].begin(),book[m].end());
    if(book[m].size()==1) cout << book[m][0];
    else{
        for(j=0;j<book[m].size()-1;j++) cout << book[i][j] << endl;
        cout << book[i][j];
    }
    
    
    return 0;
}