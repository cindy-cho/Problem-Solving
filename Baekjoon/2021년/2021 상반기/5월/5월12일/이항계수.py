A, B = input().split()
A = int(A)
B = int(B)

if A-B < B :
    B = A-B

SUM = 1
SUM2 = 1

for i in range(B+1,A) :
    SUM *= i
    SUM2 *= (i-B)

SUM = (SUM / SUM2) %1000000007
print(int(SUM))

