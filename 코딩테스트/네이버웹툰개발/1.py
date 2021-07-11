def solution(S, pattern):
    answer = 0
    patternDict = {}
    SDict = {}
    pLen = len(pattern)

    for pa in pattern:
        if patternDict.get(pa) == None:
            patternDict[pa] = 1
        else:
            patternDict[pa]+=1;
    
    
    for i in range(len(S)):
        if SDict.get(S[i]) == None:
            SDict[S[i]] = 1
        else:
            SDict[S[i]]+=1;
        
        if i >= pLen-1:
            flag = True
            for key in patternDict:
                if SDict.get(key) == None or patternDict[key] != SDict[key] :
                    flag = False
            
            if flag == True:
                answer +=1
            
            SDict[S[i-pLen+1]]-=1


    return answer