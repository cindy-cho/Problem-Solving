parkingHour = int(input("주차시간 입력:"))
print("주차시간: %d분"%(parkingHour))
if parkingHour <=30 :
    print("주차요금: 0원")
elif parkingHour >30 and parkingHour <=60 :
    print("주차요금: 5000원")
else:
    print("주차요금: %d원"%(5000+(parkingHour-60)//15*1000))