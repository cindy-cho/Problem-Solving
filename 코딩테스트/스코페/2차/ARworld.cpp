#include<iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int answer=200000000;
int worldIdx=0;
map < string , int > worldDic;
vector < vector < pair <string, int  > > > data;
void connectCity(int loc,int resource,vector<bool> vst,int cityCount){
    if(cityCount==worldIdx){
        if(answer > resource) answer = resource;
        return;
    }
    int i;
    for(i=0;i<data[loc].size();i++){
        vst[worldDic[data[loc][i].first]]=true;
        resource+= data[loc][i].second;    
    }

    
    
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,i, minSource=0;
    string city1,city2,resource;
    cin >> N;
    int cityCount=0;
    data.resize(N);

    cin.ignore();
    
    for(i=0;i<N;i++){
        cin >> city1 >> city2 >> resource ;
        if(worldDic.count(city1)){
            data[worldDic[city1]].push_back(make_pair(city2,resource));
        }
        else{
            worldDic[city1] = worldIdx++;
            data[worldDic[city1]].push_back(make_pair(city2,resource));
        }
        if(worldDic.count(city2)){
            data[worldDic[city2]].push_back(make_pair(city1,resource));
        }
        else{
            worldDic[city2] = worldIdx++;
            data[worldDic[city2]].push_back(make_pair(city1,resource));
        }
        
    }
    vector <bool>  vst(worldIdx,false);
    // dp에 무조건 연결이 1개인 도시들은 fix로 넣어놓기
    for(i=0;i<worldIdx;i++){
        if(data[i].size()==1){
            minSource += data[i][0].second;
            vst[i]=true;
            cityCount++;
        }
    }

    for(i=0;i<worldIdx;i++){
        if(data[i].size()>1){
            connectCity(i,minSource,vst,cityCount);
            break;
        }
    }

    return 0;

}
// int minResource = 1<<28;
// int worldIdx=0;
// vector <vector <pair <string, int > > > arWorld;
// map < string,  int >  worldDic;

// void findBestResource(vector<bool> vst,int currentCity, int resource, int vstCity){
//     if(minResource < resource) return;
//     if(vstCity==worldIdx){
//         if(minResource > resource) minResource = resource;
//         return ;
//     }    

//     // cout << "visitedCity : " << vstCity << ", currentCity : " << currentCity << ", resource : " << resource << endl;

//     vst[currentCity] = true;
//     int i,cityLen = arWorld[currentCity].size();
//     for(i=0;i<cityLen;i++){
//         //방문하지 않은 도시중
//         if(vst[worldDic[arWorld[currentCity][i].first]]==false){
//             vst[worldDic[arWorld[currentCity][i].first]]=true;
//             resource+=arWorld[currentCity][i].second;
//             findBestResource(vst,worldDic[arWorld[currentCity][i].first],resource,vstCity+1);
//             resource-=arWorld[currentCity][i].second;
//             vst[worldDic[arWorld[currentCity][i].first]]=false;
//         }
//     }
//     return ;
// }

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int N,i,j;

//     string city1, city2;
//     int resource;
//     cin >> N;
//     cin.ignore();
//     pair <string, string> tmp;
//     arWorld.resize(N+1);
    
   
//     for(i=0;i<N;i++){
//         cin >> city1 >> city2 >> resource;
//         if(worldDic.count(city1)){
//             arWorld[worldDic[city1]].push_back(make_pair(city2,resource));
//         }
//         else{
//             worldDic[city1] = worldIdx;
//             // arWorld[worldIdx].push_back(make_pair(city1,0));
//             arWorld[worldDic[city1]].push_back(make_pair(city2,resource));
//             worldIdx++;
//         }
//         if(worldDic.count(city2)){
//             arWorld[worldDic[city2]].push_back(make_pair(city1,resource));
//         }
//         else{
//             worldDic[city2] = worldIdx;
//             // arWorld[worldIdx].push_back(make_pair(city2,0));
//             arWorld[worldDic[city2]].push_back(make_pair(city1,resource));
//             worldIdx++;
//         }       
//     }

//     vector<bool> vst(worldIdx,false);
    
//     for(i=0;i<worldIdx;i++){
//         findBestResource(vst,i,0,1);
//     }

//     cout << minResource << "\n";
//     return 0;
// }



/*
a b
a c
a d
a e
a f*/