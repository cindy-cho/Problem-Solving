numA = float(input("숫자를 입력하세요."))
operand = int(input("연산자를 선택하세요.(1.덧셈.2.뺄셈.3.곱셈.4.나눗셈)"))
numB = float(input("숫자를 입력하세요."))

if operand == 1:
    print("덧셈 결과 : %.1f" %(numA+numB))

elif operand == 2:
    print("뺄셈 결과 : %.1f" %(numA-numB))

elif operand == 3:
    print("곱셈 결과 : %.1f" %(numA*numB))

elif operand == 4:
    if numB == 0:
        print("나눗셈 결과 : 0으로 나눌 수 없습니다")
    else:
        print("나눗셈 결과 : %.1f" %(numA/numB))