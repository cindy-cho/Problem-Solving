def solution(word):
    wordDict = {'N': 1, 'A':0, 'E':1, 'I' :2 , 'O' :3 , 'U' : 4}
    arr = [781,156,31,6,1]
    answer = 0    
    i=0
    for wo in word:
        answer += 1 + wordDict[wo]*arr[i]
        i+=1

    return answer