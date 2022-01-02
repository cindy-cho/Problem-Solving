import math as m
A, B = input().split()

A = float(A)
B = float(B)

M = (B-A)/400

print(1/(1+m.pow(10,M)))

