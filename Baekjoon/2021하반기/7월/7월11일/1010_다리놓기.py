'''
nCr = nPr / r!
    = n* (n-1) * (n-2) ..... * (n-r+1) / r!
'''
T = int(input())
for i in range(T):
    N, M = input().split()
    
    N = int(N)
    M = int(M)
    answer = 1
    for j in range(M,M-N,-1):
        answer = answer*j
    for j in range(N,1,-1):
        answer = answer // j

    print(int(answer))

