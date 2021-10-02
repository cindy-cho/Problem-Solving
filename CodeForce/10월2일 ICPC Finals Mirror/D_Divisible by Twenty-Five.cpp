#include<iostream>
#include<string>
#include<vector>
#define endl '\n'
typedef long long ll;

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    
    cin >> s;
    if(s=="0" || s=="X" || s=="_"){
        cout << "1\n";
        return 0;
    }
    int l = s.length();
    int answer = 0;
    int start=1,end=1;
    
    for(int i=1;i<l;i++) start*=10;
    int mul=start;
    end = start*10-1;
    vector<int> digit(l);
    for(int i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9') digit[i] = s[i]-'0';
        else if(s[i]=='X') digit[i] = -1;
        else if(s[i]=='_') digit[i] = -2;
    }
    bool flag;
    bool isX;
    int X;
    // for(int i=0;i<l;i++) cout << digit[i] << " " ;
    // cout << endl;

    while(start%25!=0) start++;
    // cout << "start : " << start << " , end : " << end << endl;
    // cout << "length : " << l << endl;
    int tmp;
    for(int i=start;i<=end;i+=25){
        tmp = i;
        // cout << i << endl;
        isX = false;
        if(digit[0]>=0 && digit[0]<=9 &&tmp/mul> digit[0]) break;
        if(tmp/mul==digit[0] || digit[0]==-1 || digit[0]==-2) {
            flag = true;
            if(digit[0]==-1){
                isX=true;
                X = tmp/mul;
            }
        }
        else continue;
        for(int j=l-1;j>=1;j--){
            if(digit[j]==-2) {
                tmp /= 10;
                continue;
            }
            if(digit[j]>=0 && digit[j]<=9 && digit[j] == tmp%10) {
                tmp /= 10;
                continue;
            }
            if(digit[j]==-1){
                if(isX==true && X == tmp%10) {
                    tmp/=10;
                    continue;
                }
                if(isX==false){
                    isX=true;
                    X = tmp%10;
                    tmp /=10;
                    continue;
                }
            }
            flag = false;
            break;
        }
        if(flag==true) answer ++;
    }
    cout << answer << endl;
    return 0;
}

// #include<iostream>
// #include<string>
// #include<math.h>
// #define endl '\n'
// typedef long long ll;

// using namespace std;

// ll testString(string A,int X){
//     int len = A.length();
//     if(len==2) return 1;
//     int chance=0;
//     int answer=0;
//     int isX=0;
//     for(int i=0;i<len-2;i++) {
//         if(A[i]=='_') chance ++;
//         else if(A[i]=='X') isX++;
//     }
//     if(A[0]=='X' && X==0) return 0; // no leading zero
//     if(A[0]=='X'){
//         if(chance!=0) answer = pow(10,chance);
//         if(X==-1 && isX!=0) return answer * 9;
//         else return answer;
//     }
//     if(A[0]=='_'){
//         if(chance == 1){
//             if(X==-1 && isX!=0) return 90;
//             else return 9;
//         }
//         answer = pow(10,chance-1);
//         answer *= 9;
//         if(X==-1 && isX!=0) return answer * 10;
//         else return answer;
//     }
//     if(chance !=0){
//         answer = pow(10, chance);
//         if(X==-1 && isX!=0) return answer * 10;
//         else return answer;
//     }
//     return 0;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     string s;
//     ll answer=0;
//     int X;
//     string demo[4] = { "00", "25", "50", "75" };
//     string two;
//     int type;
//     cin >> s;
//     int sLen = s.length();
//     if(sLen==1){
//         if(s=="0" || s=="X" || s=="_") cout << "1\n";
//         else cout << "0\n";
//         return 0;
//     }
//     // cout << "input S : " << s << endl;
//     // cout << " s lenght : " << sLen << endl;
//     // cout << s[sLen-2] << " , " << s[sLen-1] << endl;
//     two = s[sLen-2];
//     two  = two + s[sLen-1];
//     // cout << "last two is : " << two << endl;
//     if(s=="XX") {
//         cout << "0\n";
//         return 0;
//     }

//     for(int i=0;i<4;i++){
//         // cout << "now demo is : " << demo[i] << endl;
//         X = -1;
//         if(two[0] == demo[i][0] || two[0] == 'X' || two[0] == '_'){
//             if(two[0]=='X') X = demo[i][0]-'0';
//             if(two[1] == demo[i][1] || two[1] == '_' || two[1]=='X'){
//                 // cout << "go function : " << demo[i] << endl;
//                 if(two[0]=='X' && two[1]=='X' && i!=0) continue;
//                 if(two[1]=='X') X = demo[i][1]-'0';
//                 answer +=testString(s, X);
//             }
//         }
//     }

//     cout << answer << endl;
//     return 0;
// }