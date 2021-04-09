#
# poly.py - polynomials
#

from math import sqrt

# Polynomial Equation Solver
#
# coefficients : list of coefficients. for example [2, 3, 4] for 2x^2 + 3x + 4
# return list of solutions. for example [-1, 1] for x^2 -1 = 0
def solve(coefficients) :
    ans=[]
    if(len(coefficients)>3): #원소의 개수가 3개가 넘을 때
        print("can't solve!,",coefficients)
    elif((coefficients[0]==0 and len(coefficients)==3) or len(coefficients)==2): 
        if(len(coefficients)==3):
            b = coefficients[1]
            c = coefficients[2]
        elif(len(coefficients)==2):
            b = coefficients[0]
            c = coefficients[1]
        if(b==0): # b==0인 경우
            if(c==0): #  c==0 일 때 부정
                print("Warning: indeterminate (0/0 form)")
            elif(c!=0): # c!=0 일 때 불능
                print("Warning: undefined (there is no possible solution")
        else : # b는 0이 아닐 경우 x = - c / b
            ans.append(-c/b)
            print(ans)
    elif(len(coefficients)==3):
         a = coefficients[0]
         b = coefficients[1]
         c = coefficients[2]
         calc = b*b - 4*a*c
         if(calc >0): #두 개의 실근
             ans.append((-b + sqrt(calc)) / (2*a))
             ans.append((-b - sqrt(calc)) / (2*a))
             print(ans)
         elif(calc == 0): # 하나의 중근
             ans.append(-b / (2*a))
             print(ans)
         elif(calc < 0): #두개의 허근
             calc *= -1
             ans1 = complex( -b/(2*a),sqrt(calc) / (2*a))
             ans2 = complex( -b/(2*a),-sqrt(calc) / (2*a))
             ans.append(ans1)
             ans.append(ans2)
             print(ans)
    pass