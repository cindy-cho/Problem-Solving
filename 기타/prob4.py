# 중간고사 10%, 기말 5%, 과제 30%, 퀴즈 25%, 출석 30%

midtermScore = float(input("중간고사 점수:"))
finalScore = float(input("기말고사 점수:"))
homeworkScore = float(input("과제 점수:"))
quizScore = float(input("퀴즈 점수:"))/130*25
attendanceScore = float(input("출석 점수:"))/15*30

totalScore= midtermScore+finalScore+homeworkScore+quizScore+attendanceScore

if totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 A+ 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 A 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 B+ 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 B 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 C+ 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 C 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 D+ 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 D 입니다." %(totalScore))

elif totalScore <= 100 and totalScore > 95 :
    print("프통문 최종 점수는 %.2f 이고 예상 학점은 F 입니다." %(totalScore))

