import math as m
sample = input()
A,B = sample.split(":")
A = int(A)
B = int(B)
C = m.gcd(A,B)

print("%d:%d"%(A//C,B//C))
