import requests, json, random

baseUrl = "https:// ~ /"
key = ""
start_header = {'Content-Type': 'application/json; charset=utr-8',
                    'X-Auth-Token' : '~~'}
headers = {'Content-Type': 'application/json; charset=utf-8', "Authrization":key} 

arr = [[0 for col in range(5)] for row in range(5)]
tucks = []
fulls = []
lows = []
empties = []

def getLocations():
    global fulls,lows,empties,arr
    fulls = []
    lows = []
    empties = []
    response = requests.get(baseUrl+"locations",headers = headers)
    for loc in response.json()["locatoins"]:
        arr[4-loc]["id"]%5][int(loc["id"]/5)] = loc["located_bikes_count"]
        if loc["located_bikes_count"] >=3 :
            fulls.append(loc["id"])
    return response

def getTrucks():
    response = requests.get(baseUrl+"trucks",headers=headers)
    return response

def simultae(commands):
    '''{
        "status" : "ready",
        "time" : 1,
        "failed_requests_count" : 5,
        "distance" : 1.2,
    }'''
    data = {"commands":commands}
    response = requests.put(baseUrl+"simulate",headers=headers,data=json.dumps(data))
    return response

def score():
    response = requests.get(baseUrl+"score",headers=headers)
    return response

def setting():
    commands= []
    commands.append({"truck_id":0,"command":[1,1]})
    return commands