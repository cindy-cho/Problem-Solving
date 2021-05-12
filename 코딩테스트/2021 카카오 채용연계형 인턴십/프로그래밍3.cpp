#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int arr[1000000][2];
    int move,top,idx;
    int prev,next;
    string strMove;
    stack<int> s;
    arr[0][0] = -1;
    arr[n-1][1] = -1;
    for(int i=0;i<n;i++){
        answer +='O';
        if(i!=0) arr[i][0]=i-1;
        if(i!=n-1) arr[i][1] = i+1;
    }
    int cursor = k;

    for(auto cm : cmd){
        cout << "cursor : " << cursor << endl;
        for(int i=0;i<n;i++) cout << arr[i][1] << " ";
        cout << endl;
        if(cm[0]=='U'){
            strMove = cm.substr(2,cm.length()-2);
            move = stoi(strMove);
            int i=1;
            while(i<move){
                if(arr[cursor][0] > 0)i++;

                cursor --;
            }
        }
        else if(cm[0]=='D'){
            strMove = cm.substr(2,cm.length()-2);
            move = stoi(strMove);
            int i=1;
            while(i<move){
                if(arr[cursor++][0] > 0) i++;
                cursor ++;
            }
        }
        else if(cm[0]=='C'){
            s.push(cursor);
            prev = arr[cursor][0];
            next = arr[cursor][1];
            arr[prev][1] = next;
            arr[next][0] = prev;

            arr[cursor][0] = -prev;
            arr[cursor][1] = -next;
        }
        else{ //Z인 경우
            top = s.top();
            s.pop();
            idx = top;
            while(idx>0 && arr[idx][0]<0) idx--;
            cout << idx << ": " << arr[idx][0] << "," << arr[idx][1] << endl;            
        }
    }
    
    while(!s.empty()){
        answer[s.top()]= 'X';
        s.pop();
    }
    return answer;
}

// #include <string>
// #include <vector>
// #include <list>
// #include <stack>
// #include <iostream>

// using namespace std;

// string solution(int n, int k, vector<string> cmd) {
//     string answer = "";
//     list <int> cell;
//     list <int> :: iterator it,itD;
//     list <int> arr[1000000];
    
//     int move,top;
//     string strMove;
//     stack<int> s;
//     for(int i=0;i<n;i++) {
//         cell.push_back(i);
//         answer +='O';
//     }
//     if(k<n/2){
//         it = cell.begin();
//         for(int i=0;i<k;i++) {
//             it++;
//         }    
//     }
//     else{
//         it = cell.end();
//         for(int i=n;i>k;i--) it--;
//     }
    

//     for(auto cm : cmd){
//         if(cm[0]=='U'){
//             strMove = cm.substr(2,cm.length()-2);
//             move = stoi(strMove);
//             for(int i=0;i<move;i++) it--;
//         }
//         else if(cm[0]=='D'){
//             strMove = cm.substr(2,cm.length()-2);
//             move = stoi(strMove);
//             for(int i=0;i<move;i++) it++;
//         }
//         else if(cm[0]=='C'){
//             s.push(*it);
//             if(*it==cell.back()){
//                 it--;
//                 cell.pop_back();
//             }
//             else{
//                 it = cell.erase(it);
//             }
//         }
//         else{ //Z인 경우
//             top = s.top();
//             s.pop();
//             itD = it;
//             itD++;
//             if(top > cell.back()){
//                 cell.push_back(top);
//             }
//             else if(top < cell.front()){
//                 cell.push_front(top);
//             }
//             else if(top> *it && top < *itD){
//                 itD = it;
//                 itD++;
//                 cell.insert(itD,top);
//             }
//             else if(top>*it){
//                 if(cell.back()-top < top -(*it)){ //cell.end시작이 빠르다
//                     itD=cell.end();
//                     itD--;
//                     while(itD!=cell.begin() && *itD > top) itD--;
//                     itD++;
//                     cell.insert(itD,top);
//                 }
//                 else{
//                     itD = it;
//                     while(itD!=cell.end() && *itD < top) itD++;
//                     cell.insert(itD,top);
//                 }
//             }
//             else{
//                 if((*it)-top < top){
//                     itD = it;
//                     while(itD!=cell.begin() && *itD > top) itD--;
//                     itD++;
//                     cell.insert(itD,top);
//                 }
//                 else{ //begin t시작이 빠르다
//                     itD = cell.begin();
//                     itD++;
//                     while(itD!=cell.end() && *itD < top) itD++;
//                     cell.insert(itD,top);
//                 }
                
//             }
            
//         }
//     }
    
//     while(!s.empty()){
//         answer[s.top()]= 'X';
//         s.pop();
//     }
//     return answer;
// }



#include <string>
#include <vector>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    list <int> cell;
    list <int> :: iterator it,itD;

    int move,top;
    string strMove;
    stack<int> s;
    for(int i=0;i<n;i++) {
        cell.push_back(i);
        answer +='O';
    }

    if(k<n/2){
        it = cell.begin();
        for(int i=0;i<k;i++) {
            it++;
        }    
    }
    else{
        it = cell.end();
        for(int i=n;i>k;i--) it--;
    }


    for(auto cm : cmd){
        if(cm[0]=='U'){
            strMove = cm.substr(2,cm.length()-2);
            move = stoi(strMove);
            for(int i=0;i<move;i++) it--;
        }
        else if(cm[0]=='D'){
            strMove = cm.substr(2,cm.length()-2);
            move = stoi(strMove);
            for(int i=0;i<move;i++) it++;
        }
        else if(cm[0]=='C'){
            s.push(*it);
            if(*it==cell.back()){
                it--;
                cell.pop_back();
            }
            else{
                it = cell.erase(it);
            }
        }
        else{ //Z인 경우
            top = s.top();
            s.pop();
            itD = it;
            itD++;
            if(top > cell.back()){
                cell.push_back(top);
            }
            else if(top < cell.front()){
                cell.push_front(top);
            }
            else if(top> *it && top < *itD){
                itD = it;
                itD++;
                cell.insert(itD,top);
            }
            else if(top>*it){
                if(cell.back()-top < top -(*it)){ //cell.end시작이 빠르다
                    itD=cell.end();
                    itD--;
                    while(itD!=cell.begin() && *itD > top) itD--;
                    itD++;
                    cell.insert(itD,top);
                }
                else{
                    itD = it;
                    while(itD!=cell.end() && *itD < top) itD++;
                    cell.insert(itD,top);
                }
            }
            else{
                if((*it)-top < top){
                    itD = it;
                    while(itD!=cell.begin() && *itD > top) itD--;
                    itD++;
                    cell.insert(itD,top);
                }
                else{ //begin t시작이 빠르다
                    itD = cell.begin();
                    itD++;
                    while(itD!=cell.end() && *itD < top) itD++;
                    cell.insert(itD,top);
                }

            }

        }
    }

    while(!s.empty()){
        answer[s.top()]= 'X';
        s.pop();
    }
    return answer;
}