def isCroatia(newStr):
    alphaDic = ['c=','c-','dz=','d-','lj','nj','s=','z=']
    for alpha in alphaDic :
        aLen = len(alpha)
        if newStr[0:aLen] == alpha :
            return newStr[aLen:]
    
    return newStr[1:]

    
croatiaStr = input()
ans = 0
while(len(croatiaStr)>0):
    croatiaStr = isCroatia(croatiaStr)
    ans += 1

print(ans)
