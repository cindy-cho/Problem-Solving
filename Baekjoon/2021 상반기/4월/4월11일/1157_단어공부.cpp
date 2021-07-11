//신경써야 할 부분
// 문자열로 입력받을 때 배열의 길이는 반드시 100만1 이상이어야 합니다. 널 문자를 저장할 공간이 별도로 필요하기 때문입니다. fgets로 받을 시 개행 문자까지 저장되므로 길이가 100만2 이상이어야 합니다.
// 최댓값을 갱신해가는 과정에서 현재까지의 최댓값과 같은 수가 또 나왔다고 곧바로 물음표를 출력하고 종료하면 안 됩니다. 전체에서 가장 많이 나온 글자가 몇 번 나왔는지를 끝까지 구해보기 전까지는 섣부른 판단은 금물입니다.

#include<iostream>
#include<string>
using namespace std;

string upperToLower(string input){
    for(int i=0;i<input.length();i++){
        if(input[i]>='A' and input[i]<='Z'){
            input[i] = input[i] - ('A'-'a');
        }
    }
    return input;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int charCount[26];
    int max = 0, idx = 0, cnt=0;
    for(int i=0;i<26;i++) charCount[i] = 0;
    
    string input;
    cin >> input;

    if(input.length()==0){
        cout << "?\n";
        return 0;
    }

    input = upperToLower(input);

    for(auto i:input){
        charCount[i-'a']++;
    }
    for(int i=0;i<26;i++){
        if(charCount[i]==max){
            cnt++;
        }
        if(charCount[i]>max){
            cnt=1;
            max = charCount[i];
            idx = i;
        }
    }

    if(cnt>1) cout << "?\n";
    else cout << char('A'+idx) << "\n";

    return 0;
}