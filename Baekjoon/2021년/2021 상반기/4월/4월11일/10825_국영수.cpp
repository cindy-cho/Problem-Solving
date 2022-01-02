#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
    string name;
    int korean;
    int english;
    int math;
}Student;

bool cmp(Student a, Student b){
    if(a.korean==b.korean){
        if(a.english==b.english){
            if(a.math==b.math){
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.english < b.english;
    }
    return a.korean > b.korean;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    
    cin >> N;
    cin.ignore();
    vector<Student> a(N);
    int flag=0;
    int lastSpot;
    string input;

    for(int i=0;i<N;i++){
        flag = 0;
        getline(cin,input);
        for(int j=0;j<input.length();j++){
            if(input[j]==' '){
                if(flag==0){
                    a[i].name = input.substr(0,j);
                    lastSpot=j;
                    flag=1;
                }
                else if(flag==1){
                    a[i].korean = stoi(input.substr(lastSpot,j-lastSpot));
                    lastSpot=j;
                    flag=2;
                }
                else if(flag==2){
                    a[i].english = stoi(input.substr(lastSpot,j-lastSpot));
                    lastSpot=j;
                    a[i].math = stoi(input.substr(lastSpot,input.length()-lastSpot));
                }
            }
        }
        // cout << a[i].name << "," << a[i].korean << "," << a[i].english << "," << a[i].math << endl;
    }

    sort(a.begin(),a.end(),cmp);

    for(auto aa : a){
        cout << aa.name << "\n";
    }
    return 0;
}