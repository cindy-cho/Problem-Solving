from typing import DefaultDict
from operator import itemgetter
import requests
import random
import json

from requests.api import request
from requests.models import RequestEncodingMixin

#현재 대기열에서 매칭을 대기 중인 유저들의 정보를 반환한다.
#"waiting_line": [
#{ "id": 1, "from": 3 },
def waitingLine(url,headers,path,userLevel):
    waitingList=DefaultDict(list)
    matchList=[]
    req = requests.get('/'.join([url,path]),headers=headers)
    # print("-------------------------------------")
    # print("waitingLine API RESULT : ", req.status_code)
    j = req.json()
    for id, waitStart in [(i['id'],i['from']) for i in j["waiting_line"]]:
        waitingList[waitStart].append(id)
    # print(">>>>> WAITING LIST")
    # print(waitingList)
    #waitingList 시간 따라 정렬
    sWaitingList = sorted(waitingList.items())
    # print(">>>>> SORTED WAITING LIST")
    # print(sWaitingList)
    left = []
    waitings = []
    for time in sWaitingList :
        for user in time[1]:
            waitings.append([userLevel[user-1],time[0],user])
        waitings.sort(key=itemgetter(0,2))
        # print(">>>>> WAITINGS")
        # print(waitings)
        while (len(waitings) > 1):
            if(waitings[1][0]-waitings[0][0] < 20000):
                matchList.append([waitings[1][2],waitings[0][2]])
                waitings.pop(0)
                waitings.pop(0)
            else:
                left.append(waitings[0])
                waitings.pop(0)
        
        while(len(waitings)>0):
            left.append(waitings[0])
            waitings.pop(0)
        
        # print(">>>>> WAITINGS")
        # print(waitings)
        # print(">>>>> LEFT")
        # print(left)
        # print(">>>>> MATCH")
        # print(matchList)

        while(len(left)>0):
            waitings.append(left[0])
            left.pop(0)

    match(url,headers,"match",matchList)

#이번 턴에 게임이 끝난 유저들의 게임 결과를 반환한다.
#"game_result" : { "win": 10, "lose": 2, "taken": 7 },
# 걸리는 시간 : 40분 - (두 유저 간 고유 실력 차 / 99000 * 35) + e 
# e의 값은 -5 이상 5 이하인 정수 중에서 무작위로 선택된 값이다.
# 유저 A가 이길 확률 : (유저 A의 고유 실력) / (유저 A의 고유 실력 + 유저 B의 고유 실력)
def gameResult(url,headers,path,userLevel):
    req = requests.get('/'.join([url,path]),headers = headers)
    # print("-------------------------------------")
    # print("gameResult API RESULT : ", req.status_code)
    j = req.json()
    # print(j)
    for win, lose, taken in [(i['win'],i['lose'],i['taken']) for i in j["game_result"]]:
        win -=1 ; lose -=1
        e = random.randint(-5,5)
        levelDiff = (taken - e - 40)/35*99000 #두 유저 간 고유 실력 차
        midLevel = (userLevel[win]+userLevel[lose])/2
        
        userLevel[win] = (userLevel[win] + midLevel + levelDiff/2) / 2
        userLevel[lose] = (userLevel[lose] + midLevel - levelDiff/2) / 2
        
        if(userLevel[win] > 100000) :
            userLevel[win] = 100000

        if(userLevel[lose] < 0) :
            userLevel[lose] = 0

        # print(win+1, int(9999*userLevel[win]/100000), lose+1, int(9999*userLevel[lose]/100000))
        changeGrade(url,headers,"change_grade",{ 'commands' : [{"id": win+1, "grade": int(9999*userLevel[win]/100000) }, {"id":lose+1, "grade":int(9999*userLevel[lose]/100000)}]})

#모든 유저들의 현재 등급을 반환한다.
#"user_info": { "id": 1, "grade": 2100 }
def userInfo(url,headers,path):
    req = requests.get('/'.join([url,path]),headers=headers)
    print("-------------------------------------")
    print("userInfo API RESULT : ", req.status_code)
    j = req.json()
    print(j)
    

#대기열에서 매칭 대기 중인 두 유저를 매칭하여 게임을 시작하도록 한다.
#"status": "ready",
#"time": 312
#param = {'pairs': [[1,2],[9,7]]}
def match(url,headers,path,param):
    req = requests.put('/'.join([url,path]),headers=headers,data=json.dumps({'pairs': param}))
    # print("match API RESULT : ", req.status_code)
    j = req.json()
    print(j)

#여러 유저의 등급을 수정할 수 있다. 0~9999
#param = { 'commands' : [{"id": 1, "grade": 1900 },{"id":2,"grade":2340}] }
def changeGrade(url,headers,path,param):
    req = requests.put('/'.join([url,path]),headers=headers,data=json.dumps(param))
    print("changeGrade API RESULT : ", req.status_code)
    # j = req.json()
    # print(j)


#시뮬레이션이 끝난 뒤 정확성 점수와 효율성 점수, 총점을 반환한다.
def score(url,headers,path):
    req = requests.get('/'.join([url,path]),headers=headers)
    print("score API RESULT : ", req.status_code)
    j = req.json()
    if(req.status_code == 200):
        print("status : ", j['status'])
        print("efficiency_score : ", j['efficiency_score'])
        print("accuracy_score1 : ", j['accuracy_score1'])
        print("accuracy_score2 : ", j['accuracy_score2'])
        print("score : ", j['score'])

def matchingStart(qid):
    url = 'https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod'
    path = 'start'
    x_auth_token ='71ab7a6f5a17efc0d6d8ef655efec598'
    param = {'problem':qid}
    headers = {'X-Auth-Token':x_auth_token, 'Content-Type': 'application/json'}

    req = requests.post('/'.join([url,path]),headers = headers, data=json.dumps(param))
    print("START RESULT : ", req.status_code)
    j = req.json()
    auth_key = j['auth_key']
    headers = {'Authorization': auth_key, 'Content-Type': 'application/json'}


    if(qid == 1):
        user = 30
    elif(qid == 2):
        user = 900

    userLevel = [40000 for i in range(user)]
    # print("-------------------------------------")
    # print(userLevel)
    # print("-------------------------------------")
    # #call WaitingLine API
    for i in range(555):
        # print("-------------------------------------")
        print("stage : ",i)
        gameResult(url,headers,"game_result",userLevel)
        waitingLine(url,headers,"waiting_line",userLevel)
        # print("-------------------------------------")
        

    for i in range(556,596):
        print("stage : ",i)
        gameResult(url,headers,"game_result",userLevel)
    
    userInfo(url,headers,"user_info")
    match(url,headers,"match",[])
    score(url,headers,"score")

# matchingStart(1)
matchingStart(2)