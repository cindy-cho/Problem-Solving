import java.util.Stack;

class Solution {
    static int[][] map;
    static int[] copyPassenger;
    static int maxAns, maxIdx;
    public int[] solution(int n, int[] passenger, int[][] train) {
        int[] answer = new int [2];
        maxAns=0;
        maxIdx=0;
        int current;
        map = new int [n][n];
        copyPassenger = new int[passenger.length];
        for(int i=0;i<passenger.length;i++) copyPassenger[i]=passenger[i];
        boolean[] visit = new boolean[n];
        for(int i=0;i<train.length;i++){
            map[train[i][0]-1][train[i][1]-1]=1;
            map[train[i][1]-1][train[i][0]-1]=1;
        } //지도 초기화
        visit[0]=true;
        for(int i=0;i<n;i++){ //1번에서 출발하니까
            if(map[0][i]==1){ //1번에서 갈 수 있는 경우
                current = passenger[0];
                visit[i]=true;
                current += passenger[i];
                dfs(i,current,visit);
                visit[i]=false;
            }
        }
        answer[0] = maxIdx+1;
        answer[1] = maxAns;
        return answer;
    }
    
    private static void dfs(int i,int current,boolean[] visit){
        int len = map.length;
        int flag = -1;
        for(int j=0;j<len;j++){
            if(map[i][j]==1 && visit[j]==false){
                flag =1;
                visit[j]=true;
                current+=copyPassenger[j];
                dfs(j,current,visit);
                visit[j]=false;
                current-=copyPassenger[j];
            }
        }
        if(flag==-1){
            if(current>maxAns){
                maxAns = current;
                maxIdx = i;
                return;
            }
            else if(current==maxAns){
                if(maxIdx < i){
                    maxIdx = i;
                    return;
                }
            }
        }
    }
}