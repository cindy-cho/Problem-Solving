class Solution {
    public int solution(int[] gift_cards, int[] wants) {
        int answer = 0;
        int[] totalGift = new int[100000];
        for(int i=0;i<gift_cards.length;i++){
            totalGift[gift_cards[i]-1]++;
            totalGift[wants[i]-1]--;
        }
        for(int i=0;i<totalGift.length;i++){
            if(totalGift[i]<0) answer += totalGift[i];
        }
        answer= answer*(-1);
        return answer;
    }
}