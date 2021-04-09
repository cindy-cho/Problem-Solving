import java.util.PriorityQueue;
import java.util.*;

class Pair implements Comparable<Pair>{
    int idx;
    int count;
    public Pair(int idx, int count){
        super();
        this.idx = idx;
        this.count = count;
    }
    
    @Override
    public int compareTo(Pair target){
        if(this.count < target.count){
            return 1;
        }
        else return -1;
    }
}

class Solution {
    public int solution(int[][] needs, int r) {
        int answer = 0;
        int count;
        int[] part = new int[15];
        int[] product = new int[needs.length];
        int[] candidate = new int[15];
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        for(int i=0;i<needs.length;i++){
            count = 0;
            for(int j=0;j<needs[i].length;j++){
                if(needs[i][j]==1){
                    count ++;
                }
            }
            if(count<=r){ //만들수 있는 제품이면
                for(int j=0;j<needs[i].length;j++){
                    if(needs[i][j]==1) part[j]++; // 가장 많이 쓰이는 부품을 체크
                }
            }
            else product[i]=-1;
        }
        
        for(int i=0;i<15;i++){
            if(part[i]>0){
                Pair temp = new Pair(i,part[i]);
                pq.offer(temp);
            }
        }
        
        for(int i=0;i<r;i++){
            if(pq.isEmpty()) break;
            Pair temp = pq.poll();
            candidate[temp.idx]=1;
        }
    
        int flag;
        for(int i=0;i<needs.length;i++){
            if(product[i]!=-1){
                flag = 1;
                for(int j=0;j<needs[i].length;j++){
                    if(needs[i][j]==1 && candidate[j]!=1){
                        flag = -1;
                        break;
                    }
                }
                if(flag==1) answer ++;
            }
        }   
        return answer;
    }
}