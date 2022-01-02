import math as m

def sameLine (xA, yA, xB, yB, xC, yC):
    if xA==xB and yA==yB or xA==xC and yA==yC or xB==xC and yB==yC :
        return -1
    if xA-xB==0 and xA==xC:
        return -1
    if xA-xB==0:
        return 0


    if yC*(xA-xB)*(xA-xB) == (yA-yB)*xC*(xA-xB) + (yA*(xA-xB) - ((yA-yB)*  xA))*(xA-xB):
        return -1

    return 0

def findPoint (xA, yA, xB, yB, xC, yC):
    x1 = (xA+xB) - xC
    y1 = (yA+yB) - yC
    D1 = m.sqrt((xC-xA)*(xC-xA)+(yC-yA)*(yC-yA))+m.sqrt((x1-xA)*(x1-xA)+(y1-yA)*(y1-yA))
    return D1*2

xA, yA, xB, yB, xC, yC = input().split()

xA = int(xA)
yA = int(yA)
xB = int(xB)
yB = int(yB)
xC = int(xC)
yC = int(yC)

if sameLine(xA,yA,xB,yB,xC,yC) == -1 :
    print(-1)

else :
    D1 = findPoint(xA,yA,xB,yB,xC,yC)
    D2 = findPoint(xA,yA,xC,yC,xB,yB)
    D3 = findPoint(xB,yB,xC,yC,xA,yA)
    D = []
    if D1 != 0 :
        D.append(D1)
    if D2 != 0 :
        D.append(D2)
    if D3 != 0 :
        D.append(D3)
    
    
    dMin = min(D)
    dMax = max(D)

    print(dMax-dMin)

