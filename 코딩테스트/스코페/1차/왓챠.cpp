#include <iostream>
#include <vector>
#include <algorithm>

//열람한적 없는 콘텐츠 && 장르 선호도 높은 순  YYYYYYY
//열람했으나 끝까지 다 보지 못한 && 장르 선호도 높은 순  OOOOO
// 끝까지 열람 함 -> type : 2 
// O 열람 &  끝까지 다 보지 못함 -> status : 1
// W 열람 & 끝까지 다 봄  -> status : 0
// Y 열람 한 적 없음  -> status : 6
// 1 2 3 4 5
// A B C D E
typedef struct{
    int i;
    int j;
    int type; // ABCDE
    char name;
}watcha;

// bool cmp(watcha a, watcha b){
    
//         if(a.type==b.type){
//             if(a.i==b.i) return a.j < b.j;
//             return a.i < b.i;
//         }
//         return a.type > b.type ;
    
  
// }
void merge(int l, int r);
void mergesort(int l,int m, int r);


using namespace std;

//vector <watcha> answer(1000);

watcha answer[1000];
watcha tmp[1000];
void merge(int l, int r) {
   if (l < r) {
      int m = (l + r) / 2;

      merge(l, m);
      merge(m + 1, r);

      mergesort(l, m, r);
   }
}
void mergesort( int l, int m, int r) {
   int ll = l;  
   int rr = m + 1;
   int idx = 0;


   while (ll <= m && rr <= r)
      if (answer[ll].type >= answer[rr].type)
        tmp[idx++] = answer[ll++];
      else
        tmp[idx++] = answer[rr++];
   while (ll <= m)
      tmp[idx++] = answer[ll++];
   while (rr <= r)
      tmp[idx++] = answer[rr++];
   for (int i = l; i <= r; i++)
      answer[i] = tmp[i - l];
}

int main(void){
    vector <pair<double, int> > like(5);
    int order [5] = {0,};
    double score[5]={0,};
    //vector <watcha> answer;
    watcha tmp;
    int i,j,N,M,idx=0,currentStatus;
    int status;
    for(i=0;i<5;i++) {
        like[i].second = i;
        
        scanf("%lf",&like[i].first);
    }
    sort(like.begin(), like.end());
    for(i=4;i>=0;i--){
        order[like[i].second] = (i+1);
        score[like[i].second] =like[i].first;
    }

    
    cin >> N >> M;

    cin.ignore();
    vector <string> history(N), content(N);
    for(i=0;i<N;i++) getline(cin,history[i]);
    for(i=0;i<N;i++) getline(cin,content[i]);

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(history[i][j]=='W') continue;
            if(history[i][j]=='O') status = 1;
            else if(history[i][j]=='Y') status=6;
            if(content[i][j]=='A') {tmp.type = status*order[0];
            tmp.name='A';}
            else if(content[i][j]=='B') {tmp.type = status*order[1];
            tmp.name='B';}
            else if(content[i][j]=='C') {
                tmp.type = status*order[2];
                tmp.name='C';
                }
            else if(content[i][j]=='D') {
                tmp.type = status*order[3];
                tmp.name='D';
                }
            else {tmp.type = status*order[4];
            tmp.name='E';
            }
            tmp.i=i;
            tmp.j=j;
            answer[idx]=tmp;
            idx++;
        }
    }

    //sort(answer.begin(),answer.begin()+idx,cmp);
    //sort(answer.begin(),answer.end(),cmp);
     merge(0, idx - 1);

    for(i=0;i<idx;i++){
        if(answer[i].name=='A') printf("A %.1lf",score[0]);
        else if(answer[i].name=='B') printf("B %.1lf",score[1]);
        else if(answer[i].name=='C') printf("C %.1lf",score[2]);
        else if(answer[i].name=='D') printf("D %.1lf",score[3]);
        else if(answer[i].name=='E') printf("E %.1lf",score[4]);
        printf(" %d %d\n",answer[i].i, answer[i].j);
    }

    return 0;
}

