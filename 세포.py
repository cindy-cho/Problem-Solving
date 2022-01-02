import sys
s = int(input(''))
energy = 0
count = 1
while(s>0):
    energy += count
    s= s//2
    count *= 2

print(energy)