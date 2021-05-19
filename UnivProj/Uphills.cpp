def solution(new_id):
    answer = ''
    new_id = new_id.lower()
    for new in new_id:
        if new>='a' and new<='z' :
            answer += new;
        elif new=='-' or new=='_' or new=='.' :
            answer += new;
    
    check = '..'
    for i in range(len(new_id)):
        answer = answer.replace(check,".")
        check += '.'
    
    if answer[0]=='.' :
        answer = answer[1:]
    
    if answer[-1]=='.' :
        answer = answer[:-1]
        
    if len(answer) == 0:
        answer = 'a'
    
    if len(answer) >=16 :
        answer = answer [:15]
    
    if answer[-1]=='.':
        answer = answer[:-1]
        
    if len(answer)==1:
        answer = answer + answer + answer
    
    elif len(ansewr)==2:
        answer += answer[-1]
        
    return answer