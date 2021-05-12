a = 0
b = 1
n = int(input())

if n==0:
    print(a)
elif n==1:
    print(b)
else:
    for i in range(n-1):
        c = a+b
        a = b
        b = c

    print(c)
