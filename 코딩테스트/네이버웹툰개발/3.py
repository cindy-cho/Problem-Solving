def solution(letters, k):
    answer = []
    aIdx = -1
    for i in range(len(letters)):
        if aIdx == -1:
            answer.append(letters[i])
            aIdx+=1
        else:
            if letters[i] > answer[aIdx]:
                answer[aIdx] = letters[i]
            else :
                if aIdx == (k-1):
                    break     
                answer.append(letters[i])
                aIdx+=1
        if(len(letters)-i)+aIdx == k:
            i+=1
            for j in range(k-aIdx-1):
                answer.append(letters[i+j])
            break
    
    strAnswer = "".join(answer)
        
    return strAnswer